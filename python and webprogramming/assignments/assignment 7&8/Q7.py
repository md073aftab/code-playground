# 7. Create a class for representing any 2-D point or vector. The methods inside this class include 
# its magnitude and its rotation with respect to the X-axis. Using the objects define functions for 
# calculating the distance between two vectors, dot product, cross product of two vectors. Extend 
# the 2-D vectors into 3-D using the concept of inheritance. Update the methods according to 3D.
import math
import numpy as np

class vector2D:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    
    def magnitude(self):
        return (math.sqrt(self.x ** 2 + self.y ** 2))
    
    def rotation(self):
        return math.degrees(math.atan2(self.y,self.x))
    
    def distance(self,other):
        return math.sqrt((self.x-other.x)**2 + (self.y-other.y)**2)

    def dot_product(self,other):
        return self.x * other.x + self.y * other.y
    
    def cross_product(self,other):
        return self.x * other.y - self.y * other.x
    
class vector3D(vector2D):
    def __init__(self,x,y,z):
        super().__init__(x,y)
        self.z = z

    def magnitude(self):
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)
    
    def distance(self,other):
        return math.sqrt((self.x-other.x)**2 + (self.y-other.y)**2 + (self.z-other.z)**2)
    
    def dot_product(self,other):
        return self.x * other.x + self.y * other.y + self.z * other.z
    
    def cross_product(self,other):
        return np.cross(
    np.array([self.x, self.y, self.z]),
    np.array([other.x, other.y, other.z])
)
    
v1 = vector2D(3, 4)
v2 = vector2D(1, 2)
print("Magnitude of v1:", v1.magnitude())
print("Angle of v1 with X-axis:", v1.rotation())
print("Distance between v1 and v2:", v1.distance(v2))
print("Dot product of v1 and v2:", v1.dot_product(v2))
print("Cross product of v1 and v2:", v1.cross_product(v2))

v3 = vector3D(1, 2, 3)
v4 = vector3D(4, 5, 6)
print("\nMagnitude of v3:", v3.magnitude())
print("Distance between v3 and v4:", v3.distance(v4))
print("Dot product of v3 and v4:", v3.dot_product(v4))
print("Cross product of v3 and v4:", v3.cross_product(v4))