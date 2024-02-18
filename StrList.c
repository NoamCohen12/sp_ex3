#include <stdio.h>
#include "StrList.h"

typedef struct _node{
    char* data;
    struct _node* next; 
}Node;


struct _StrList{
    Node* _head;
    size_t _size;
};

StrList* StrList_alloc(){
    StrList* p = (StrList*)malloc(sizeof(StrList));
    p->_head = (Node*)malloc(sizeof(Node)); 
    return p;
}


void StrList_free(StrList* StrList){
    if (StrList == NULL) return;
    Node* p1 = StrList->_head;
    Node* p2;
    while(p1 != NULL) {
        p2 = p1;
        p1 = p1->next;
        free(p2);
    }
    free(StrList);
}

 
size_t StrList_size(const StrList* StrList){
    return StrList->_size;
}

void StrList_insertLast(StrList* StrList,const char* data){
    Node* p1 = StrList->_head;
    Node* p2;
    while(p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data= data;
    new_node->next= NULL;
    p1->next = new_node;
}

void StrList_insertAt(StrList* StrList,const char* data,int index){
    Node* p1 = StrList->_head;
    Node* p2 = NULL;
    int count = 0;

    // Check if insert at the beginning of the list
    if (index == 0) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) {
            return; // Handle memory allocation failure
        }
        new_node->data = data;
        new_node->next = StrList->_head;
        StrList->_head = new_node;
        return;
    }

    // check if insert at the end of the list
    while(p1 != NULL && count < index) {
        p2 = p1;
        p1 = p1->next;
        count++;
    }
    if (p1 == NULL){
        // Handle index out of range (insert at the end)
        // You can choose to append the new node at the end of the list here
        return;
    }
    // Create a new node and insert it between p2 and p1
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return; // Handle memory allocation failure
    }
    new_node->data = data;
    new_node->next = p1;
    p2->next = new_node;

}

char* StrList_firstData(const StrList* StrList){
    return StrList->_head->data;

}

void StrList_print(const StrList* StrList){
      if (StrList == NULL) {
        printf("Invalid StrList pointer\n");
        return;
    }
    printf("StrList contents:\n");

    if (StrList->_head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* current = StrList->_head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }

}
void StrList_printAt(const StrList* Strlist,int index){

}

int StrList_printLen(const StrList* Strlist){

}
int StrList_count(StrList* StrList, const char* data){

}
void StrList_remove(StrList* StrList, const char* data){

}
void StrList_removeAt(StrList* StrList, int index){

}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){

}
StrList* StrList_clone(const StrList* StrList){

}

void StrList_reverse( StrList* StrList){

}
void StrList_sort( StrList* StrList){

}
int StrList_isSorted(StrList* StrList){

}









