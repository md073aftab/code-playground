import numpy as np

N = 10
points = np.random.rand(N, 2) * 10  # random 2D points

x, y = points[:, 0], points[:, 1]
r = np.sqrt(x**2 + y**2)
theta = np.arctan2(y, x)

polar = np.column_stack((r, theta))
print("Cartesian:\n", points)
print("Polar:\n", polar)
