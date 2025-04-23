#4. Create a class "Employee" with attributes name and salary. Implement overloaded operators + and - to combine and compare employees based on their salaries.
class Employee:
    def __init__(self,name,salary):
        self.name = name
        self.salary = salary
        
    def __add__(self,other):
        sum =  self.salary + other.salary
        return f"Total salary is {sum}"
    
    def __sub__(self,other):
        diff =  abs(self.salary - other.salary)
        return f"Difference is {diff}"
    
obj1 = Employee("aftab",1000)
obj2 = Employee("keval",6000)

print(obj1 + obj2)
print(obj1 - obj2)