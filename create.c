#include"main.h"
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int create_db(m_node *arr[],Flist *head)
{
    for(int i=0;i<26;i++)
    {
	if(arr[i] != NULL)
	{
	    printf("DATABASE already exists\n");
	    return FAILURE;
	}
    }
    char word[20];
    int index;
    FILE *fptr;
    int m_flag=0,s_flag=0;
    while(head != NULL)
    {
        char word[20];
        int index;
        fptr = fopen(head -> file_name,"r");
        if(fptr == NULL)
            return FAILURE;
        while(fscanf(fptr,"%s",word) != EOF)
        {
            if(word[0] >='a' && word[0] <= 'z' || word[0] >= 'A' && word[0] <= 'Z')
            {
                index = tolower(word[0]) - 97;
            }
            else
                index = 26;
            if(arr[index] == NULL)
            {
                m_node *new_main = malloc(sizeof(m_node));
                if(new_main == NULL)
                {
                    printf("Memory Allocation Failure For Main Node\n");
                    return FAILURE;
                }
                s_node *new_sub = malloc(sizeof(s_node));
                if(new_sub == NULL)
                {
                    printf("Memory Allocation Failure For Subnode\n");
                    return FAILURE;
                }
                new_main -> file_count = 1;
                new_main -> m_link = NULL;
                new_main -> s_link = new_sub;
                strcpy(new_main -> Word,word);

                new_sub -> word_count = 1;
                new_sub -> s_link =NULL;
                strcpy(new_sub -> f_name,head -> file_name);
                arr[index] = new_main;
                continue;
            }
            else
            {
                m_node *temp = arr[index],*prev;
                prev = temp;
                while(temp != NULL)
                {
                    if(strcmp(temp -> Word,word) == 0)
                    {
                        s_node *t1 = temp -> s_link,*p1;
                        p1 = t1;
                        while(t1 != NULL)
                        {
                            if(strcmp(t1 -> f_name,head -> file_name) == 0)
                            {
                                (t1 -> word_count)++;
                                break;
                            }


                            p1 = t1;
                            t1 = t1 -> s_link;
                        }
                        if(t1 == NULL)
                        {

                            s_node *new_sub = malloc(sizeof(s_node));
                            if(new_sub == NULL)
                                return FAILURE;
                            new_sub -> word_count = 1;
                            new_sub -> s_link = NULL;
                            strcpy(new_sub -> f_name,head -> file_name);
                            p1 -> s_link = new_sub;
                            (temp -> file_count)++;
                        }
                        break;
                    }
                    prev = temp;
                    temp = temp -> m_link;
                }
                if(temp == NULL)
                {
                    m_node *new_main = malloc(sizeof(m_node));
                    s_node *new_sub = malloc(sizeof(s_node));
                    if(new_sub == NULL)
                        return FAILURE;
                    if(new_main == NULL)
                        return FAILURE;
                    new_main -> file_count = 1;
                    new_main -> m_link = NULL;
                    new_main -> s_link = new_sub;
                    strcpy(new_main -> Word,word);
                    new_sub -> s_link = NULL;
                    new_sub -> word_count = 1;
                    strcpy(new_sub -> f_name,head -> file_name);
                    prev -> m_link = new_main;
                }
            }
        }
        head = head -> link;

    }
    return SUCCESS;
}
