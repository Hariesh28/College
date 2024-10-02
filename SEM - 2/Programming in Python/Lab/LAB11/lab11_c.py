with open('data.txt') as file:

    for _ in range(2):
        print(file.readline(), end='')

    file.seek(4 + file.tell())
    print(file.readline(), end='')

    for _ in range(3):
        file.readline()

    while True: 
        line = file.readline()

        if line == '':
            break

        else:
            print(line, end='')
