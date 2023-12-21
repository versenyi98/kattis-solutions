from functools import lru_cache

@lru_cache(maxsize=None)
def dp(idx, rem):
    if idx == W + 1:
        return 0

    result = 0
    for price, seat in zip(prices[idx], seats[idx]):
        if seat <= rem:
            result = max(result, seat * price + dp(idx + 1, rem - seat))
        else:
            result = max(result, rem * price)
    return result

N, W = map(int, input().split())

prices = []
seats = []

for week in range(W + 1):
    line = list(map(int, input().split()))
    prices.append(line[1:1 + line[0]])
    seats.append(line[1 + line[0]:])

total_profit = dp(0, N)
print(total_profit)
for price, seat in zip(prices[0], seats[0]):
    profit = min(seat, N) * price
    if dp(1, N - min(seat, N)) + profit == total_profit:
        print(price)
        break