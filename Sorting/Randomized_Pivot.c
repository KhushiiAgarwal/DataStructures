#include<stdio.h>
#include <stdlib.h>
float cmp[50][50];
int n;
int partition(int a[], int min, int max)
{
    int right = max, left = min, flag = 0;
    int index = (rand() % (max - min + 1)) + min;
    
while (flag != 1){
        while ((a[index] <= a[right]) && (index != right)){
            cmp[a[index]][a[right]]++;
            cmp[a[right]][a[index]]++;
            right--;
        }

        if (index == right) {
            flag = 1;
        }

        else if (a[index] > a[right]){
            int temp;
            temp = a[index];
            a[index] = a[right];
            a[right] = temp;
            index = right;
        }

        if (flag != 1){
            while (a[index] >= a[left] && (index != left)){
                cmp[a[left]][a[index]]++;
                cmp[a[index]][a[left]]++;
                left++;
            }

            if (index == left){
                flag = 1;
            }

            else if (a[index] < a[left]){
                int temp;
                temp = a[index];
                a[index] = a[left];
                a[left] = temp;
                index = left;
            }
        }
    }
    return index;
}

void quick_sort(int a[], int min, int max){
    int index;
    if (min < max){
        index = partition(a, min, max);
        quick_sort(a, min, index - 1);
        quick_sort(a, index + 1, max);
    }
}


int main(){
    int c,i,j,n, arr[50];

    printf("Enter the number of iterations: ");
    scanf("%d", &c);
    printf("Enter the number of elements in the array:");
    scanf("%d", &n);
    
for ( i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            cmp[i][j] = cmp[j][i] = 0;
        }
    }
    for ( i = 0; i < c; i++){
        for ( i = 0; i < n; i++){
            arr[i] = i;
        }
        quick_sort(arr, 0, n - 1);
    }

    printf("\nThe average matrix formed after %d iterations is\n", c);
        for (i = 0; i < n; i++) {
        printf("\t%d", arr[i]);
    }
    printf("\n");
    
for (i = 0; i < n; i++) {
        printf("%d\t\t", arr[i]);
        for (j = 0; j < n; j++) {
            printf("%.2f\t", cmp[i][j]);
        }
        printf("\n");
    }
return 0;
}
