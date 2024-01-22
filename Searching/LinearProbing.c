#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FACULTY 100 // maximum number of faculties
#define TABLE_SIZE 101 // hash table size (prime number)

typedef struct Faculty {
    char name[50];
    char department[50];
    char email[50];
} Faculty;

// hash table node for linear probing with chaining
typedef struct HashNode {
    int key; // hash key
    Faculty faculty; // faculty record
    struct HashNode* next; // pointer to next node in chain
} HashNode;

// hash table
typedef struct HashTable {
    HashNode* table[TABLE_SIZE];
} HashTable;

// hash function using MOD operation
int hash(char* name) {
    int i, sum = 0;
    for (i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % TABLE_SIZE;
}

// create a new faculty record
Faculty create_faculty() {
    Faculty faculty;
    printf("Enter faculty name: ");
    scanf("%s", faculty.name);
    printf("Enter department: ");
    scanf("%s", faculty.department);
    printf("Enter email: ");
    scanf("%s", faculty.email);
    return faculty;
}

// create a new hash table node
HashNode* create_node(int key, Faculty faculty) {
    HashNode* node = (HashNode*) malloc(sizeof(HashNode));
    node->key = key;
    node->faculty = faculty;
    node->next = NULL;
    return node;
}

// insert a faculty record into the hash table
void insert(HashTable* ht, Faculty faculty) {
    int key = hash(faculty.name);
    HashNode* node = create_node(key, faculty);
    HashNode* curr = ht->table[key];
    if (curr == NULL) {
        ht->table[key] = node; // no collision, insert at head of chain
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node; // collision, insert at end of chain
    }
}

// search for a faculty record in the hash table
Faculty search(HashTable* ht, char* name) {
    int key = hash(name);
    HashNode* curr = ht->table[key];
    while (curr != NULL) {
        if (strcmp(curr->faculty.name, name) == 0) {
            return curr->faculty;
        }
        curr = curr->next; // linear probing
    }
    Faculty empty = {"", "", ""}; // faculty not found
    return empty;
}

int main() {
    int n, i;
    HashTable ht = {0}; // initialize hash table to NULL
    printf("Enter number of faculties: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        Faculty faculty = create_faculty();
        insert(&ht, faculty);
    }
    char name[50];
    printf("Enter faculty name to search: ");
    scanf("%s", name);
    Faculty faculty = search(&ht, name);
    if (strcmp(faculty.name, "") == 0) {
        printf("Faculty not found.\n");
    } else {
        printf("Faculty details:\n");
        printf("Name: %s\n", faculty.name);
        printf("Department: %s\n", faculty.department);
        printf("Email: %s\n", faculty.email);
    }
   
    // free memory for hash table nodes
    for (i = 0; i < TABLE_SIZE; i++) {
        HashNode* curr = ht.table[i];
        while (curr != NULL) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    return 0;
}
