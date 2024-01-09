#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
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
    for (int i = s+1; i &lt;= e; i++)
    {
        if (arr[i].emp_no &lt;= pivot)
        {
            count++;
        }      

    }
    int pivot_index = s + count;
    swap(&amp;arr[pivot_index] , &amp;arr[s]);
    (*swap_count)++;
    int k = s;
    int l = e;
    while (k &lt; pivot_index &amp;&amp; l &gt; pivot_index)
    {
        if (arr[k].emp_no &lt;= pivot)
        {
            k++;
        }
        if (arr[l].emp_no &gt; pivot)
        {
            l--;
        }
        if (k &lt; pivot_index &amp;&amp; l &gt; pivot_index)
        {
            swap(&amp;arr[k++] , &amp;arr[l--]);
            (*swap_count)++;
        }      
    }  
    return pivot_index;  
}
void quick_sort(struct Employee arr[] , int s , int e , int*swap_count){
    if (s &gt;= e)
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
    for (int i = 0; i &lt; length1; i++)
    {
        first[i] = arr[mai++];
    }
    mai = m+1;
    for (int i = 0; i &lt; length2; i++)
    {
        second[i] = arr[mai++];
    }
    int index1 = 0;
    int index2 = 0;
    mai = s;
    while (index1 &lt; length1 &amp;&amp; index2 &lt; length2)
    {
        if (first[index1].emp_no &lt; second[index2].emp_no)
        {
            arr[mai++] = first[index1++];
            count++;
        }
        else
        {
            arr[mai++] = second[index2++];
        }        
    }
    while (index1 &lt; length1)
    {
        arr[mai++] = first[index1++];
    }
    while (index2 &lt; length2)
    {
        arr[mai++] = second[index2++];
    }
    printf(&quot;\nAnd number of swap performed using Merge Sort: %d\n&quot; ,
count);
}
void merge_sort(struct Employee arr[] , int s , int e){

    if (s&gt;= e)
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
    if (l &lt; n &amp;&amp; arr[l].emp_no &gt; arr[largest].emp_no)
        largest = l;
    if (r &lt; n &amp;&amp; arr[r].emp_no &gt; arr[largest].emp_no)
        largest = r;
    if (largest != i) {
        swap(&amp;arr[i], &amp;arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(struct Employee arr[], int n) {
    int count = 0;
    for (int i = n / 2 - 1; i &gt;= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i&gt;=0; i--) {
        swap(&amp;arr[0], &amp;arr[i]);
        count++;
        heapify(arr, i, 0);
    }
    printf(&quot;And number of swap performed using Heap Sort: %d\n&quot;, count);
}
void main(){

   
    struct Employee arr[3];
        for (int i =0; i&lt;3 ; i++){
        printf(&quot;Enter employee name , employee number and employee salary
%d\n&quot;,(i+1));
        scanf(&quot;%s %d %d&quot;,&amp;arr[i].employee_name,&amp;arr[i].emp_no,
&amp;arr[i].emp_salary);
        }
    int n = sizeof(arr)/sizeof(arr[0]);
    int swap_count = 0;
    int s = 0;
    int e = n-1;
    quick_sort(arr , s , e , &amp;swap_count);
    printf(&quot;Sorted Array using Quick Sort: \n&quot;);
    for (int i = 0; i &lt; n; i++)
    {
        printf(&quot;%s %d %d \n&quot; , arr[i].employee_name , arr[i].emp_no ,
arr[i].emp_salary);
    }
    printf(&quot;And number of swap performed using Quick Sort: %d\n&quot; ,
swap_count);
    merge_sort(arr , s , e);
    printf(&quot;\nSorted Array using Merge Sort: \n&quot;);
    for (int i = 0; i &lt; n; i++)
    {
        printf(&quot; %s %d %d \n&quot; , arr[i].employee_name , arr[i].emp_no ,
arr[i].emp_salary);
    }
   
    heapSort(arr, n);
    printf(&quot;Sorted Array using Heap Sort:\n&quot;);
    for (int i=0; i&lt;n; i++) {
        printf(&quot; %s %d %d \n&quot; , arr[i].employee_name , arr[i].emp_no ,
arr[i].emp_salary);    
        }
    return 0;
}
