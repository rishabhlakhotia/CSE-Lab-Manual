#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <process.h>
struct node {
    int info;
    struct node * llink, * rlink;
};
struct node * root = NULL;

void insfront() {
    struct node * temp;
    temp = (struct node * ) malloc(sizeof(struct node));
    printf("Enter the item\n");
    scanf("%d", & temp -> info);
    temp -> llink = NULL;
    temp -> rlink = NULL;
    if (root == NULL)
        root = temp;
    else {
        temp -> rlink = root;
        root -> llink = temp;
        root = temp;
    }
}

void inskey() {
    struct node * temp, * cur, * prev;
    int key, flag = 0;
    if (root == NULL)
        printf("list is empty\n");
    else {
        printf("enter key\n");
        scanf("%d", & key);
        if (key == root -> info) {
            flag = 1;
            insfront();
        } else {
            cur = root;
            while (cur != NULL) {
                if (key == cur -> info) {
                    flag = 1;
                    temp = (struct node * ) malloc(sizeof(struct node));
                    printf("enter the item\n");
                    scanf("%d", & temp -> info);
                    prev = cur -> llink;
                    prev -> rlink = temp;
                    temp -> llink = prev;
                    cur -> llink = temp;
                    temp -> rlink = cur;
                }
                cur = cur -> rlink;
            }
        }
        if (flag != 1)
            printf("key not found\n");
    }
}

void delkey() {
    struct node * prev, * cur, * nxt;
    int flag = 0, key;
    if (root == NULL)
        printf("list is empty\n");
    else {
        cur = root;
        printf("enter the item to be deleted\n");
        scanf("%d", & key);
        if (cur == root && cur -> info == key) {
            flag = 1;
            root = root -> rlink;
            root -> llink = NULL;
            free(cur);
        } else {
            while (cur != NULL) {
                if (cur -> info == key) {
                    flag = 1;
                    prev = cur -> llink;
                    nxt = cur -> rlink;
                    prev -> rlink = nxt;
                    nxt -> llink = prev;
                    cur -> llink = NULL;
                    cur -> rlink = NULL;
                    free(cur);
                }
                cur = cur -> rlink;
            }
        }
        if (flag == 1)
            printf("\nitem %d is deleted\n", key);
        else
            printf("item not found\n");
    }
}

void display() {
    struct node * temp;
    if (root == NULL)
        printf("list empty\n");
    else {
        temp = root;
        while (temp != NULL) {
            printf("%d\t", temp -> info);
            temp = temp -> rlink;
        }
    }
}

void main() {
    int ch;
    clrscr();
    for (;;) {
        printf("\n1.insert front\n2.insert before key\n3.delete from key\n4.display\n5.exit\n");
        printf("enter ur choice\n");
        scanf("%d", & ch);
        switch (ch) {
        case 1:
            insfront();
            break;
        case 2:
            inskey();
            break;
        case 3:
            delkey();
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }
}
