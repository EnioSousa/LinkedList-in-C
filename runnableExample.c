#include "linkedList.h"
#include <stdio.h>

// This is only an example of use. There are no safety mechanism here

/**
 * @brief Create a Obj object to be used in the list.
 * the point here is to abstract. You can change the contents of the
 * object being save by altering the code bellow
 * 
 * @param value The variable to save, in our case it just a integer
 * @return void* Address to a new variable with the same iamge as the paramater
 */
void* createObj(int value) {
    int* n = (int*)malloc(sizeof(int));

    *n = value;

    return n;
}

/**
 * @brief Function deletes the object creates with the function
 * createObj/1
 * 
 * @param obj Object to delete
 */
void delObj(void* obj) {
    free(obj);
}

/**
 * @brief Functions print the object creates with the function
 * createObj/1
 * 
 * @param obj 
 */
void printObj(void* obj) {
    printf("%d\n", *(int*)obj);
}

/**
 * @brief Simple interface for you to test
 * 
 */
void interface() {
    printf("\n");
    printf("Press 1 to add integer at the beginning:\n");
    printf("Press 2 to add integer at the end:\n");
    printf("Press 3 to remove first integer:\n");
    printf("Press 4 to remove last integer:\n");
    printf("Press 5 to print full list:\n");
    printf("Press 6 to get first element:\n");
    printf("Press 7 to get last element:\n");
    printf("Press 8 to exist:\n");
}

int main(int argc, char** argv) {
    List* list = newList();

    int readValue;

    do {
        interface();

        int value;
        scanf("%d", &readValue);

        switch (readValue) {
        case 1:
            scanf("%d", &value);
            addFirst(list, createObj(value));
            break;
        case 2:
            scanf("%d", &value);
            addLast(list, createObj(value));
            break;
        case 3:
            delFirst(list, *delObj);
            break;
        case 4:
            delLast(list, *delObj);
            break;
        case 5:
            printList(list, *printObj);
            break;
        case 6:
            printObj(getFirst(list));
            break;
        case 7:
            printObj(getLast(list));
            break;
        default:
        }
    } while (readValue < 8);
}
