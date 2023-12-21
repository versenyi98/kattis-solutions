import sys


def longest_increasing_subsequence(i):
    if memo[i] != -1:
        return memo[i]
    memo[i] = 1
    for j in range(i):
        if ord(line[j]) < ord(line[i]):
            memo[i] = max(memo[i], longest_increasing_subsequence(j) + 1)
    return memo[i]


line = sys.stdin.read().strip("\n")
memo = [-1] * len(line)
for idx in range(len(line)):
    longest_increasing_subsequence(idx)
print(26 - max(memo))
