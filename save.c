#include<stdio.h>
#include"main.h"
#include<string.h>
int save(m_node *arr[])
{
    char file[20];
    printf("Enter the file name : ");
    scanf("%s",file);
    if(strstr(file,".txt") == NULL)
    {
        printf("ERROR: Entered file is not a .txt File\n");
        return FAILURE;
    }
    FILE *fptr = fopen(file,"w");
    if(fptr == NULL)
    {
        printf("ERROR: FILE was not opened\n");
        return FAILURE;
    }
    for(int i=0;i<27;i++)
    {
        m_node *temp = arr[i];
        while(temp != NULL)
        {
            fprintf(fptr,"#%d;%s;%d;",i,temp -> Word,temp -> file_count);
            s_node *t1 = temp -> s_link;
            while(t1 != NULL)
            {
                fprintf(fptr,"%s;%d;#",t1 -> f_name,t1 -> word_count);
                t1 = t1 -> s_link;
            }
            temp = temp -> m_link;
            fprintf(fptr,"\n");

        }
    }
    return SUCCESS;
}
