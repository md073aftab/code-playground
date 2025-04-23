#Write a program that generates 100 random integers that are either 0 or 1. Then find the
#longest run of zeros, the largest number of zeros in a row. For instance, the longest run of
#zeros in [1,0,1,1,0,0,0,0,1,0,0] is 4.

import random

# Generate 100 random integers (0 or 1)
random_int = [random.randint(0, 1) for _ in range(100)]
print(random_int)

zeroes = 0
max_zeroes = 0

# Iterate through the list to find the longest run of zeros
for num in random_int:
    if num == 0:
        zeroes += 1
        max_zeroes = max(max_zeroes, zeroes)
    else:
        zeroes = 0  # Reset the zero count on encountering a 1

print("Max number of continuous zeros is:", max_zeroes)
