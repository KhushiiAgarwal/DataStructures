#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char employee_name[20];
    int emp_no;
    int emp_salary;
};
void swap(struct Employee *a, struct Employee *b){
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
}
int partition(struct Employee arr[] , int s , int e , int *swap_count){
    int pivot = arr[s].emp_no;
    int count = 0;
    for (int i = s+1; i <= e; i++)
    {
        if (arr[i].emp_no <= pivot)
        {
            count++;
        }      

    }
    int pivot_index = s + count;
    swap(&arr[pivot_index] , &arr[s]);
    (*swap_count)++;
    int k = s;
    int l = e;
    while (k < pivot_index && l > pivot_index)
    {
        if (arr[k].emp_no <= pivot)
        {
            k++;
        }
        if (arr[l].emp_no >pivot)
        {
            l--;
        }
        if (k < pivot_index && l>pivot_index)
        {
            swap(&arr[k++] , &arr[l--]);
            (*swap_count)++;
        }      
    }  
    return pivot_index;  
}
void quick_sort(struct Employee arr[] , int s , int e , int*swap_count){
    if (s >= e)
    {
        return;
    }
    int pivot_index = partition(arr, s, e, swap_count);
    quick_sort(arr , s , pivot_index-1 , swap_count);
    quick_sort(arr , pivot_index+1 , e , swap_count);  
}
void merge(struct Employee arr[] , int s , int e ){
    int m = s + (e-s)/2;
    int length1 = m-s + 1;
    int length2 = e-m;
    int count = 0;

    struct Employee first[length1];
    struct Employee second[length2];
   
    int mai = s;
    for (int i = 0; i < length1; i++)
    {
        first[i] = arr[mai++];
    }
    mai = m+1;
    for (int i = 0; i < length2; i++)
    {
        second[i] = arr[mai++];
    }
    int index1 = 0;
    int index2 = 0;
    mai = s;
    while (index1 < length1 && index2 < length2)
    {
        if (first[index1].emp_no < second[index2].emp_no)
        {
            arr[mai++] = first[index1++];
            count++;
        }
        else
        {
            arr[mai++] = second[index2++];
        }        
    }
    while (index1 <length1)
    {
        arr[mai++] = first[index1++];
    }
    while (index2 < length2)
    {
        arr[mai++] = second[index2++];
    }
    printf("\nAnd number of swap performed using Merge Sort: %d\n" ,count);
}
void merge_sort(struct Employee arr[] , int s , int e){

    if (s>= e)
    {
        return;
    }
    int m = s + (e-s)/2;
    merge_sort(arr, s , m);
    merge_sort(arr, m+1 , e);
    merge(arr , s , e );
}
void heapify(struct Employee arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l].emp_no > arr[largest].emp_no)
        largest = l;
    if (r < n && arr[r].emp_no > arr[largest].emp_no)
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(struct Employee arr[], int n) {
    int count = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--) {
        swap(&arr[0], &arr[i]);
        count++;
        heapify(arr, i, 0);
    }
    printf("And number of swap performed using Heap Sort: %d\n", count);
}
void main(){

   
    struct Employee arr[3];
        for (int i =0; i<3 ; i++){
        printf("Enter employee name , employee number and employee salary%d\n",(i+1));
        scanf("%s %d %d",&arr[i].employee_name,&arr[i].emp_no,arr[i].emp_salary);
        }
    int n = sizeof(arr)/sizeof(arr[0]);
    int swap_count = 0;
    int s = 0;
    int e = n-1;
    quick_sort(arr , s , e , &swap_count);
    printf("Sorted Array using Quick Sort: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d \n", arr[i].employee_name , arr[i].emp_no ,
arr[i].emp_salary);
    }
    printf("And number of swap performed using Quick Sort: %d\n" ,swap_count);
    merge_sort(arr , s , e);
    printf("\nSorted Array using Merge Sort: \n");
    for (int i = 0; i< n; i++)
    {
        printf(" %s %d %d \n", arr[i].employee_name , arr[i].emp_no ",arr[i].emp_salary);
    }
   
    heapSort(arr, n);
    printf("Sorted Array using Heap Sort:\n");
    for (int i=0; i<n; i++) {
        printf(" %s %d %d \n" , arr[i].employee_name , arr[i].emp_no ,arr[i].emp_salary);    
        }
    return 0;
}
