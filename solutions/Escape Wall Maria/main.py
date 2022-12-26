import sys

directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]

advance = {
    'U': (1, 0),
    'D': (-1, 0),
    'L': (0, 1),
    'R': (0, -1)
}

line = input()

splitted = line.split()

t, N, M = [int(x) for x in splitted]

grid = []

start_pos = None

for i in range(N):
    next_line = input()
    grid.append(next_line)

    if next_line.find('S') != -1:
        start_pos =  (next_line.find('S'), i, 0) # x, y, time

pos_queue = [start_pos]

won = -1

# is it possible
possible = False
for i in range(N):
    possible |= (grid[i][0] != '1' or grid[i][M-1] != '1')
for i in range(M):
    possible |= (grid[0][i] != '1' or grid[N-1][i] != '1')

if possible == False:
    pos_queue = []

while len(pos_queue) > 0:
    x, y, time = pos_queue.pop(0)

    if grid[y][x] != '1':
        grid[y] = grid[y][:x] + '1' + grid[y][x+1:]

    if time > t:
        break
    elif x == 0 or y == 0 or x == M - 1 or y == N - 1:
        won = time
        break

    minimum_distance = min(min(x, M - 1 - x), min(y, N - 1 - y))
    if minimum_distance + time - 1> t:
        break


    for dir_ in directions:
        nx = x + dir_[1]
        ny = y + dir_[0]


        if grid[ny][nx] == '1':
            continue
        elif grid[ny][nx] == '0':
            pos_queue.append((nx, ny, time + 1))
            grid[ny] = grid[ny][:nx] + '1' + grid[ny][nx+1:]
        elif dir_ == advance[grid[ny][nx]]:
            pos_queue.append((nx, ny, time + 1))
            grid[ny] = grid[ny][:nx] + '1' + grid[ny][nx+1:]

if won == -1:
    print("NOT POSSIBLE")
else:
    print(won)