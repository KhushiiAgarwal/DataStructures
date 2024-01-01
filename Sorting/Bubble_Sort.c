#include <stdio.h>
#include <string.h>
struct stud{
    char name[30];
    int rollno;
    float cpi;
    };
void main(){
    int i, temp, j,n=3;;
    struct stud s[3];
    char temp2[20];
    for (i = 0; i < 3; i++) {
        printf("Enter your Name, Roll No and CGPA: ");
        scanf("%s %d %f",s[i].name,&s[i].rollno,&s[i].cpi);
    }
    printf("unSorted array: \n");
    for (i = 0; i < 3; i++) {
        printf("%s %d %f \n",s[i].name,s[i].rollno,s[i].cpi);
    }
    for (i = 0; i < 3; i++) {
                for (j = i+1; j < 3; j++) {
         if(s[i].rollno>s[j].rollno){
        temp=s[i].rollno;
        s[i].rollno=s[j].rollno;
        s[j].rollno=temp;
        temp=s[i].cpi;
        s[i].cpi=s[j].cpi;
        s[j].cpi=temp;
        strcpy(temp2,s[i].name);
        strcpy(s[i].name,s[j].name);
        strcpy(s[j].name,temp2);
                        }
                }
    }
    printf("Sorted array: \n");
    for (i = 0; i < 3; i++) {
        printf("%s %d %f \n",s[i].name,s[i].rollno,s[i].cpi);
    }
}
