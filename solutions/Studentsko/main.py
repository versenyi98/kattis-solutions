import bisect
import sys

N, K = map(int, sys.stdin.readline().split())
numbers = list(map(int, sys.stdin.readline().split()))

should_be_in = {value: idx // K for idx, value in enumerate(sorted(numbers))}
numbers = [should_be_in[value] for value in numbers]

lnds = []
for number in numbers:
    pos = bisect.bisect_right(lnds, number)
    if pos == len(lnds):
        lnds.append(number)
    else:
        lnds[pos] = number
print(len(numbers) - len(lnds))