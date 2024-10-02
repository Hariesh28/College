#  Read only the first 2 lines of the text file created above and print them. Then skip the next 4 characters and print the remaining characters in the line. Then, skip 3 lines and print the remaining lines.

with open('data.txt') as file:

    for _ in range(2):
        print(file.readline(), end='')

    file.seek(file.tell() + 4)
    print(file.readline(), end='')

    for _ in range(3):
        file.readline()

    for i in file.readlines():
        print(i, end='')
