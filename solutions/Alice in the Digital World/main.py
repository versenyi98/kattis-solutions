import sys

test_cases = int(sys.stdin.readline())

while test_cases:
    n, m = map(int, sys.stdin.readline().split())
    numbers = list(map(int, sys.stdin.readline().split()))

    current_best = 0
    running_sum = 0
    minimum_seen = False
    minimum_idx = 0

    idx = 0

    while idx < n:
        number = numbers[idx]

        if number < m:
            running_sum = 0
            minimum_seen = False
            idx += 1
            continue

        if number == m:
            if minimum_seen:
                minimum_seen = False
                idx = minimum_idx + 1
                running_sum = 0
                continue
            else:
                minimum_seen = True
                minimum_idx = idx

        running_sum = running_sum + number
        if minimum_seen:
            current_best = max(running_sum, current_best)
        idx += 1
    test_cases -= 1
    print(current_best)
