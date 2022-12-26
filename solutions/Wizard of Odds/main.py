import sys
input = sys.stdin.read().split()

N, K = map(int, input)

if pow(2, K) >= N:
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")