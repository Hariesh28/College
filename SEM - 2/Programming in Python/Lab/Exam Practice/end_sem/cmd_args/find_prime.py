import sys

def isPrime(number:int) -> bool:

    if number < 2:
        return False

    for i in range(2, int(number ** 0.5) + 1):

        if number % i == 0:
            return False

    return True

if len(sys.argv) != 2:
    print("Invalid")
    exit()

try:
    num = int(sys.argv[1])

except ValueError:
    print("Invalid")
    exit()
    
else:
    for i in range(int(sys.argv[1]) + 1):
        if isPrime(i):
            print(i, end=' ')