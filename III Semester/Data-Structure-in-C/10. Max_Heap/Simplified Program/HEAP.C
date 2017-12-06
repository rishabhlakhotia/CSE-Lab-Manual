#include <stdio.h>
#include <conio.h>
#define MAX_SIZE 100

int heap[MAX_SIZE];
int n = 0;

void createHeap(int item) {
    int c, p;
    if (n == MAX_SIZE)
        printf("Heap is full\n");
    else {
        c = n;
        p = (c - 1) / 2;
        while (c != 0 && item > heap[p]) {
            heap[c] = heap[p];
            c = p;
            p = (c - 1) / 2;
        }
        heap[c] = item;
        n++;
    }
}

void main() {
    int item, ch, i;
    clrscr();
    while (1) {
        printf("1. create\t2. display : ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter Item in heap\n");
            scanf("%d", &item);
            createHeap(item);
            break;
        case 2:
            for (i = 0; i <= n; i++)
                printf("Heap[%d] = %d", i, heap[i]);
            break;
        default:
            exit(0);
        }
    }
    getch();
}
