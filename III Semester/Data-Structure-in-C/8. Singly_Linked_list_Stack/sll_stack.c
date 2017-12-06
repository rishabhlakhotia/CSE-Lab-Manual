// C Program to implement Singly Linked List using stack principles.

#include <stdio.h>
#include <alloc.h>
#include <conio.h>

//Define Structures
struct sll {
    int info;
    struct sll * nxt;
};

int ch, item;

//Define Function to insert in the rear
struct sll * insert_rear(struct sll *f) {
    struct sll *t, *p;
    t = (struct sll * ) malloc(sizeof(struct sll));
    printf("enter the information");
    scanf("%d", &item);
    t -> info = item;
    t -> nxt = NULL;
    if (f == NULL)
        return t;
    else {
        p = f;
        while (p -> nxt != NULL) {
            p = p -> nxt;
        }
        p -> nxt = t;
    }
    return f;
}

// Function to delete in the rear
struct sll * delete_rear(struct sll *f) {
    struct sll *c, *p;
    if (f == NULL) {
        printf("List Empty");
        return f;
    }
    if (f -> nxt == NULL) //only one node present
    {
        printf("Item deleted is %d", f -> info);
        free(f);
        return NULL;
    }
    //many nodes so traverse until NULL
    p = NULL;
    c = f;
    while (c -> nxt != NULL) {
        p = c;
        c = c -> nxt;
    }
    printf("Item Deleted is %d", c -> info);
    free(c);
    p -> nxt = NULL;
    return f;
}

//Funtion to display list
void display (struct sll *f) {
    struct sll *t;
    if (f == NULL)
        printf("Empty List");
    t = f;
    while (t -> info != NULL) {
        printf("%d\t", t -> info);
        t = t -> nxt;
    }
}

// Main Function
void main() {
    struct sll *f = NULL;
    int cou;
    clrscr();
    for (;;) {
        printf("\n1.PUSH \n2.POP\n3.Display\n 4..Exit\n");
        printf("Enter choice");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            f = insert_rear(f);
            break;
        case 2:
            f = delete_rear(f);
            break;
        case 3:
            display(f);
            break;
        default:
            exit(0);
        }
    }
}
