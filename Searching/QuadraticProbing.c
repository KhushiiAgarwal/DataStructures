#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node* hashtable[], int key, int loc) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if(hashtable[loc] == NULL) {
        hashtable[loc] = newNode;
    } else {
        struct Node* curr = hashtable[loc];
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void displayHashtable(struct Node* hashtable[], int n) {
    printf("Hashtable:\n");
    for(int i=0; i<n; i++) {
        printf("Bucket %d: ", i);
        struct Node* curr = hashtable[i];
        while(curr != NULL) {
            printf("%d -> ", curr->data);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, k, m;
    printf("Enter the size of hashtable: ");
    scanf("%d", &n);
    struct Node* hashtable[n];
    for(int i=0; i<n; i++) {
        hashtable[i] = NULL;
    }
    printf("Enter the number of keys to insert: ");
    scanf("%d", &k);
    printf("Enter the keys: ");
    for(int i=0; i<k; i++) {
        int key;
        scanf("%d", &key);
        int loc = key / n;
        if(hashtable[loc] == NULL) {
            insertNode(hashtable, key, loc);
        } else {
            // quadratic probing technique
            int j = 1;
            while(hashtable[(loc+j*j)%n] != NULL) {
                j++;
            }
            insertNode(hashtable, key, (loc+j*j)%n);
        }
    }
    displayHashtable(hashtable, n);
    return 0;
}
