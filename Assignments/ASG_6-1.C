#include <stdio.h>

void print (struct info student);

struct info
{
    char name[50];
    int age ;
    int degree ;
    int section ;

} x[5];
int main ()
{
    x[0].info.name= "Ahmed";
    x[1]= {"Mohamed",19,97,5};
    x[2]= {"Omar",18,90,4};
    x[3]= {"Mostafa",21,89,7};
    x[4]= {"Shadi",20,95,8};

    printf("student 1");
    print(student_1);

    printf("\n\n\nstudent 2");
    print(student_2);

    printf("\n\n\nstudent 3");
    print(student_3);

    printf("\n\n\nstudent 4");
    print(student_4);

    printf("\n\n\nstudent 5");
    print(student_5);



    return 0 ;
}

void print (struct info student)
{
    printf("\n\nName     : %s",student.name);
    printf("\nAge      : %d",student.age);
    printf("\nDegree   : %d",student.degree);
    printf("\nSection  : %d",student.section);

}
