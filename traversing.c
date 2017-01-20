#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *left , *right;
} node;

node *creat(void);
void preorder_traversal(node *tree);
void inorder_traversal(node *tree);
void postorder_traversal(node *tree);

void main() {
    node *binary_tree;
    int choice;

    binary_tree = creat();

    do {
        printf("\n*****Menu*****\n");
        printf("1. Inorder traversal\n2. Preorder traversal\n3. Postorder traversal\n4. Exit\n");
        scanf("%d" , &choice);

        switch (choice) {
            case 1 :printf("Inorder traversal : \n"); 
                    inorder_traversal(binary_tree);
            break;

            case 2 :printf("Preorder traversal : \n"); 
                    preorder_traversal(binary_tree);
            break;

            case 3 :printf("Postorder traversal : \n"); 
                    postorder_traversal(binary_tree);
            break;

            case 4 : printf("Visit again\n");
            break;

            default : printf("Invalid option\n");
            break; 
        }
    } while (choice != 4);
}

node *creat() {
    node *root;
    int number;

    printf("Enter a data ( Note : -1 for no data ) :\n");
    scanf("%d" , &number);

    if ( number == -1 ) {
        return NULL;
    } else {
        root = (node*)malloc(sizeof(node));
        root->data = number;
      }

    printf("Enter the left child of %d : \n" , number);

    root->left = creat();
    
    printf("Enter the right child of %d : \n" , number);

    root->right = creat();

    return root;

}

void preorder_traversal(node *tree) {
    if (tree != NULL) {
        printf("%d\n" , tree->data );
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
    }
}

void inorder_traversal(node *tree) {
    if (tree != NULL) {
        inorder_traversal(tree->left);
        printf("%d\n" , tree->data);
        inorder_traversal(tree->right);
    }
}

void postorder_traversal(node *tree) {
    if (tree != NULL) {
        postorder_traversal(tree->left);
        postorder_traversal(tree->right);
        printf("%d\n" , tree->data);
    }
}