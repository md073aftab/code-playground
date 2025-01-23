# You are a student in a class of 10. Your class teacher assigns you a task of entering the
# names of all the students in the class. You finally want to display the names given the
# condition that the maximum allowed characters in a name is 15. As a fun task, reverse the
# names and display them. [Hint: Slicing works when you are selecting maximum characters]
student_name = []
print("Enter the student names:")

# Collect student names
for i in range(10):
    name = input(f"Student {i+1} name: ")
    student_name.append(name)

# Reverse and print the names
print("\nReversed Student Names:")
for name in student_name:
    if len(name) > 15:
        updatename = name[:15]
        reversename = updatename[::-1] 
    else:
        reversename = name[::-1]  # Reverse the name directly
    
    print(reversename)