#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *left, *right;
} Node;

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->val = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *search(Node *root, int val1, int val2)
{
    Node *tmp = root;
    if (tmp == NULL)
    {
        return NULL;
    }
    else if (tmp->val < val1 && tmp->val < val2)
    {
        return search(tmp->right, val1, val2);
    }
    else if (tmp->val > val1 && tmp->val > val2)
    {
        return search(tmp->left, val1, val2);
    }
    return tmp;
}

Node *RECinsert(Node *root, int item)
{
    Node *new_node;
    if (root == NULL)
    {
        new_node = create_node(item);
        return new_node;
    }
    if (item < root->val)
    {
        root->left = RECinsert(root->left, item);
    }
    else if (item > root->val)
    {
        root->right = RECinsert(root->right, item);
    }
    free(new_node);
    return root;
}

Node *RECsearch_node(Node *root, int item)
{
    Node *temp_ptr = root;
    if (temp_ptr == NULL)
    {
        return temp_ptr;
    }
    if (temp_ptr->val == item)
    {
        return temp_ptr;
    }
    else if (item > temp_ptr->val)
    {
        temp_ptr = RECsearch_node(temp_ptr->right, item);
    }
    else if (item < temp_ptr->val)
    {
        temp_ptr = RECsearch_node(temp_ptr->left, item);
    }
}

void displayInorder(Node *root)
{
    if (root)
    {
        displayInorder(root->left);
        printf("%d ", root->val);
        displayInorder(root->right);
    }
}

int main()
{
    Node *head = NULL;
    int check = 0, val;
    printf("Enter the node data to fill in the tree & enter -1 to exit : ");
    while (check != -1)
    {
        scanf("%d", &val);
        check = val;
        if (check != -1)
        {
            if (RECsearch_node(head, val) != NULL)
            {
                printf("\nNode of value %d pre-exists skipping insertion.", val);
            }
            else
            {
                head = RECinsert(head, val);
                printf("\nNode of value %d inserted.", val);
            }
        }
    }
    printf("\nIn-order traversal : ");
    displayInorder(head);
    printf("\n");
    printf("\nEnter the 2 nodes to find the L.C.A of the nodes respectively : ");
    int n1,n2;  scanf("%d %d",&n1,&n2);
    printf("\nThe L.C.A of the 2 nodes %d & %d is : %d\n",n1,n2,(search(head,n1,n2))->val);
    return 0;
}