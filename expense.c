#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expense.h"

void add_expense(Expense **expenses, int *count) {
    *expenses = realloc(*expenses, (*count + 1) * sizeof(Expense));
    if (*expenses == NULL) {
        printf("\t\t\t\t\t\t\tMemory allocation failed.\n");
        exit(1);
    }

    printf("\t\t\t\t\t\tEnter date (YYYY-MM-DD): ");
    scanf("%s", (*expenses)[*count].date);

    printf("\t\t\t\t\t\tEnter category: ");
    scanf("%s", (*expenses)[*count].category);

    printf("\t\t\t\t\t\tEnter description: ");
    scanf(" %[^\n]s", (*expenses)[*count].description);

    printf("\t\t\t\t\t\tEnter amount: ");
    scanf("%f", &(*expenses)[*count].amount);

    // 💡 Compute total expenses
    float total_expenses = 0.0f;
    for (int i = 0; i < *count; i++) {
        total_expenses += (*expenses)[i].amount;
    }

   float monthly_budget = get_monthly_budget();
if ((total_expenses + (*expenses)[*count].amount) > monthly_budget) {
    float remaining = monthly_budget - total_expenses;
    printf("\n\t⚠️ Cannot add this expense. You only have Rs %.2f left in your budget of Rs %.2f\n",
           remaining, monthly_budget);
    return;
}


    (*count)++;
    printf("===================================================================================================================================\n");
    printf("\t\t\t\t\t\tExpense added successfully!\n");
    printf("===================================================================================================================================\n");
}
