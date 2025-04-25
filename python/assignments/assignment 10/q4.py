import numpy as np

arr = np.array(['apple', 'banana', 'cherry'])

centered = np.char.center(arr, 15, fillchar='_')
left = np.char.ljust(arr, 15, fillchar='_')
right = np.char.rjust(arr, 15, fillchar='_')

print("Centered:\n", centered)
print("Left-justified:\n", left)
print("Right-justified:\n", right)
