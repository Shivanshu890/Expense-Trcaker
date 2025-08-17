
#include <stdio.h>
#include <stdlib.h>
#include "expense.h"

void remove_expense(Expense **expenses, int *count) {
    if (*count == 0) {
        printf("\t\t\t\t\t\tNo expenses to remove.\n");
        return;
    }
    printf("\t\t\t\t+-----+------------+-----------------+--------------------------+--------------------+\n");
    printf("\t\t\t\t| No. | Date       | Category        | Description              | Amount             |\n");
    printf("\t\t\t\t+-----+------------+-----------------+--------------------------+--------------------+\n");

    for (int i = 0; i < *count; i++) {
        printf(" \t\t\t\t| %-3d | %-10s | %-15s | %-24s | Rs %-7.1f         |\n",
            i + 1,
            (*expenses)[i].date,
            (*expenses)[i].category,
            (*expenses)[i].description,
            (*expenses)[i].amount);
    }
    printf("      \t\t\t\t+-----+------------+-----------------+--------------------------+--------------------+\n");

    int index;
    printf("\t\t\t\t\t\tEnter the number of the expense to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("\t\t\t\t\t\tInvalid selection.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        (*expenses)[i] = (*expenses)[i + 1];
    }

    (*count)--;
    *expenses = realloc(*expenses, (*count) * sizeof(Expense));
    printf("\t\t\t\t\t\tExpense removed successfully.\n");
}
