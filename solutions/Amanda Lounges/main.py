import sys


def main():
    lines = sys.stdin.read().strip("\n").split("\n")

    number_of_nodes, number_of_edges = map(int, lines[0].split())
    edges = [list(map(int, edge_info.split())) for edge_info in lines[1:]]

    lounge = set()
    no_lounge = set()

    exactly_one = {n + 1: [] for n in range(number_of_nodes)}

    for x, y, l in edges:
        if l == 0:
            no_lounge.add(x)
            no_lounge.add(y)
        elif l == 2:
            lounge.add(x)
            lounge.add(y)
        else:
            exactly_one[x].append(y)
            exactly_one[y].append(x)

    if set.intersection(lounge, no_lounge):
        print("impossible")
        return

    changed = True
    while changed:
        lounge_len = len(lounge)
        no_lounge_len = len(no_lounge)

        for node, others in exactly_one.items():
            if node in lounge:
                no_lounge.update(others)
            elif node in no_lounge:
                lounge.update(others)
        changed = len(lounge) != lounge_len or len(no_lounge) != no_lounge_len

    if set.intersection(lounge, no_lounge):
        print("impossible")
        return

    remaining = {}
    for node, others in exactly_one.items():
        if not others:
            continue
        if node not in lounge and node not in no_lounge:
            remaining[node] = others

    if not remaining:
        print(len(lounge))
        return

    visited = set()
    res = len(lounge)
    for node, values in remaining.items():
        if (node, 0) in visited or (node, 1) in visited:
            continue
        group0, group1 = set(), set()
        visited.add((node, 0))
        queue = [(node, 0)]

        while queue:
            head, group = queue.pop(0)
            if group == 0:
                group0.add(head)
            else:
                group1.add(head)

            for other in exactly_one[head]:
                next_node = (other, 1 - group)
                if next_node not in visited:
                    visited.add(next_node)
                    queue.append(next_node)
        if set.intersection(group0, group1):
            print("impossible")
            return
        res += min(len(group1), len(group0))

    print(res)


if __name__ == "__main__":
    main()
