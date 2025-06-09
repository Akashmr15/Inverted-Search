#include"main.h"
#include<stdio.h>
int display(m_node *arr[])
{
    printf("[Index]\t Words\t File Count\t Filename\t Word count\t Filename\t Word Count\t Filename\t Word Count\n");
    printf("-------\t -----\t ----------\t --------\t ----------\t --------\t ----------\t --------\t ----------\n");
    for(int i=0;i<27;i++)
    {
        if(arr[i] != NULL)
        {
            m_node *temp = arr[i];
            while(temp != NULL)
            {
                printf("[%d]\t ",i);
                printf("%s\t ",temp -> Word);
                printf("%d\t\t ",temp -> file_count);
                s_node *t1 = temp -> s_link;
                while(t1 != NULL)
                {
                    printf("%s\t ",t1 -> f_name);
                    printf("   %d\t\t ",t1 -> word_count);
                    t1 = t1 -> s_link;
                }
                printf("\n");
                temp = temp -> m_link;
            }
        }
    }
}

