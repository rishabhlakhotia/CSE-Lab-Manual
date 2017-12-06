#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 100

int a[SIZE], c;
void bst(int ele) {
    if (a[0] == NULL) {
        a[0] = ele;
        return;
    }
    c = 0;
    while (a[c] != NULL) {
        if (ele < a[c])
            c = 2 * c + 1;
        else
            c = 2 * c + 2;
    }
    a[c] = ele;
}

void display() {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (a[i] == NULL)
            continue;
        printf("a[%d]=%d\n", i, a[i]);
    }
}

void main() {
    int ch, i, j, ele;
    printf("\n1.bst\n2.display\n");
    for (;;) {
        printf("\nEnter choice\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            for (i = 0; i < SIZE; i++) a[i] = NULL;
            printf("\enter no of ele to enter\n");
            scanf("%d", &j);
            printf("\nEnter the array of elements\n");
            for (i = 0; i < j; i++) {
                scanf("%d", &ele);
                bst(ele);
            }
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        }
    }
}
