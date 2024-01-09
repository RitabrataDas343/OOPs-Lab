#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int val;
    struct node *lft,*rgt;
} Node;
Node* create_node(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->val = data;
    new_node->lft = new_node->rgt = NULL;
    return new_node;
}
int search(int arr[], int start, int end, int val)
{
    for(int i=end;i>=start;i--){
        if(arr[i]==val){
            return i;
        }
    }
}
Node* create_tree(int in[], int post[], int start, int end, int* lptr)
{
    if(start>end){
        return NULL;
    }
    Node* new_node = create_node(post[*lptr]);
    (*lptr)--;
    if(start==end){
        return new_node;
    }
    int searchVal = search(in,start,end,new_node->val);
    new_node->rgt = create_tree(in,post,searchVal+1,end,lptr);
    new_node->lft = create_tree(in,post,start,searchVal-1,lptr);
    return new_node;
}        

void displayPreorder(Node *root)
{
    if (root)
    {
        printf("%d ", root->val);
        displayPreorder(root->lft);
        displayPreorder(root->rgt);
    }
}

int main(void)
{
    Node* head = NULL;
    printf("\nEnter the size of the array : ");
    int n;  scanf("%d",&n);
    int arr[n], arr2[n];
    int last_ptr = n-1;
    printf("Enter the elements in inorder order : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the elements in postorder order : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr2[i]);
    }
    head = create_tree(arr,arr2,0,n-1,&last_ptr);
    printf("\nPost-order traversal : ");
    displayPreorder(head);
    printf("\n");
    return 0;   
}