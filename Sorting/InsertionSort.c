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
    //Assuming 1st element is sorted
     for (i = 1; i < n; i++) {
        temp=s[i].rollno;
        j=i-1;
        while(j>=0 && s[j].rollno>temp){
            s[j+1].rollno=s[j].rollno;
            strcpy(s[j+1].name,s[j].name);
            s[j+1].cpi=s[j].cpi;
            j--;
        }
        s[j+1].rollno=temp;
    }
  
  printf("Sorted array: \n");
    for (i = 0; i < 3; i++) {
        printf("%s %d %f \n",s[i].name,s[i].rollno,s[i].cpi);
    }
}
