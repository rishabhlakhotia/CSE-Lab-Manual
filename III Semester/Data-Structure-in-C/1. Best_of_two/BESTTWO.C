// Program to get the average of  two largest numbers
#include <stdio.h>
#include <conio.h>

void main() {
    int a[100], n, i, l1, l2 = -999;
    float avg;

    clrscr();
    printf("Enter the number of elements\n");
    scanf("%d", &n);

    // Retrieving array
    printf("\nEnter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    l1 = a[0];

    // Checking for largest and second largest numbers
    for (i = 1; i < n; i++) {
        if (a[i] > l1)
            l1 = a[i];
    }

    l2 = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > l2 && l1 != a[i])
            l2 = a[i];
    }

    // Calculating average and printing it
    printf("Largest Number is: %d\nSecond largest Number is: %d", l1, l2);
    avg = (float)(l1 + l2) / 2;
    printf("\nAverage of Best two Number is: %f", avg);
    getch();

}
