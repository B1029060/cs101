#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    node_t* next;
} node_t;

node_t* allocate_node(int data) {
    return malloc(data * sizeof(int));
}

void show_list(node_t* list) {
    while (1) {
        printf("[%d]->", list->data);
        list->next = list;
        if (list == NULL) {
            printf("null\n");
            break;
        }
    }
}
node_t* append_node(node_t* list, int new_data) {
    list->data = new_data;
    list->next = NULL;
    node_t* current = &list;
}

int main() {
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 11);
    show_list(head);


    return 0;
}