/*
 * Remove duplicate elements in linkedlist
 * Eg.: 3->4->3->2->6->1->2->6 becomes 3-> 4-> 2-> 6-> 1-> 2
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void removeNodes(struct node** head, int value){

    struct node* curr = *head;
    struct node* prev = *head;

    while(curr){
        if(curr->data > value){
            if (curr == *head){
                *head = curr->next;   
                prev = *head;   
            }
            else
                prev->next = curr->next;
        }
        else
            prev = curr;
        curr = curr->next;
    }

}

void insertNode(struct node** head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
    temp->data = data;
    temp->next = NULL;
    
    if (*head == NULL){
        *head = temp;
    }
    else{
        struct node* curr = *head;
        while(curr->next)
            curr=curr->next;
        curr->next = temp;
    }

}

void displayList(struct node** head){
    struct node* curr = *head;
    while(curr){
        printf("%d ->", curr->data );
        curr=curr->next;
    }
    printf( "NULL\n");
}


void removeDuplicate(struct node** head)
{
    int map[1000] = {0};
    struct node* curr = *head, *prev = NULL;
    
    while(curr != NULL) {
        int data = curr->data;
        if (map[data] == 1) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
            continue;
        }
        map[data] = 1;
        prev = curr;
        curr = curr->next;
    }
    
}

void fill_map(struct node *head, int *map)
{
    while(head != NULL) {
        ++map[head->data];
        head = head->next;
    }    
}

int main()
{
    struct node* head = NULL;
    int map[1000] = {0};
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 6);
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 6);

    displayList(&head);
    //fill_map(head, map);
    removeDuplicate(&head);
    
    displayList(&head);

    return 0;
}


