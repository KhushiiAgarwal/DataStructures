// In a lab there were 10 computers which are having numbers as 21 to 30.
// Students registered for a lab are 10 only. Design appropriate hash
// function to assign a computer to every student. Now assume that three
// students are absent of this batch so another batch students want to use
// computers in this lab. Allocate the computers to these new students by
// using linear probing with chaining without replacement.


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct node {
    int data;
    struct node* next;
} Node;

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(Node** table, int data) {
    int index = hash(data);
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = table[index];
    table[index] = node;
}

void display(Node** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: ", i);
        Node* node = table[i];
        while (node != NULL) {
            printf("%d -> ", node->data);
            node = node->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int students[10];
    int computers[10] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    Node* table[TABLE_SIZE] = {NULL};

    // Assign computers to students using hash function
    printf("Enter the student IDs (10 integers):\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &students[i]);
        int index = hash(students[i]) - 1;
        insert(table, computers[index]);
    }

    printf("Computers allocated to the first batch of students:\n");
    display(table);
    printf("\n");

    // Allocate computers to new students using linear probing with chaining
    int count = 0;
    while (count < 3) {
        int key;
        printf("Enter the student ID for new student: ");
        scanf("%d", &key);
        int index = hash(key) - 1;
        if (table[index] == NULL) {
            insert(table, computers[index]);
            printf("New student has been assigned computer %d\n", computers[index]);
            count++;
        } else {
            Node* node = table[index];
            while (node != NULL) {
                if (node->data == computers[index]) {
                    printf("Computer %d is already assigned to a student\n", computers[index]);
                    break;
                }
                node = node->next;
            }
            if (node == NULL) {
                for (int i = index+1; i < TABLE_SIZE; i++) {
                    if (table[i] == NULL) {
                        insert(table, computers[i]);
                        printf("New student has been assigned computer %d\n", computers[i]);
                        count++;
                        break;
                    }
                    Node* node = table[i];
                    while (node != NULL) {
                        if (node->data == computers[i]) {
                            printf("Computer %d is already assigned to a student\n", computers[i]);
                            break;
                        }
                        node = node->next;
                    }
                    if (node == NULL && i == TABLE_SIZE-1) {
                        printf("All computers are already assigned to students\n");
                    }
                }
            }
        }
    }

    printf("\nComputers allocated to the new batch of students:\n");
    display(table);

    return 0;
}
