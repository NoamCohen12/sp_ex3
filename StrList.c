#include <stdio.h>
#include "StrList.h"
#include <string.h>


typedef struct _node
{
    char *data;
    struct _node *next;
} Node;

struct _StrList
{
    Node *_head;
    size_t _size;
};

typedef struct _StrList StrList;
Node *Node_alloc(char *data, Node *next);

void StrList_swap( Node** node1, Node** node2);

Node *Node_alloc(char *data, Node *next)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = next;
    return p;
}

StrList *StrList_alloc()
{
    StrList *p = (StrList *)malloc(sizeof(StrList));
    if (p == NULL)
    {
        return NULL; // Allocation failed
    }
    // Initialize the allocated StrList structure
    p->_head = NULL; // Initialize head to NULL as the list is initially empty
    p->_size = 0;    // Initialize size to 0
    return p;
}

void StrList_free(StrList *StrList)
{
    if (StrList == NULL)
        return;
    Node *p1 = StrList->_head;
    Node *p2;
    while (p1 != NULL)
    {
        p2 = p1;
        p1 = p1->next;
        free(p2->data);
        free(p2);
    }
    free(StrList);
}

size_t StrList_size(const StrList *StrList)
{
    return StrList->_size;
}

void StrList_insertLast(StrList *StrList, const char *data)
{
    Node *p1 = StrList->_head;
    Node *p2;

    // Check if the list is empty
    if (p1 == NULL) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            // Handle memory allocation failure
            return;
        }
        new_node->data = strdup(data);
        new_node->next = NULL;
        StrList->_head = new_node;  // Update the head of the list
        return;
    }

    // Traverse the list to find the last node
    while (p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }

    // Create a new node and insert it at the end
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return;
    }
    new_node->data = strdup(data);
    new_node->next = NULL;
    p1->next = new_node;
}

// { 
//     Node *p1 = StrList->_head;
//     Node *p2;

//     // Handle the case when the list is empty
//     if (p1 == NULL) {
//         Node *new_node = (Node *)malloc(sizeof(Node));
//         if (new_node == NULL) {
//             // Handle memory allocation failure
//             return;
//         }
//         new_node->data = strdup(data);
//         new_node->next = NULL;
//         StrList->_head = new_node;
//         return;
//     }

//     // Traverse the list to find the last node
//     while (p1->next != NULL)
//     {
//         p2 = p1;
//         p1 = p1->next;
        
//     }

//     // Create a new node and insert it at the end
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     if (new_node == NULL) {
//         // Handle memory allocation failure
//         return;
//     }
//     new_node->data = strdup(data);
//     new_node->next = NULL;
//     p1->next = new_node;
// }


void StrList_insertAt(StrList *StrList, const char *data, int index)
{
    Node *p1 = StrList->_head;
    Node *p2 = NULL;
    int count = 0;

    // Check if insert at the beginning of the list
    if (index == 0)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL)
        {
            return; // Handle memory allocation failure
        }
        // new_node->data = data;
        new_node->data = strdup(data);
        new_node->next = StrList->_head;
        StrList->_head = new_node;
        return;
    }

    // check if insert at the end of the list
    while (p1 != NULL && count < index)
    {
        p2 = p1;
        p1 = p1->next;
        count++;
    }
    if (p1 == NULL)
    {
        // Handle index out of range (insert at the end)
        // You can choose to append the new node at the end of the list here
        return;
    }
    // Create a new node and insert it between p2 and p1
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return; // Handle memory allocation failure
    }
    // new_node->data = data;
    new_node->data = strdup(data);
    new_node->next = p1;
    p2->next = new_node;
}

char *StrList_firstData(const StrList *StrList)
{
    return StrList->_head->data;
}

void StrList_print(const StrList *StrList)
{
    if (StrList == NULL)
    {
        printf("Invalid StrList pointer\n");
        return;
    }
    printf("StrList contents:\n");

    if (StrList->_head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *current = StrList->_head;
    while (current != NULL)
    {
        printf("%s ", current->data);
        current = current->next;
    }
}
void StrList_printAt(const StrList *Strlist, int index)
{
    if (Strlist == NULL || Strlist->_head == NULL || index < 0)
    {
        // printf("Invalid input\n");
        return;
    }

    Node *current = Strlist->_head;
    int count = 0;

    while (current != NULL)
    {
        if (count == index)
        {
            printf("%s\n", current->data);
            return;
        }
        current = current->next;
        count++;
    }
}

int StrList_printLen(const StrList *Strlist)
{
    int sum_of_lengths = 0;
    if (Strlist == NULL || Strlist->_head == NULL)
    {
        return 0;
    }
    else
    {
        Node *current = Strlist->_head;
        while (current != NULL)
        {
            sum_of_lengths = sum_of_lengths + strlen(current->data);
            current = current->next;
        }
    }
    return sum_of_lengths;
}
int StrList_count(StrList *StrList, const char *data)
{
    int count = 0;
    Node *current = StrList->_head;
    while (current != NULL)
    {
        if (strcmp(current->data, data) == 0)
        {
            current = current->next;
            count++;
        }
    }
    return count;
}
void StrList_remove(StrList *StrList, const char *data)
{
    if (StrList == NULL || StrList->_head == NULL)
    {
        return; // Bad input or empty list
    }

    // Check if there's only one node in the list
    if (StrList->_head->next == NULL)
    {
        if (strcmp(StrList->_head->data, data) == 0)
        {
            // Match found, remove the node
            free(StrList->_head->data);
            free(StrList->_head);
            StrList->_head = NULL; // Update head to NULL
            StrList->_size = 0;    // Update size to 0
            return;
        }
        else
        {
            return; // No match found in the only node
        }
    }

    // More than one node in the list
    Node *current = StrList->_head;
    Node *pre = NULL;
    while (current != NULL)
    {
        if (strcmp(current->data, data) == 0)
        {
            // Match found, remove the node
            if (pre == NULL)
            {
                StrList->_head = current->next; // Update head if removing the first node
            }
            else
            {
                pre->next = current->next;
            }
            free(current->data);
            free(current);
            return;
        }
        pre = current;
        current = current->next;
    }
}
void StrList_removeAt(StrList *StrList, int index)
{
    if (StrList == NULL || StrList->_head == NULL || index < 0)
    {
        return; // Bad input or empty list
    }

    // Check if there's only one node in the list
    if (StrList->_head->next == NULL && index == 0)
    {
        // Match found, remove the node
        free(StrList->_head->data);
        free(StrList->_head);
        StrList->_head = NULL; // Update head to NULL
        StrList->_size = 0;    // Update size to 0
        return;
    }
    else
    {
        if (StrList->_head->next == NULL && index != 0)
        {
            // Index out of bounds for a list with only one node
            return;
        }

        int count = 0;
        // More than one node in the list
        Node *current = StrList->_head;
        Node *pre = NULL;
        while (current != NULL)
        {
            if (count == index)
            {
                // Match found, remove the node
                if (pre == NULL)
                {
                    StrList->_head = current->next; // Update head if removing the first node
                }
                else
                {
                    pre->next = current->next;
                }
                free(current->data);
                free(current);
                return;
            }
            count++;
            pre = current;
            current = current->next;
        }
    }
}

int StrList_isEqual(const StrList *StrList1, const StrList *StrList2)
{
    if (StrList1 == NULL && StrList2 == NULL)
    {
        return 0;
    }
    if (StrList1 == NULL || StrList2 == NULL)
    {
        return -1;
    }
    if (StrList_size(StrList1) != StrList_size(StrList2))
    {
        return -1;
    }
    Node *p1 = StrList1->_head;
    Node *p2 = StrList1->_head;
    while (p1 != NULL && p2 != NULL)
    {
        if (strcmp(p1->data, p2->data) != 0)
        {
            return -1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    // after run on all the nodes and found p1==p2==null the two lists are equal.
    if (p1 == NULL && p2 == NULL)
    {
        return 0;
    }
    return -1;
}
StrList *StrList_clone(const StrList *StrList) 
{

    if (StrList == NULL || StrList->_head == NULL)
    {
        return NULL;
    }
    struct _StrList *str_copy = StrList_alloc();

    if (str_copy == NULL)
    {
        return NULL; // Memory allocation failed
    }
    Node *current = StrList->_head;
    Node *current_copy = str_copy->_head;

    while (current != NULL)
    {
        current_copy = Node_alloc(current->data, current->next);
        current_copy = current_copy->next;
        current = current->next;
    }

    return str_copy;
}

void StrList_reverse(StrList *StrList)
{
    if (StrList == NULL || StrList->_head == NULL)
    {
        return;
    }

    Node *pre = NULL;
    Node *current = StrList->_head;
    Node *next;
    while (current != NULL)
    {
        next = current->next; // 2               3           4                    5
        current->next = pre;  // 1->null       2->1->null     3->2->1->null     4->3->2->1->null
        pre = current;        // null to 1         1 to 2      2 to 3           3 to 4
        current = next;       // 1 to 2             2 to 3     3 to 4            4 to 5
    }
    StrList->_head = pre;
}
void StrList_sort(StrList *StrList)
{
      if (StrList == NULL || StrList->_head == NULL)
    {
        return; // No need to sort an empty list or a list with only one node
    }

    // Flag to indicate whether a swap occurred during the last iteration
    //int swapped;
    do
    {
        Node *pre = StrList->_head;
        Node *current = pre->next;
       // swapped = 0; // Initialize the flag to 0

        while (current != NULL)
        {
            if (strcmp(pre->data, current->data) > 0)
            {
                StrList_swap(&pre, &current);
                //swapped = 1; // Set the flag to 1 indicating a swap occurred
            }

            pre = current;
            current = current->next;
        }
    } while (!StrList_isSorted(StrList)); // Continue sorting until no swaps occur
}


void StrList_swap(Node** node1, Node** node2) {
    char* tmp = (*node1)->data;
    (*node1)->data = (*node2)->data;
    (*node2)->data = tmp;





}
int StrList_isSorted(StrList *StrList)
{

    if (StrList == NULL || StrList->_head == NULL)
    {             /// chack big letter
        return 0; // Not sorted if list is empty or NULL
    }
    Node *p1 = StrList->_head;
    Node *p2 = p1->next;
    while (p2 != NULL)
    {
        if (strcmp(p1->data, p2->data) > 0)
        {
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1;
}
