def first_gt(x, arr):
    "Return first element in the array with a value greater than x"
    for el in arr:
        if el > x:
            return el

def sieve(to):
    nums = list(range(2,to+1))
    prime = 2 # current prime number
    while prime < len(nums): # prime can't be greater than list's biggest number
        for num in nums:
            if num % prime == 0 and num != prime:
                nums.remove(num) # num is not a prime number
        prime = first_gt(prime, nums)
    return nums # executed when the loop ends

def main():
    to = input("Sieve of 2-?? ")
    try:
        to = int(to)
    except:
        print("You didn't entered an integer as input")
    else:
        if to <= 2:
            print("Please enter a value greater than 2")
    
    print(sieve(to))


main()