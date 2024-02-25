#include "StrList.h"
#include <stdio.h>
int main()
{
    
    struct _StrList *user_list = StrList_alloc();
    int choice;

    scanf("%d", &choice);

    while (choice)
    {
        if (choice == 1)
        {
            int num_of_words = 0;
            scanf("%d", &num_of_words);
           // printf("%d", num_of_words);
            for (size_t i = 0; i < num_of_words; i++)
            {
                char String[100];
                scanf("%s", String);
                StrList_insertLast(user_list, String);
            }
        }
        if (choice == 2)
        {
            int index = 0;
            scanf("%d", &index);
            char String[100];
            scanf("%s", String);
            StrList_insertAt(user_list, String, index);
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
            char String[100];
            scanf("%s", String);
            int count = StrList_count(user_list, String);
            printf("%d\n" , count);
        }
        if (choice == 8)
        {
            char String[100];
            scanf("%s", String);
            StrList_remove(user_list, String);
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
                printf("true");
            }
        }
        scanf("%d", &choice);
    }
    return 0;
}