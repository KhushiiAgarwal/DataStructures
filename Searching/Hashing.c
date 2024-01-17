#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* table[SIZE];
int hash(int key) {
    return key % SIZE;
}

void insert(int data) {
    int key = hash(data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->next = NULL;
    
    if (table[key] != NULL) {
        struct Node* temp = table[key];
        
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        table[key] = newNode;
    }
}

void search(int data) {
    int key = hash(data);
    struct Node* temp = table[key];

    while (temp != NULL) {
        if (temp->data == data) {
            printf("%d found in hash table.\n", data);
            
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in hash table.\n", data);
}
void delete(int data) {
    int key = hash(data);
    
struct Node* temp = table[key];
    struct Node* prev = NULL;
   
while (temp != NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                // Node is first in chain
                table[key] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("%d deleted from hash table.\n", data);
            
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not found in hash table.\n", data);
}
void display() {
    printf("Hash Table:\n");
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d -> ", i);
        if (table[i] != NULL) {
            struct Node* temp = table[i];
            
            while (temp != NULL) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
        }
        printf("NULL\n");
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }
    
    insert(10);
    insert(5);
    insert(14);
    insert(12);
    insert(11);
    insert(7);
    display();
    search(14);
    delete(5);
    printf("\n After deletion\n");
    display();
    
    return 0;
}
 
