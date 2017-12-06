#include <stdio.h>
#include <conio.h>
#include <process.h>

int a[100], n, i, root, c, temp, ch;

void createheap(int i) {
    if (i == 0) //location is zero
    {
        root = i;
        return;
    } else {
        c = i;
        while (c != 0) {
            root = (c - 1) / 2;
            if (a[root] <= a[c]) //parent is less than child swap
            {
                temp = a[root];
                a[root] = a[c];
                a[c] = temp;
            }
            c = root;
        }
    }
}

void display() {
    printf("Max heap\n ");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}

void main() {
    clrscr();
    for (;;) {
        printf("1. create Max Heap\n2. display\n3. exit\n");
        printf("enter ur choice\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("enter the number of nodes\n");
            scanf("%d", &n);
            printf("enter the elements\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &a[i]);
                createheap(i);
            }
            break;
        case 2:
            display();
            break;
        default:
            exit(0);
        }
    }
}
