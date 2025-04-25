import numpy as np

def magic_square_odd(n):
    magic = np.zeros((n, n), dtype=int)
    i, j = 0, n // 2
    for num in range(1, n**2 + 1):
        magic[i, j] = num
        i_new, j_new = (i-1) % n, (j+1) % n
        if magic[i_new, j_new]:
            i = (i + 1) % n
        else:
            i, j = i_new, j_new
    return magic

def magic_square_doubly_even(n):
    magic = np.arange(1, n*n+1).reshape(n, n)
    for i in range(n):
        for j in range(n):
            if (i % 4 == j % 4) or ((i + j) % 4 == 3):
                magic[i, j] = n*n + 1 - magic[i, j]
    return magic

def magic_square_singly_even(n):
    half_n = n // 2
    sub_square_size = half_n
    sub_square = magic_square_odd(sub_square_size)

    # Allocate a big square
    magic = np.zeros((n, n), dtype=int)

    # Constants for quadrants
    add = [0, 2, 3, 1]  # A, B, C, D quadrants
    for i in range(sub_square_size):
        for j in range(sub_square_size):
            for k in range(4):
                row = i + (k // 2) * sub_square_size
                col = j + (k % 2) * sub_square_size
                magic[row, col] = sub_square[i, j] + add[k] * (sub_square_size**2)

    # Swapping columns
    num_swaps = sub_square_size // 2
    for i in range(sub_square_size):
        for j in range(n):
            if j < num_swaps or (j >= n - num_swaps and j < n):
                if j == num_swaps:  # center column special case
                    if i == num_swaps:
                        continue
                # swap columns between A and C
                temp = magic[i, j]
                magic[i, j] = magic[i + sub_square_size, j]
                magic[i + sub_square_size, j] = temp

    return magic

def generate_magic_square(n):
    if n % 2 == 1:
        return magic_square_odd(n)
    elif n % 4 == 0:
        return magic_square_doubly_even(n)
    else:
        return magic_square_singly_even(n)

# Generate and display squares for N = 4, 5, 6, 7, 8
for n in [4, 5, 6, 7, 8]:
    try:
        print(f"\nMagic Square for N={n}:\n", generate_magic_square(n))
    except ValueError as e:
        print(f"\nN={n}: {e}")
