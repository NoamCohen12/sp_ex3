#include <stdio.h>
#include "StrList.h"
#include <string.h>
#include <stdlib.h> // Added for malloc and free

// Define a node structure
typedef struct _node
{
    char *data;
    struct _node *next;
} Node;

// Define a structure for the string list
struct _StrList
{
    Node *_head;  // Pointer to the head of the list
    size_t _size; // Size of the list
};

// Allocate memory for a new node
Node *Node_alloc(const char *data, Node *next)
{
    Node *p = (Node *)malloc(sizeof(Node)); // Allocate memory for the node
    p->data = strdup(data);                 // Copy the data into the node
    p->next = next;                         // Set the next pointer
    return p;
}

// Allocate memory for a new StrList structure
StrList *StrList_alloc()
{
    StrList *p = (StrList *)malloc(sizeof(StrList)); // Allocate memory for the StrList
    if (p == NULL)
    {
        return NULL; // Allocation failed
    }
    p->_head = NULL; // Initialize head to NULL as the list is initially empty
    p->_size = 0;    // Initialize size to 0
    return p;
}

// Free memory allocated for the StrList and its nodes
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
        free(p2->data); // Free memory allocated for data
        free(p2);       // Free memory allocated for the node
    }
    free(StrList); // Free memory allocated for the StrList structure
}

// Get the size of the StrList
size_t StrList_size(const StrList *StrList)
{
    return StrList->_size;
}

// Insert a new node at the end of the StrList
void StrList_insertLast(StrList *StrList, const char *data)
{
    Node *p1 = StrList->_head;
    Node *new_node = Node_alloc(data, NULL); // Create a new node with the given data
    if (new_node == NULL)
    {
        // Handle memory allocation failure
        return;
    }
    if (p1 == NULL)
    {
        // List is empty, set the new node as the head
        new_node->next = NULL;
        StrList->_head = new_node;
        StrList->_size++;
        return;
    }

    // Traverse the list to find the last node
    while (p1->next != NULL)
    {
        p1 = p1->next;
    }
    // Insert the new node at the end of the list
    new_node->next = NULL;
    p1->next = new_node;
    StrList->_size++;
}

// Insert a new node at the specified index of the StrList
void StrList_insertAt(StrList *StrList, const char *data, int index)
{
    Node *p1 = StrList->_head;
    Node *p2 = NULL;
    int count = 0;

    Node *new_node = Node_alloc(data, NULL); // Create a new node with the given data
    if (new_node == NULL)
    {
        return; // Handle memory allocation failure
    }

    if (index == 0)
    {
        // Insert at the beginning of the list
        new_node->next = StrList->_head;
        StrList->_head = new_node;
        StrList->_size++;
        return;
    }
    if (StrList->_size == index)
    {
        // Insert at the end of the list
        StrList_insertLast(StrList, data);
        // we update the list size in "StrList_insertLast"
        return;
    }
    // Insert at the specified index
    while (p1 != NULL && count < index)
    {
        p2 = p1;
        p1 = p1->next;
        count++;
    }
    new_node->next = p1;
    p2->next = new_node;
    StrList->_size++;
}

// Get the data of the first node in the StrList
char *StrList_firstData(const StrList *StrList)
{
    return StrList->_head->data;
}

// Print all nodes of the StrList
void StrList_print(const StrList *StrList)
{
    if (StrList == NULL || StrList->_head == NULL)
    {
        return;
    }

    Node *current = StrList->_head;
    while (current->next != NULL)
    {
        printf("%s ", current->data);
        current = current->next;
    }
     printf("%s", current->data);
}

// Print the data of the node at the specified index
void StrList_printAt(const StrList *StrList, int index)
{
    if (StrList == NULL || StrList->_head == NULL || index < 0)
    {
        return;
    }

    Node *current = StrList->_head;
    int count = 0;

    while (current != NULL)
    {
        if (count == index)
        {
            printf("%s",current->data);
            return;
        }
        current = current->next;
        count++;
    }
}

// Calculate the total length of all strings in the StrList
int StrList_printLen(const StrList *Strlist)
{
    int sum_of_lengths = 0;
    if (Strlist == NULL || Strlist->_head == NULL)
    {
        return 0; // Return 0 if the list is empty or NULL
    }
    else
    {
        Node *current = Strlist->_head;
        while (current != NULL)
        {
            sum_of_lengths = sum_of_lengths + strlen(current->data); // Accumulate the length of each string
            current = current->next;                                 // Move to the next node
        }
    }
    return sum_of_lengths; // Return the total length of all strings
}

// Count occurrences of a specific string in the StrList
int StrList_count(StrList *StrList, const char *data)
{
    int count = 0;
    Node *current = StrList->_head;
    while (current != NULL)
    {
        // Check if the current node's data matches the specified string
        if (strcmp(current->data, data) == 0)
        {
            count++; // Increment count if a match is found
        }
        current = current->next; // Move to the next node
    }
    return count; // Return the count of occurrences
}

// Remove nodes with matching data from the StrList
void StrList_remove(StrList *StrList, const char *data)
{
    if (StrList == NULL || StrList->_head == NULL)
    {
        return; // Return if the list is empty or NULL
    }
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
                pre->next = current->next; // Link the previous node to the next node, skipping the current node
            }
            Node *temp = current;
            current = current->next; // Move to the next node before freeing memory
            StrList->_size--;        // Decrement the size of the list
            free(temp->data);        // Free memory allocated for the data
            free(temp);              // Free memory allocated for the node
        }
        else
        {
            pre = current;           // Move the previous pointer
            current = current->next; // Move to the next node
        }
    }
}

// Remove node at the specified index from the StrList
void StrList_removeAt(StrList *StrList, int index)
{
    if (StrList == NULL || StrList->_head == NULL || index < 0)
    {
        return; // Return if the list is empty, NULL, or if the index is negative
    }
    if (StrList->_head->next == NULL && index != 0)
    {
        return; // Return if index is out of bounds for a list with only one node
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
                pre->next = current->next; // Link the previous node to the next node, skipping the current node
            }
            StrList->_size--;    // Decrement the size of the list
            free(current->data); // Free memory allocated for the data
            free(current);       // Free memory allocated for the node
            return;
        }
        count++;
        pre = current;           // Move the previous pointer
        current = current->next; // Move to the next node
    }
}

// Check if two StrLists are equal
int StrList_isEqual(const StrList *StrList1, const StrList *StrList2)
{
    if (StrList1 == NULL && StrList2 == NULL)
    {
        return 0; // Both lists are NULL, considered equal
    }
    if (StrList1 == NULL || StrList2 == NULL)
    {
        return -1; // One list is NULL while the other is not, considered unequal
    }
    if (StrList_size(StrList1) != StrList_size(StrList2))
    {
        return -1; // Lists have different sizes, considered unequal
    }
    Node *p1 = StrList1->_head;
    Node *p2 = StrList2->_head;
    while (p1 != NULL && p2 != NULL)
    {
        if (strcmp(p1->data, p2->data) != 0)
        {
            return -1; // Data at current nodes is not equal, lists are unequal
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    // After traversing both lists, if both pointers are NULL, the lists are equal
    if (p1 == NULL && p2 == NULL)
    {
        return 0;
    }
    return -1; // Otherwise, lists are unequal
}

// Clone a StrList
StrList *StrList_clone(const StrList *StrList)
{
    if (StrList == NULL || StrList->_head == NULL)
    {
        return NULL; // Return NULL if the input list is NULL or empty
    }
    struct _StrList *str_copy = StrList_alloc(); // Allocate memory for the new list

    if (str_copy == NULL)
    {
        return NULL; // Memory allocation failed, return NULL
    }
    Node *current = StrList->_head;
    Node *current_copy = str_copy->_head;

    // Traverse the original list and copy each node to the new list
    while (current != NULL)
    {
        current_copy = Node_alloc(current->data, current->next);
        current_copy = current_copy->next;
        current = current->next;
    }

    return str_copy; // Return the cloned list
}

// Reverse the order of nodes in a StrList
void StrList_reverse(StrList *StrList)
{
    if (StrList == NULL || StrList->_head == NULL)
    {
        return; // Return if the list is empty or NULL
    }

    Node *pre = NULL;
    Node *current = StrList->_head;
    Node *next;
    // Iterate through the list and reverse the pointers of each node
    while (current != NULL)
    {
        next = current->next; // 2               3           4                    5
        current->next = pre;  // 1->null       2->1->null     3->2->1->null     4->3->2->1->null
        pre = current;        // null to 1         1 to 2      2 to 3           3 to 4
        current = next;       // 1 to 2             2 to 3     3 to 4            4 to 5
    }
    StrList->_head = pre; // Update the head pointer to point to the last node, which is now the first node
}
// Swap data between two nodes
void StrList_swap(Node **node1, Node **node2)
{
    char *tmp = (*node1)->data;
    (*node1)->data = (*node2)->data;
    (*node2)->data = tmp;
}
// Sort a StrList in ascending order
void StrList_sort(StrList *StrList)
{
    if (StrList == NULL || StrList->_head == NULL)
    {
        return; // No need to sort an empty list or a list with only one node
    }

    // Perform bubble sort until the list is sorted
    do
    {
        Node *pre = StrList->_head;
        Node *current = pre->next;

        while (current != NULL)
        {
            if (strcmp(pre->data, current->data) > 0)
            {
                StrList_swap(&pre, &current); // Swap nodes if necessary to maintain ascending order
            }

            pre = current;
            current = current->next;
        }
    } while (!StrList_isSorted(StrList)); // Continue sorting until the list is sorted
}

// Check if a StrList is sorted in ascending order
int StrList_isSorted(StrList *StrList)
{
    if (StrList == NULL || StrList->_head == NULL)
    {
        return 1; // Not sorted if the list is empty or NULL
    }
    Node *p1 = StrList->_head;
    Node *p2 = p1->next;
    while (p2 != NULL)
    {
        if (strcmp(p1->data, p2->data) > 0)
        {
            return 0; // Return false if any adjacent elements are out of order
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1; // Return true if all elements are in ascending order
}