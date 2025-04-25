import random

def is_safe(board, row, col):
    for i in range(row):
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True

def solve_n_queens(n, board=[], row=0, solutions=[]):
    if row == n:
        solutions.append(board[:])
        return

    cols = list(range(n))
    random.shuffle(cols)
    for col in cols:
        if is_safe(board, row, col):
            board.append(col)
            solve_n_queens(n, board, row + 1, solutions)
            board.pop()

    return solutions

# Find all solutions for 8 queens
solutions = solve_n_queens(8)
print("Number of solutions found:", len(solutions))
print("One sample solution (row = index, value = column):")
print(solutions[0])
