#include<stdio.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct main
{
    char Word[30];
    int file_count;
    struct main *m_link;
    struct sub *s_link;
}m_node;

typedef struct sub
{
    int word_count;
    char f_name[30];
    struct sub *s_link;
}s_node;

typedef struct node
{
    char *file_name;
    struct node *link;
}Flist;

int validate(int argc,char *argv[],Flist **head);
int create_db(m_node *arr[],Flist *f_list);
int display(m_node *arr[]);
int search(m_node *arr[]);
int save(m_node *arr[]);
int update(m_node *arr[]);
