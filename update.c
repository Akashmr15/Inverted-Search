#include<stdio.h>
#include"main.h"
#include<string.h>
#include<stdlib.h>
int update(m_node *arr[])
{
    for(int i=0;i<27;i++)
    {
        if(arr[i] != NULL)
        {
            printf("Error: Database Already Exist\n");
            return FAILURE;
        }
    }
    char file[20],str[100];
    printf("Enter the file name : ");
    scanf("%s",file);
    if(strstr(file,".txt") == NULL)
    {
        printf("ERROR: Enter the valid file\n");
        return FAILURE;
    }
    FILE *fptr = fopen(file,"r");
    if(fptr == NULL)
    {
        printf("ERROR: File was not opened\n");
        return FAILURE;
    }
    char fch = fgetc(fptr);
    fseek(fptr,-2,SEEK_END);
    char lch = fgetc(fptr);
    rewind(fptr);
    if(fch == '#' && lch == '#')
    {
        printf("Entered File Is Backup File\n");

    }
    else
    {
        printf("ERROR: This File is Not Backup File\n");
        return FAILURE;
    }
    while(fscanf(fptr,"%s",str) != EOF)
    {
        int index = atoi(strtok(str,"#;"));
        m_node *new_main = malloc(sizeof(m_node));
        if(new_main == NULL)
        {
            printf("ERROR: Memory was not Allocated\n");
            return FAILURE;
        }
        if(arr[index] == NULL)
        {
            arr[index] = new_main;
        }
        else
        {
            m_node *temp = arr[index],*prev;
            while(temp != NULL)
            {
                prev = temp;
                temp = temp -> m_link;
            }
            prev -> m_link = new_main;
        }
        strcpy(new_main -> Word,strtok(NULL,"#;"));
        new_main -> file_count = atoi(strtok(NULL,"#;"));
        new_main -> m_link = NULL;
        int flag =0;
        for(int i =0;i<new_main -> file_count;i++)
        {
            s_node * new_sub = malloc(sizeof(s_node)),*p1;
            if(i > 0)
                p1 -> s_link = new_sub;
            if(new_sub == NULL)
            {
                printf("ERROR: Memory Was Not Allocated\n");
                return FAILURE;
            }
            if(flag == 0)
            {
                new_main -> s_link = new_sub;
                flag = 1;
            }
            strcpy(new_sub -> f_name,strtok(NULL,"#;"));
            new_sub -> word_count = atoi(strtok(NULL,"#;"));
            new_sub -> s_link = NULL;
            p1 = new_sub;
        }
    }
    return SUCCESS;
}
