import bisect
import sys

while True:
    n = sys.stdin.readline().strip("\n")
    numbers = sys.stdin.readline().strip("\n").split()

    if not n and not numbers:
        break

    n = int(n)
    numbers = list(map(int, numbers))

    lis = []
    lis_indexes = []

    lis_previous = [-1] * n
    last_index = -1

    for idx, number in enumerate(numbers):
        pos = bisect.bisect_left(lis, number)

        if pos:
            lis_previous[idx] = lis_indexes[pos - 1]

        if pos == len(lis):
            lis.append(number)
            lis_indexes.append(idx)
            last_index = idx
        else:
            lis[pos] = number
            lis_indexes[pos] = idx

    print(len(lis))
    indexes = []
    while last_index != -1:
        indexes.append(last_index)
        last_index = lis_previous[last_index]
    print(*indexes[::-1])