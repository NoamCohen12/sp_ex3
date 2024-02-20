#include "StrList.h"
#include <stdio.h>
int main()
{
    struct _StrList *user_list = StrList_alloc();
    int choice ;

   
    scanf("%d", &choice);
    
    while (choice)
    {
        if (choice == 1)
        {
            printf("in 1\n");
            int num_of_words = 0;
            scanf("%d", &num_of_words);
            printf("done num_of_words\n");
            for (size_t i = 0; i < num_of_words; i++)
            {
                char String[100];
                scanf("%s", String);
                StrList_insertLast(user_list, String);
                
            }
            printf("done 1\n");
        }
        if (choice == 2)
        {
             int index = 0;
            scanf("%d", &index);
            char String[100];
            scanf("%s", String);
            StrList_insertAt(user_list, String,index);
        }
        if (choice == 3)
        {
            StrList_print(user_list);
            printf("\n");
        }
        if (choice == 4)
        {
            int len = StrList_printLen(user_list);
            printf("%d", len);
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
            int size = StrList_size(user_list);
            printf("%d", size);
        }
        if (choice == 7)
        {
            char String[100];
            scanf("%s", String);
            StrList_count(user_list, String);
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
            printf("true");
        }
            scanf("%d", &choice);

    }
    return 0;
}