#include<stdio.h>
#include"main.h"
#include<string.h>
#include<ctype.h>
int search(m_node *arr[])
{
    char data[20];
    int index;
    printf("Enter the word : ");
    scanf("%s",data);
    if(data[0] >= 'a' && data[0] <= 'z' || data[0] >= 'A' && data[0] <= 'Z')
    {
        index = tolower(data[0]) - 97;
    }
    else
        index = 26;
    m_node *temp = arr[index];
    while(temp != NULL)
    {
        if(strcmp(temp -> Word,data) == 0)
        {
            printf("The word %s is in %d file \n",temp -> Word,temp -> file_count);
            s_node *t1 = temp -> s_link;
            while(t1 != NULL)
            {
                printf("In %s it is presented for %d time\n",t1 -> f_name,t1 -> word_count);
                t1 = t1 -> s_link;
            }
            return SUCCESS;
        }
        temp = temp -> m_link;
    }
    return FAILURE;
}
