import bisect
import sys

read = sys.stdin.readline

n = int(read())
hx, hy, wx, wy = map(int, read().split())

lines = sys.stdin.read().strip("\n").split("\n")
errands = list(tuple(map(int, line.split())) for line in lines)
if wy < hy:
    errands = [(x, -y) for x, y in errands]
    wy, hy = -wy, -hy
if wx < hx:
    errands = [(-x, y) for x, y in errands]
    wx, hx = -wx, -hx

errands = list(filter(lambda x: min(hx, wx) <= x[0] <= max(hx, wx) and min(wy, hy) <= x[1] <= max(wy, hy), errands))
errands = sorted(errands)

lnds = []
for errand in errands:
    pos = bisect.bisect_right(lnds, errand[1])
    if pos == len(lnds):
        lnds.append(errand[1])
    else:
        lnds[pos] = errand[1]
print(len(lnds))