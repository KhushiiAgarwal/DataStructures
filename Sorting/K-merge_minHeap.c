//WAP to implement K-means Merge sort using Min Heap Data Structure
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct {
    int val;
    int idx;
    int size;
    int end;
    int start;
} HeapNode;


void merge_new(int array[], int left, int mid, int right, int size) {
    int n1 = (mid - left) + 1;
    int n2 = right - mid;
    int temp[size];
    for (int i = 0; i < size; ++i)
        temp[i] = array[i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (temp[left + i] < temp[mid + 1 + j]) {
            array[k] = temp[i + left];
            ++i;
        } else {
            array[k] = temp[mid + 1 + j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        array[k] = temp[i + left];
        ++i;
        ++k;
    }
    while (j < n2) {
        array[k] = temp[mid + 1 + j];
        ++j;
        ++k;
    }
}


void mergeSort_new(int array[], int left, int right, int size) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort_new(array, left, mid, size);
        mergeSort_new(array, mid + 1, right, size);
        merge_new(array, left, mid, right, size);
    }
}


void k_array_sort_new(int array[], int size, int k, int sublist_size) {
    for (int i = 0; i < k; i++) {
        if (i == k - 1) {
            int l = sublist_size * i;
            int temp[size - l];
            int x = 0;
            for (int j = l; j <= size - 1; ++j)
                temp[x++] = array[j];
            mergeSort_new(temp, 0, size - l - 1, size - l);
            x = 0;
            for (int j = l; j <= size - 1; ++j)
                array[j] = temp[x++];
        } else {
            int l = sublist_size * i;
            int r = l + sublist_size - 1;
            int temp[sublist_size];
            int x = 0;
            for (int j = l; j <= r; ++j)
                temp[x++] = array[j];
            mergeSort_new(temp, 0, sublist_size - 1, sublist_size);
            x = 0;
            for (int j = l; j <= r; ++j)
                array[j] = temp[x++];
        }
    }
}


void min_heapify_new(HeapNode* heap, int index, int heap_size) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap_size && heap[left].val < heap[smallest].val) {
        smallest = left;
    }
    if (right < heap_size && heap[right].val < heap[smallest].val) {
        smallest = right;
    }
    if (smallest != index) {
        HeapNode tmp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = tmp;
        min_heapify_new(heap, smallest, heap_size);
    }
}


HeapNode* build_heap_new(int array[], int sublist_size, int size, int k) {
    HeapNode* heap = malloc(k * sizeof(HeapNode));
    for (int i = 0; i < k; i++) {
        if (i == k - 1) {
            int l = i * sublist_size;
            heap[i].val = array[l];
            heap[i].start = l;
            heap[i].idx = i;
            heap[i].size = size - l;
            heap[i].end = size - 1;
        } else {
            int l = i * sublist_size;
            heap[i].val = array[l];
            heap[i].start = l;
            heap[i].idx = i;
            heap[i].size = sublist_size;
            heap[i].end = l + sublist_size - 1;
        }
    }
    for (int i = k / 2 - 1; i >= 0; i--) {
        min_heapify_new(heap, i, k);
    }
    return heap;
}


void heap_merge_new(int array[], int sublist_size, int size, int k) {
    HeapNode* heap = build_heap_new(array, sublist_size, size, k);
    int final_arr[size];
    for (int i = 0; i < size; i++) {
        final_arr[i] = heap[0].val;  
        int next_index = heap[0].start + 1;
        if (next_index <= heap[0].end) {
            heap[0].val = array[next_index];
            heap[0].start += 1;
        } else {
            heap[0].val = INT_MAX;  
        }
        min_heapify_new(heap, 0, k); 
    }
    for (int i = 0; i < size; i++)
        array[i] = final_arr[i];
    free(heap);
}


void k_way_new(int array[], int left, int right, int size, int k) {
    int sublist_size = size / k;
    k_array_sort_new(array, size, k, sublist_size);
    heap_merge_new(array, sublist_size, size, k);
}


void Print_new(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }


    int k;
    printf("\n\nEnter the value of k: ");
    scanf("%d", &k);


    if (k > size) {
        printf("partition size is greater than the array size.\n");
        return 0;
    }


    printf("\n\nSorted array:\n");
    k_way_new(array, 0, size - 1, size, k);
    Print_new(array, size);


    return 0;
}
