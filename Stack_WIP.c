#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int topStack = 0;

void stack_push(int *content, int input) {

    content[topStack]=input;
    topStack++;
}

void stack_pop(int *content) {
    topStack--;
    content[topStack]=0;
}

void stack_make_empty() {
    topStack = 0;

    //not sure if I should be including this
    //don't think it really matters because we can only play with the top
    // for (int i = 0; i < STACK_SIZE; ++i) {
    //     content[i]=0;
    // }
}

void stack_overflow(int *content) {

    int *temp_content = realloc(content, STACK_SIZE+100);
    if (temp_content!=NULL) {
        content = temp_content;
    }

}

bool stack_is_empty() {
    return topStack==0;
}

bool stack_is_full(int *content) {
    if (topStack<=STACK_SIZE) {
        return topStack == STACK_SIZE;
    }
    else {
        return topStack%100;
    }
}

int main() {



    int *content = malloc(sizeof(int) * STACK_SIZE);

}

// // initial stack overflow content
// char choice;
// printf("Stack is full, do you want to empty it?(y/n)");
// scanf(" %c", &choice);
//
// while (choice != 'y' && choice != 'n') {
//     printf("invalid input\n");
//     printf("Stack is full, do you want to empty it?(y/n)");
//     scanf(" %c", &choice);
// }
//
// if (choice == 'y') {
//     stack_make_empty();
// }
// else {
//
// }
