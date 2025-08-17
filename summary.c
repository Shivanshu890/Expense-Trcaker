
#include <stdio.h>
#include <string.h>
#include "expense.h"

// Forward declaration if get_income is in another file
extern float get_income();

void calculate_summary(Expense *expenses, int count) {
    float total = 0;
    float income = get_income();

    // Bold & centered title
    printf("\033[1m             \t\t\t\t\t\t📊 Expense Summary 📊\n\033[0m\n");

    // Calculate total expenses
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    // Print total in a table
    printf("      \t\t\t\t\t\t+----------------------+-------------+\n");
    printf("      \t\t\t\t\t\t| \033[1m%-20s\033[0m | \033[1m%-12s\033[0m|\n", "Summary", "Total (Rs)");
    printf("      \t\t\t\t\t\t+----------------------+-------------+\n");
    printf("      \t\t\t\t\t\t| %-20s | Rs %-8.2f |\n", "Total Expenses", total);
    printf("      \t\t\t\t\t\t+----------------------+-------------+\n");

    // Income vs Expense Check
    if (total > income) {
        printf("\n\t\t\t\t\t⚠️ Warning: Expenses exceed your income (Rs %.2f)!\n", income);
    }

    // Category-wise Summary Header
    printf("\n      \t\t\t\t\t\t+----------------------+-------------+\n");
    printf("      \t\t\t\t\t\t| \033[1m%-20s\033[0m | \033[1m%-12s\033[0m|\n", "Category", "Amount (Rs)");
    printf("      \t\t\t\t\t\t+----------------------+-------------+\n");

    // Track printed categories
    int printed[100] = {0}; // Assuming max 100 categories

    for (int i = 0; i < count; i++) {
        if (printed[i]) continue;

        float category_total = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(expenses[i].category, expenses[j].category) == 0) {
                category_total += expenses[j].amount;
                printed[j] = 1;
            }
        }

        printf("      \t\t\t\t\t\t| %-20s | Rs %-8.2f |\n", expenses[i].category, category_total);
    }

    printf("      \t\t\t\t\t\t+----------------------+-------------+\n");
}
