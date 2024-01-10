#include <stdio.h>
#include <stdlib.h>


#define MAX_TREE_NODES 256


typedef struct Node {
    char data;
    unsigned frequency;
    struct Node* left;
    struct Node* right;
} Node;


typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node** array;
} MinHeap;


Node* createNode(char data, unsigned frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}


MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node**)malloc(minHeap->capacity * sizeof(Node*));
    return minHeap;
}


void swapNode(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}


void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;


    if (left < minHeap->size &&
        minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;


    if (right < minHeap->size &&
        minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;


    if (smallest != idx) {
        swapNode(&minHeap->array[idx], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}


int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}


Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}


void insertMinHeap(MinHeap* minHeap, Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}


Node* buildHuffmanTree(char data[], unsigned frequency[], int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, createNode(data[i], frequency[i]));
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}


void printHuffmanCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}


int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned frequency[] = {5, 7, 14, 15, 11, 20};
    int size = sizeof(data) / sizeof(data[0]);


    Node* root = buildHuffmanTree(data, frequency, size);


    int arr[MAX_TREE_NODES], top = 0;
    printHuffmanCodes(root, arr, top);


    return 0;
}


