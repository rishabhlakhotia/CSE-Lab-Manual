#include < stdio.h >
#include < conio.h >
#include < stdlib.h >

typedef struct tnode {
    int data;
    struct tnode * right, * left;
}TNODE;

TNODE * create_bst(TNODE * , int);
void inorder(TNODE * );
void preorder(TNODE * );
void postorder(TNODE * );

void main() {
    TNODE * root = NULL;
    int opn, elem, n, i;
    do {
        clrscr();
        printf("\nBinary Search Tree Operations\n\n");
        printf("1:Creation of bst\n2:Inorder\n3:Preorder\n4:Postorder\n5:exit");
        printf("\nEnter a choice: ");
        scanf("%d", &opn);
        switch (opn) {
        case 1:
            root = NULL;
            printf("\nBST for how many nodes?: ");
            scanf("%d", &n);
            for (i = 1; i < n + 1; i++) {
                printf("\nRead the data for the node %d? ", i);
                scanf("%d", &elem);
                root = create_bst(root, elem);
            }
            printf("\nBST with %d nodes is ready to use.\n", n);
            break;

        case 2:
            printf("\nBST Traversal in Inorder\n");
            inorder(root);
            break;

        case 3:
            printf("\nBST Traversal in Preorder\n");
            preorder(root);
            break;

        case 4:
            printf("\nBST Traversal in POSTORDER\n");
            postorder(root);
            break;

        case 5:
            printf("Terminating");
            break;

        default:
            printf("Invalid option");
        }
        printf("\nPress a key to continue.");
        getch();
    } while (opn != 5);
}

TNODE * create_bst(TNODE * root, int elem) {
    if (root == NULL) {
        root = (TNODE * ) malloc(sizeof(TNODE));
        root -> left = root -> right = NULL;
        root -> data = elem;
        return root;
    } else {
        if (elem < root -> data)
            root -> left = create_bst(root -> left, elem);
        else if (elem > root -> data)
            root -> right = create_bst(root -> right, elem);
        else
            printf("Duplicate element not allowed.");
        return root;
    }
}

void inorder(TNODE * root) {
    if (root != NULL) {
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root -> right);
    }
}

void preorder(TNODE * root) {
    if (root != NULL) {
        printf("%d ", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void postorder(TNODE * root) {
    if (root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ", root -> data);
    }
}
