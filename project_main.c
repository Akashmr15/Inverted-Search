#include"main.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    if(argc < 2)
    {
        printf("ERROR : Pass Valid CLA\n");
	printf("./a.out f1.txt f2.txt f3.txt...\n");
        return 0;
    }
    Flist *f_list = NULL;
    m_node *arr[27] = {NULL};
    if(validate(argc,argv,&f_list) == SUCCESS)
        printf("Files are successfully validated \n");
    else
    {
        printf("ERROR : Files Validation Unsuccesfull\n");
        return FAILURE;
    }
    printf("Choose Your Option:\n");
    printf("1.Create DATABASE\n2.Display DATABASE\n3.Update DATABASE\n4.Save DATABASE\n5.Search\n6.Exit\n");
    while(1)
   {
    int option;
    printf("Enter your choice : ");
    scanf("%d",&option);
        switch(option)
        {
            case 1:
                if(create_db(arr,f_list) == SUCCESS)
                {
                    printf("Database Created Successfully\n");
                }
                else
                {
                    printf("ERROR : Database Not Created\n");
                   // return FAILURE;
                }
                break;
            case 2:
                if(display(arr) == SUCCESS)
                {
                }
                else
                {
                    printf("ERROR: Display Database Unsuccessfull\n");
                   // return FAILURE;
                }
                break;
           case 3:
                if(update(arr) == SUCCESS)
                {
                    printf("DATABASE are updated successfully\n");
                }
                else
                {
                    printf("ERROR: DATABASE are not updated successfully\n");
                }
                break;
            case 4:
                if(save(arr) == FAILURE)
                {
                    printf("ERROR: Database Unsaved\n");
                }
                break;
            case 5:
                if(search(arr) == FAILURE)
                {
                    printf("Entered Word Not Found\n");
                }
                break;
            case 6:
                return 0;
        }
    }

    Flist *temp = f_list;
    printf("f_list->");
    while(temp != NULL)
    {
        printf(" %s -> ",temp -> file_name);
        temp = temp -> link;
    }
    printf("NULL\n");

}
int validate(int argc,char *argv[],Flist **f_list)
{
    for(int i=1;i<argc;i++)
    {
        if(strstr(argv[i],".txt") == NULL)
        {
            printf("ERROR : %s is not a .txt file, Pass .txt File\n",argv[i]);
            continue;
        }
        FILE *fptr = fopen(argv[i],"r");
        if(fptr == NULL)
        {
            printf("ERROR: File not created\n");
            continue;
        }
        fseek(fptr,0,SEEK_END);
        int len = ftell(fptr);
        if(len < 2)
        {
            printf("ERROR : %s is an empty file\n",argv[i]);
            continue;
        }
        if(*f_list == NULL)
        {

            Flist *new = malloc(sizeof(Flist));
            if(new == NULL)
                return FAILURE;
            new -> file_name = argv[i];
            new -> link == NULL;
            *f_list = new;
        }
        else
        {
            Flist *temp =*f_list,*prev;
            while(temp != NULL)
            {
                if(strcmp(temp -> file_name,argv[i]) == 0)
                {
                    printf("ERROR: %s already existed\n",argv[i]);
                    break;
                }
                prev = temp;
                temp = temp -> link;
            }
            if(temp == NULL)
            {
                Flist *new = malloc(sizeof(Flist));
                if(new == NULL)
                    return FAILURE;
                new -> file_name = argv[i];
                new -> link = NULL;
                prev -> link = new;
            }
        }
    }
    return SUCCESS;
}
