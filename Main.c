#include "StrList.h"
#include <stdio.h>

//allocate location for word with unkown size
char *string_input()
{
    int length = 10;
    char *string = (char *)malloc(length * sizeof(char));
    if (string == NULL)
    {
        printf("allocation failure");
    }
    int i = 0;
    char c;
    while (1)
    {
        c = getchar();
        if (c == ' ' || c == '\n' || c == EOF)
        {
            if (i == 0)
            {
                continue;
            }
            string[i] = '\0';
            break;
        }
        string[i] = c;
        i++;
        if (i >= length)
        {
            length *= 2;
            char *string_new = (char *)realloc(string, length * sizeof(char));
            string = string_new;
        }
    }
    return string;
}

int main()
{
    struct _StrList *user_list = StrList_alloc();
    int choice;
    char *string;

    // if the input is not one number
    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input\n");
    }
// if choice == 0 --> while --> false
    while (choice)
    {
        if (choice == 1)
        {
            int num_of_words = 0;
            scanf("%d", &num_of_words);
            for (size_t i = 0; i < num_of_words; i++)
            {
                string = string_input();
                StrList_insertLast(user_list, string);
                free(string);
            }
        }
        if (choice == 2)
        {
            int index = 0;
            scanf("%d", &index);
            string = string_input();
            StrList_insertAt(user_list, string, index);
            free(string);
        }
        if (choice == 3)
        {
            StrList_print(user_list);
            printf("\n");
        }
        if (choice == 4)
        {
            int len = StrList_size(user_list);
            printf("%d\n", len);
        }
        if (choice == 5)
        {
            int index = 0;
            scanf("%d", &index);
            StrList_printAt(user_list, index);
            printf("\n");
        }
        if (choice == 6)
        {
            int size = StrList_printLen(user_list);
            printf("%d\n", size);
        }
        if (choice == 7)
        {
            string = string_input();
            int count = StrList_count(user_list, string);
            printf("%d\n", count);
            free(string);
        }
        if (choice == 8)
        {
            string = string_input();
            StrList_remove(user_list, string);
            free(string);
        }
        if (choice == 9)
        {
            int index = 0;
            scanf("%d", &index);
            StrList_removeAt(user_list, index);
        }
        if (choice == 10)
        {
            StrList_reverse(user_list);
        }
        if (choice == 11)
        {
            StrList_free(user_list);
            user_list = StrList_alloc();
        }
        if (choice == 12)
        {
            StrList_sort(user_list);
        }
        if (choice == 13)
        {
            int result = StrList_isSorted(user_list);
            if (result == 0)
            {
                printf("false\n");
            }
            else
            {
                printf("true\n");
            }
        }
        // continue get input from user
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            break;
        }
    }
    return 0;
}