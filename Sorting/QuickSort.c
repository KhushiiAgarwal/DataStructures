// WAP to implement Quick Sort on 1D array of Employee structure (contains employee_name, emp_no, emp_salary), 
// with key as emp_no. And count the number of swap performed.
#include <stdio.h>
int count=0;
struct emp{
    char name[30];
    int empno;
    int sal;
    };
void swap(struct emp * f ,int min,int max){
    int temp;
    char tempchr[25];
    temp = f[min].sal;
    f[min].sal = f[max].sal;
    f[max].sal = temp;
    temp = f[min].empno;
    f[min].empno = f[max].empno;
    f[max].empno = temp;
    strcpy(tempchr, f[min].name);
    strcpy( f[min].name , f[max].name);
    strcpy(f[max].name , tempchr);
    count++;
}
void QSort(struct emp * s ,int x,int y){
   int i, j, pivot, temp;
   if(x<y){
      pivot=s[x].empno;//element to be compared
      i = x;
      j = y;
      while(i<j){
         while(s[i].empno <= pivot && i < y){
             i++;
        }
         while(s[j].empno > pivot){
             j--;
        }
         if(i < j){
             swap(s , i , j);
         }
      }
      swap(s , j , x);
      QSort(s , x , j-1);
      QSort(s , j+1 , y);
   }
}
void main(){
    struct emp s[3];
    int i,n=3;
    for ( i = 0; i < 3; i++) {
        printf("Enter your Name, Emp No and Salary: ");
        scanf("%s %d %d",s[i].name,&s[i].empno,&s[i].sal);
    }
    QSort(s,0,n-1);
    printf("Sorted array: \n");
    for (i = 0; i < 3; i++) {
        printf("%s %d %d\n",s[i].name,s[i].empno,s[i].sal);
    }
    printf("No of swaps performed= %d",count);
}
