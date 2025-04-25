import numpy as np
import matplotlib.pyplot as plt

def f(x):
    return x**3 - x - 2

def bisection(a, b, tol=1e-5):
    history = []
    while (b - a) / 2.0 > tol:
        midpoint = (a + b) / 2.0
        history.append(midpoint)
        if f(midpoint) == 0:
            break
        elif f(a) * f(midpoint) < 0:
            b = midpoint
        else:
            a = midpoint
    return midpoint, np.array(history)

root, steps = bisection(1, 2)
print("Root found:", root)

# Plotting the process
x_vals = np.linspace(1, 2, 100)
y_vals = f(x_vals)

plt.plot(x_vals, y_vals, label='f(x)')
plt.axhline(0, color='gray', linestyle='--')
plt.plot(steps, f(steps), 'ro--', label='Bisection steps')
plt.title("Bisection Method Root Finding")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.legend()
plt.grid()
plt.show()
