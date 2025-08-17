
#include <stdio.h>
#include "expense.h"

void list_expenses(Expense *expenses, int count) {
    // Bold title
    printf("\033[1m             \t\t\t\t\t\t💸All Expenses💸\n\033[0m");
    printf("\n");

    // Table header
    printf("\t\t\t\t+-----+------------+-----------------+--------------------------+--------------------+\n");
    printf("\t\t\t\t| No. | Date       | Category        | Description              | Amount             |\n");
    printf("\t\t\t\t+-----+------------+-----------------+--------------------------+--------------------+\n");

    // Table rows
    for (int i = 0; i < count; i++) {
        printf("      \t\t\t\t| %-3d | %-10s | %-15s | %-24s | Rs %-7.1f         |\n",
               i + 1,
               expenses[i].date,
               expenses[i].category,
               expenses[i].description,
               expenses[i].amount);
    }

    // Table footer
    printf("      \t\t\t\t+-----+------------+-----------------+--------------------------+--------------------+\n");
}
