#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
    Analysis : For a BST, the each search operation goes to a respective node and hence searchs for an
    element and height of a tree ranges from { log(n)<= H <= n } so time complexity ranges from
    [ O(log N) , O(N) ]
*/
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;
Node *create_node(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *RECsearch_node(Node *root, int item)
{
    Node *temp_ptr = root;
    if (temp_ptr == NULL)
    {
        return temp_ptr;
    }
    if (temp_ptr->data == item)
    {
        return temp_ptr;
    }
    else if (item > temp_ptr->data)
    {
        temp_ptr = RECsearch_node(temp_ptr->right, item);
    }
    else if (item < temp_ptr->data)
    {
        temp_ptr = RECsearch_node(temp_ptr->left, item);
    }
}

Node *RECinsert(Node *root, int item)
{
    Node *new_node;
    if (root == NULL)
    {
        new_node = create_node(item);
        return new_node;
    }
    if (item < root->data)
    {
        root->left = RECinsert(root->left, item);
    }
    else if (item > root->data)
    {
        root->right = RECinsert(root->right, item);
    }
    free(new_node);
    return root;
}

Node *ITERinsert(Node *root, int val)
{
    Node *p = root, *prev;
    Node *new_node = create_node(val);
    if (root == NULL)
    {
        root = new_node;
        return root;
    }
    while (p != NULL)
    {
        if (val < p->data)
        {
            prev = p;
            p = p->left;
        }
        else
        {
            prev = p;
            p = p->right;
        }
    }
    if (val < prev->data)
    {
        prev->left = new_node;
    }
    else
    {
        prev->right = new_node;
    }
    return root;
}

Node *deletion(Node *root, int item)
{
    Node *prev = root, *pos = root;
    while (pos->data != item && pos != NULL)
    {
        if (item < pos->data)
        {
            prev = pos;
            pos = pos->left;
        }
        else
        {
            prev = pos;
            pos = pos->right;
        }
    }
    if (pos->left == NULL && pos->right == NULL)
    {
        if (prev->left == pos)
        {
            prev->left = NULL;
        }
        else
        {
            prev->right = NULL;
        }
    }
    else if (pos->right == NULL)
    {
        Node *instant_node = pos->left;
        if (prev->left == pos)
        {
            prev->left = instant_node;
            pos->left = NULL;
        }
        else
        {
            prev->right = instant_node;
            pos->left = NULL;
        }
    }
    else if (pos->right != NULL)
    {
        Node *instant_node = pos;
        prev = pos;
        pos = pos->right;
        while (pos->left != NULL && pos->right != NULL)
        {
            instant_node = pos;
            pos = pos->left;
        }
        prev->data = pos->data;
        if (instant_node->left == pos)
        {
            instant_node->left = NULL;
        }
        else
        {
            instant_node->right = NULL;
        }
    }
    return root;
}

// Traversals Inorder / Postorder / Preorder
void displayInorder(Node *root)
{
    if (root)
    {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

void displayPreorder(Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

void displayPostorder(Node *root)
{
    if (root)
    {
        displayPostorder(root->left);
        displayPostorder(root->right);
        printf("%d ", root->data);
    }
}

int getDepth(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int ltree = getDepth(root->left);
    int rtree = getDepth(root->right);
    if (ltree > rtree)
        return ltree + 1;
    else
        return rtree + 1;
}

int main(void)
{
    int t = 1;
    Node *head = NULL;
    while (t)
    {
        printf("\n1. To fill in nodes in tree.");
        printf("\n2. To display tree.");
        printf("\n3. To search for nodes in tree.");
        printf("\n4. To delete a node in tree.");
        printf("\n5. To get depth of tree.");
        printf("\nEnter your choice : ");
        int ch;
        int check = 0, val;
        scanf("%d", &ch);
        int vl;
        switch (ch)
        {
            case 1:
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
                            head = ITERinsert(head, val);
                            printf("\nNode of value %d inserted.", val);
                        }
                    }
                }
                break;
            case 2:
                printf("\nPre-order traversal : ");
                displayPreorder(head);
                printf("\n");
                printf("\nIn-order traversal : ");
                displayInorder(head);
                printf("\n");
                printf("\nPost-order traversal : ");
                displayPostorder(head);
                printf("\n");
                break;
            case 3:
                printf("\nEnter a value to search : ");
                scanf("%d", &vl);
                if (RECsearch_node(head, vl) == NULL)
                {
                    head = RECinsert(head, vl);
                    printf("\n%d inserted as not found.", vl);
                }
                else
                {
                    printf("\nAddress for %d is => %p\n", vl, RECsearch_node(head, vl));
                }
                break;

            case 4:
                printf("\nEnter a value to delete : ");
                scanf("%d", &vl);
                head = deletion(head, vl);
                break;
            case 5:
                printf("\nMax depth of the tree is : %d\n", getDepth(head));
                break;
            default:
                printf("Wrong Choice.\n");
                break;
        }
        printf("\nEnter 1 to continue operations and 0 to exit : ");
        scanf("%d",&t);
    }
    return 0;
}