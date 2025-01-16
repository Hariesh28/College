def get_matrix():

    matrix = []
    print("Enter the values row by row as a list")

    while True:

        try:
            row = eval(input("Enter row: "))

            if type(row) != list:
                raise TypeError

        except Exception:
            print("Can't capture the row")

        else:
            matrix.append(row)

        choice = input("Do you want to enter more ? (y/n): ")

        if choice.lower() == 'n':
            break

    if len(matrix) == 0:
        row = None

    else:
        row = len(matrix)

    column = []
    for i in matrix:
        column.append(len(i))

    if len(set(column)) == 1:
        column = len(matrix[0])

    else:
        column = None

    return matrix, row, column

def get_two_square_matrix():

    while True:

        print("Enter the value of matrix 1: ")
        matrix_1, row_1, col_1 = get_matrix()

        while row_1 != col_1 or row_1 == None or col_1 == None:
            print("Given Matrix is not a square matrix !")
            print("Enter the value of matrix 1: ")
            matrix_1, row_1, col_1 = get_matrix()

        print("Enter the value of matrix 2: ")
        matrix_2, row_2, col_2 = get_matrix()

        while row_2 != col_2 or row_2 == None or col_2 == None:
            print("Given Matrix is not a square matrix !")
            print("Enter the value of matrix 1: ")
            matrix_2, row_2, col_2 = get_matrix()

        if len(set((row_1, row_2, col_1, col_2))) == 1:
            return matrix_1, matrix_2, row_1

        else:
            print("Both the matrix are not of same size !")

def create_zero_matrix(size):

    matrix = [[0 for _ in range(size)][:] for _ in range(size)]

    """
    row = [0 for _ in range(size)]

    matrix = [row[:] for _ in range(size)]

    for _ in range(size):
        matrix.append(row[:])

    """

    return matrix

def addition(matrix1, matrix2, size):

    result = create_zero_matrix(size)

    for i in range(size):
        for j in range(size):
            result[i][j] = matrix1[i][j] + matrix2[i][j]

    return result

def subtraction(matrix1, matrix2, size):

    result = create_zero_matrix(size)

    for i in range(size):
        for j in range(size):
            result[i][j] = matrix1[i][j] - matrix2[i][j]

    return result

def multiplication(matrix1, matrix2, size):

    result = create_zero_matrix(size)

    for i in range(size):
        for j in range(size):
            for k in range(size):

                result[i][j] += matrix1[i][k] * matrix2[k][j]

    return result

def transpose(matrix, size):

    result = create_zero_matrix(size)

    for i in range(size):
        for j in range(size):
            result[i][j] = matrix[j][i]

    return result

def display_matrix(matrix, size):

    for i in range(size):
        for j in range(size):

            print(f'{matrix[i][j]} ', end='')

        print()

def menu():
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Transpose")
    print("5. Change values of matrix")
    print("6. Exit")


if __name__ == '__main__':

    matrix_1, matrix_2, size = get_two_square_matrix()

    while True:

        choice = ''
        while not isinstance(choice, int):
            menu()
            choice = input("Enter: ")

            try:
                choice = int(choice)

            except ValueError:
                print("Invalid Choice")

        match choice:

            case 1:
                result = addition(matrix_1, matrix_2, size)
                display_matrix(result, size)

            case 2:
                display_matrix(subtraction(matrix_1, matrix_2, size), size)

            case 3:
                result = multiplication(matrix_1, matrix_2, size)
                display_matrix(result, size)

            case 4:
                print("Transpose of matrix 1: ")
                display_matrix(transpose(matrix_1, size), size)

                print("Transpose of matrix 2: ")
                display_matrix(transpose(matrix_2, size), size)

            case 5:
                matrix_1, matrix_1, size = get_two_square_matrix()

            case 6:
                print("Exited !")
                break

            case _:
                print("Invalid Choice")
