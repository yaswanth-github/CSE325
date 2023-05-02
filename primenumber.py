# function to check if a number is prime
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# prompt user to enter a number
num = int(input("Enter a number: "))

# iterate through all numbers up to num and print primes
print("Prime numbers up to", num, "are:")
for i in range(2, num + 1):
    if is_prime(i):
        print(i)
