import sys

line = ""
case = 0

for line in sys.stdin:
    n, m = map(int, line.split())
    t = []
    seen = []

    for i in range(n):
        t.append(sys.stdin.readline())
        seen.append([False] * m)

    counter = 0
    queue = []

    for i in range(n):
        for j in range(m):
            if t[i][j] == '-' and not seen[i][j]:
                counter += 1
                queue.append([i, j])
                while len(queue):
                    x, y = queue.pop()
                    if x < 0 or x == n or y < 0 or y == m or seen[x][y] == True or t[x][y] != '-':
                        continue
                    seen[x][y] = True
                    queue.append([x + 1, y])
                    queue.append([x - 1, y])
                    queue.append([x, y - 1])
                    queue.append([x, y + 1])
    case += 1
    print("Case {}: {}".format(case, counter))