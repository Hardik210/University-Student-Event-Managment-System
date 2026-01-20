#include<stdio.h>
#include<string.h>

enum EventType{
    cultural,
    sports,
    technical
};

union Score{
    int score;
};

typedef struct Event{
    char Eventname[50];
    enum EventType type;
    int maxMarks;
    union Score score;
}Event;

typedef struct Student{
    int rollno;
    char name[50];
    int age;
    char phone[20];
    char email[50];

    Event event[3];

    int totalmarks;
    float avg;
    char grade;
}Student;

void addstudent(Student student[]){
    int i,j;

    for(i=0;i<2;i++){
        printf("Enter the roll no:");
        scanf("%d",&student[i].rollno);

        printf("Enter the name:");
        scanf("%s",&student[i].name);

        printf("Enter the age:");
        scanf("%d",&student[i].age);

        printf("Enter the phone no:");
        scanf("%s",&student[i].phone);

        printf("Enter the email:");
        scanf("%s",&student[i].email);

        for(j=0;j<3;j++){
            printf("Enter the Event name:");
            scanf("%s",&student[i].event[j].Eventname);

            printf("Enter the Event type:");
            scanf("%d",&student[i].event[j].type);

            printf("Maaximum Marks:");
            scanf("%d",&student[i].event[j].maxMarks);

            printf("Marks Obtained:");
            scanf("%d",&student[i].event[j].score.score);
        }
    }
}

void report(Student student[]){
    int i,j;
    for(i=0;i<2;i++){
        student[i].totalmarks=0;
        for(j=0;j<3;j++){
            student[i].totalmarks=student[i].totalmarks + student[i].event[j].score.score;
        }
        student[i].avg=(float)student[i].totalmarks/3;

        if(student[i].avg >= 90){
            student[i].grade = 'A';
        }
        else if(student[i].avg >= 80){
            student[i].grade = 'B';
        }
        else
            student[i].grade = 'C';

        printf("%s\t%d\t%f\t%c\n",
               student[i].name,
               student[i].totalmarks,
               student[i].avg,
               student[i].grade);
    }
}

void sort(Student student[]){
    int i,j;
    Student temp;

for(i=0;i<2;i++){
    for(j=i+1;j<2;j++){
        if(student[i].totalmarks<student[j].totalmarks){
            temp=student[i];
            student[i]=student[j];
            student[j]=temp;
        }
    }
}
}

void leaderboard(Student student[]){
    int i;
    for(i=0;i<2;i++){
        printf("%s\t",student[i].name);
        printf("%d\n",student[i].totalmarks);
    }
}

void search(Student student[],int rollno){
    int i,j;
    int found=0;
    for(i=0;i<2;i++){
        if(student[i].rollno==rollno){
            found=1;
            printf("Roll No:%d\n",student[i].rollno);
            printf("Name: %s\n", student[i].name);
            printf("Age: %d\n", student[i].age);
            printf("Phone: %s\n", student[i].phone);
            printf("Email: %s\n", student[i].email);
            printf("Total: %d\n", student[i].totalmarks);
            printf("Average: %.2f\n", student[i].avg);
            printf("Grade: %c\n", student[i].grade);
            break;
        }
    }
    if(found!=1){
        printf("Do not exist");
    }
}

void  main(){
    Student student[2];

    addstudent(student);
    report(student);
    search(student,12);
    sort(student);
    leaderboard(student);
    

}