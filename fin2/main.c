#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
    int data;
    struct LinkedList* next_node;
} LinkedList;

LinkedList* allocate_node(char data) {
    LinkedList* p = (LinkedList*)calloc(1, sizeof(LinkedList));
    p->data = data;
    p->next_node = NULL;
    return p;
}
LinkedList* appendList(LinkedList* head, char new_data) {
    LinkedList* new_node = allocate_node(new_data);
    
    if (head) {
        LinkedList* p = head;
        while (p->next_node) {
            p = p->next_node;
        }
        p->next_node = new_node;
    } else {
        head = new_node;
    }
    return head;
}
void show_list(LinkedList* head) {
    while (head) {
        printf("[%c]->", head->data);
        head = head->next_node;
    }
    printf("null\n");
}


int main() {
    LinkedList* head = NULL;
    head = appendList(head, 'A');
    head = appendList(head, 'B');
    head = appendList(head, 'C');
    head = appendList(head, 'D');
    head = appendList(head, 'E');
    show_list(head);
    return 0;
}
