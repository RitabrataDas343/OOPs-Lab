#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node_init;
node_init* create(int val)
{
    node_init *new_node = (node_init*)malloc(sizeof(node_init));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}
void push_back(node_init **root, int data)
{
    node_init *new_node = create(data);
    if((*root)==NULL)
    {
        (*root) = new_node;
    }
    else {
        node_init *tmp = *root;
        while(tmp->next!=NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}
void display(node_init **root)
{
    node_init *tmp = *root;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
void insertSort(node_init **root, int data)
{
    node_init *new_node = create(data);
    node_init *tmp = *root;
    if(tmp->data>data){
        new_node->next = *root;
        *root = new_node;
    } else {
        while((tmp->next->data)<data && tmp->next!=NULL){
            tmp = tmp->next;
        }
        new_node->next = tmp->next;
        tmp->next = new_node;
    }
}
void insertCheck(node_init **root)
{
    node_init *tmp = *root;
    node_init *prev = *root;
    while(tmp->next!=NULL){
        prev = tmp;
        tmp = tmp->next;
        if(prev->data>tmp->data)
        {
            prev->next = tmp->next;
            tmp->next = NULL;
            insertSort(root,tmp->data);
            prev = *root;
            tmp = *root;
        }
    }
}
int main()
{
    node_init *root = NULL;
    printf("\nEnter the amount of node to enter : ");
    int n;  scanf("%d",&n);
    printf("\nEnter the nodes : ");
    for(int i=0;i<n;i++)
    {
        int val;    scanf("%d",&val);
        push_back(&root,val);
    }
    printf("\nThe original array is : ");
    display(&root);
    insertCheck(&root);
    printf("\nThe sorted array is : ");
    display(&root);
    return 0;
}