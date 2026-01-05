#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
node *insAtPos(node *head, int v, int p) {
    node *nn = (node*)malloc(sizeof(node));
    nn->data = v;
    nn->next = NULL;
    if (p == 1) {
        nn->next = head;
        return nn;
    }
    if (head == NULL) {
        printf("List is empty, cannot insert at position %d\n", p);
        free(nn);
        return head;
    }
    node *temp = head;
    int i;
    for (i = 1; i < p-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d out of range\n", p);
        free(nn);
        return head;
    }

    nn->next = temp->next;
    temp->next = nn;
    return head;
}
void display(node *head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    node *head = NULL;
    head = insAtPos(head, 10, 1);
    head = insAtPos(head, 20, 2);
    head = insAtPos(head, 30, 2);
    display(head);
    return 0;
}
