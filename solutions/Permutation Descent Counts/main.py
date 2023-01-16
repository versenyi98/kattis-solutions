from functools import lru_cache


@lru_cache(maxsize=None)
def dp(n, k):
    if k == 0 or k == n - 1:
        return 1
    return (k + 1) * dp(n - 1, k) + (n - k) * dp(n - 1, k - 1)
    
test_cases = int(input())

for _ in range(test_cases):
    idx, n, k = map(int, input().split())
    print(f"{idx} {dp(n, k) % 1001113}")