#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE getnode() {
    NODE temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

void insert(NODE root, NODE temp) {
    if (temp->info < root->info) {
        if (root->llink == NULL) {
            root->llink = temp;
        } else {
            insert(root->llink, temp);
        }
    } else if (temp->info > root->info) {
        if (root->rlink == NULL) {
            root->rlink = temp;
        } else {
            insert(root->rlink, temp);
        }
    }
}

void search(NODE root, int key) {
    if (root == NULL) {
        printf("\nSearch Unsuccessful\n");
    } else if (key == root->info) {
        printf("\nSearch Success. Item %d Found\n", key);
    } else if (key < root->info) {
        search(root->llink, key);
    } else {
        search(root->rlink, key);
    }
}

void inorder(NODE temp) {
    if (temp != NULL) {
        inorder(temp->llink);
        printf("%d\t", temp->info);
        inorder(temp->rlink);
    }
}

void preorder(NODE temp) {
    if (temp != NULL) {
        printf("%d\t", temp->info);
        preorder(temp->llink);
        preorder(temp->rlink);
    }
}

void postorder(NODE temp) {
    if (temp != NULL) {
        postorder(temp->llink);
        postorder(temp->rlink);
        printf("%d\t", temp->info);
    }
}

int main() {
    int ch, key, i, n;
    NODE temp, root;

    root = NULL;
    printf("\nProgram for BST\n");

    while (1) {
        printf("\n1: Insert\n2: Search\n3: Traversal\n4: Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number of elements: \n");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (i = 0; i < n; i++) {
                    temp = getnode();
                    scanf("%d", &temp->info);
                    if (root == NULL) {
                        root = temp;
                    } else {
                        insert(root, temp);
                    }
                }
                break;
            case 2:
                printf("\nEnter the Element to be Searched: \t");
                scanf("%d", &key);
                search(root, key);
                break;
            case 3:
                if (root == NULL) {
                    printf("\nTree is not created");
                } else {
                    printf("\nThe Inorder Traversal\n");
                    inorder(root);
                    printf("\nThe Preorder Traversal\n");
                    preorder(root);
                    printf("\nThe Postorder Traversal\n");
                    postorder(root);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
