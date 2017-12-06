// Program to find element in a Sparse matrix
#include <stdio.h>
#include <conio.h>

void main() {
    int i, j, p, q, a[10][10], k = 0, key;

    // Sparse matrix structure
    struct matrix {
        int r, c, v;
    }
    m[10];

    // Input the Sparse matrix
    printf("Enter no. of Rows &Cols: ");
    scanf("%d %d", &p, &q);
    printf("Enter the Matrix: ");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0) {
                m[k].r = i + 1;
                m[k].c = j + 1;
                m[k].v = a[i][j];
                k++;
            }
        }

    // printing the non-zero values
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++) {
            printf("%d", a[i][j]);
        }

    printf("_________________________________________");
    printf("\nRow\tColumn\tvalue\n");
    printf("_________________________________________");
    for (i = 0; i < k; i++) {
        printf("\n%d\t%d\t%d", m[k].r, m[k].c, m[k].v);
    }

    // taking in the key &Searching it
    printf("\n\nEnter the Search element: ");
    scanf("%d", &key);
    for (i = 0; i < k; i++) {
        if (key == m[i].v) {
            printf("\nResult found at loc: %d %d", m[i].r, m[i].c);
            getch();
        }
    }
    printf("\nResults not found");
    getch();
}
