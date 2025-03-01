// Q3: Write a C program to manage the details of students using an array of structures.
//The program should:
//1. Accept the number of students (n) from the user.
//2. For each student, input the following details:
//• Roll number (integer)
//• Name (string)
//• Marks (floating-point value)
//3. Store the details of all students in an array of structures.
//4. Display the details of all students in a formatted way.

#include<stdio.h>
#include<strings.h>

typedef struct
{

    int roll_no;
    char name[50];
    float marks;

}student;


int main()
{
    int n;
    printf("enter the number of students : \n");
    scanf("%d",&n);

    student person[n];

    for(int i=0 ; i<n ; i++)
    {
        printf("enter the roll no of student %d : \n",i+1);
        scanf("%d",&person[i].roll_no);

        printf("enter the marks of student %d : \n",i+1);
        scanf("%f",&person[i].marks);

        printf("enter the name of student %d : \n",i+1);
        scanf("%s",&person[i].name);
    }
    printf("\nentered students details is shown below : \n");
    for(int i=0 ; i<n ; i++)
    {
        printf("\ndetails of student %d : \n",i+1);
        printf("roll no = %d\n",person[i].roll_no);
        printf("marks = %f\n",person[i].marks);
        printf("name = %s",person[i].name);
    }
}