N, Q = map(int, input().split(' '))

mapping = {}
default = 0

while Q:
    Q -= 1

    command = input().split(' ')
    if command[0] == 'SET':
        mapping[command[1]] = command[2]
    elif command[0] == 'RESTART':
        mapping = {}
        default = int(command[1])
    else:
        print(mapping.get(command[1], default))