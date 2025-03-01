class student:
    class_year=2025
    num_student=0

    def __init__(self,name,age):
        self.name=name
        self.age=age
        student.num_student+=1

student1=student("aftab",19)
student2=student("karan",18)
student3=student("keval",19)

print(student1.name)