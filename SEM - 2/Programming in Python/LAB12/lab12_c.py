import sys

number = sys.argv[1]

def isPrime(number:int) -> bool:
    
    if number <= 1:
        return False
    
    for i in range(2, int(number ** 0.5) + 1):
        if number % i == 0:
            return False
        
    return True


prime_numbers:list[int] = [i for i in range(int(number)) if isPrime(i)]

print(prime_numbers)