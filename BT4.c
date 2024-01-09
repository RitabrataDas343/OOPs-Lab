#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int g_count = 0, count = 0;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;
typedef struct queue 
{
    int front,rear,size;
    Node* *array;
} Queue;
Node* create_node(int value)
{
    Node* new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}
Queue* create_queue(int sz)
{
    Queue* qu = (Queue*)malloc(sizeof(Queue));
    qu->size = sz;
    qu->front = qu->rear = 0;
    qu->array = (Node**)malloc(sizeof(Node)*qu->size);
    return qu;
}

bool isEmpty(Queue* root)
{
    return root->front==root->rear;
}

bool isFull(Queue* root)
{
    return (root->rear+1)%root->size == root->front;
}

void enqueue(Queue* root, Node* val)
{
    root->rear = (root->rear+1)%root->size;
    root->array[root->rear] = val;
}

void dequeue(Queue* root)
{
    root->front = (root->front+1)%root->size;
}

Node* front(Queue *var){
    return var->array[var->front];
}

Node* rear(Queue *var){
    return var->array[var->rear];
}

Node *create()
{
    int x;
    char ch;
    Node *new_node;
    printf("Enter the value to insert in tree\n");
    scanf("%d", &x);
    new_node = (Node *)malloc(sizeof(Node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = x;
    if (count < g_count)
    {
        printf("\nDo you want to enter the left node of %d (Y/N) : ", x);
        scanf(" %c",&ch);
        if (ch == 'Y')
        {
            ++count;
            new_node->left = create();
        }
        else
        {
            new_node->left = NULL;
        }
    }
    else
    {
        new_node->left = NULL;
    }
    if (count < g_count)
    {
        printf("\nDo you want to enter the right node of %d (Y/N) : ", x);
        scanf(" %c", &ch);
        fflush(stdin);
        if (ch == 'Y')
        {
            ++count;
            new_node->right = create();
        }
        else
        {
            new_node->right = NULL;
        }
    }
    else
    {
        new_node->right = NULL;
    }
    return new_node;
}

void BFS_Traversal(Node* root, int sz)
{
    if(root==NULL){
        return;
    }
    Queue *qu = create_queue(sz);
    enqueue(qu,root);
    enqueue(qu,NULL);
    while(!isEmpty(qu))
    {
        Node* check = front(qu);
        dequeue(qu);
        if(check!=NULL){
            printf("%d ",check->data);
            if(check->left)
                enqueue(qu,check->left);
            if(check->right)
                enqueue(qu,check->right);
        } else if(!isEmpty(qu)) {
            enqueue(qu,NULL);
        }
    }
}


int main(void){
    printf("\nEnter the number of nodes to form : ");
    int num;
    scanf("%d", &num);
    num -= 1;
    g_count = num;
    Node* root;
    root = create();
    printf("\nThe Level Order Traversal of the tree : ");
    BFS_Traversal(root,num);
    printf("\n");
    return 0;
}