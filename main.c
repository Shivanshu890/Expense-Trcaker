
#include <stdio.h>
#include <stdlib.h>
#include "expense.h"

int main() {
    if (!authenticate_user()) {
        return 1; // Exit if login fails
    }
Expense *expenses = NULL;
int count = 0, choice;
float monthly_budget = 0.0;

load_expenses_from_file(&expenses, &count, "expenses.txt");

monthly_budget = get_monthly_budget();

float total_expenses = 0.0;
for (int i = 0; i < count; i++) {
    total_expenses += expenses[i].amount;
}

float remaining = monthly_budget - total_expenses;
printf("\t\t\t\t\t💰 Amount Left This Month: Rs %.2f of Rs %.2f\n", remaining, monthly_budget);

while (1) {
    printf("===================================================================================================================================\n");
    printf("  ______                                  _______             _                                    _ _           _   _             \n");
    printf(" |  ____|                                |__   __|           | |                 /\\               | (_)         | | (_)            \n");
    printf(" | |__  __  ___ __   ___ _ __  ___  ___     | |_ __ __ _  ___| | _____ _ __     /  \\   _ __  _ __ | |_  ___ __ _| |_ _  ___  _ __  \n");
    printf(" |  __| \\ \\/ | '_ \\ / _ | '_ \\/ __|/ _ \\    | | '__/ _` |/ __| |/ / _ | '__|   / /\\ \\ | '_ \\| '_ \\| | |/ __/ _` | __| |/ _ \\| '_ \\ \n");
    printf(" | |____ >  <| |_) |  __| | | \\__ \\  __/    | | | | (_| | (__|   |  __| |     / ____ \\| |_) | |_) | | | (_| (_| | |_| | (_) | | | |\n");
    printf(" |______/_/\\_| .__/ \\___|_| |_|___/\\___|    |_|_|  \\__,_|\\___|_|\\_\\___|_|    /_/    \\_| .__/| .__/|_|_|\\___\\__,_|\\__|_|\\___/|_| |_|\n");
    printf("             | |                                                                      | |   | |                                    \n");
    printf("             |_|                                                                      |_|   |_|                                    \n");
    printf("===================================================================================================================================\n");
    printf("\033[1m             						1. Add Expense\n\033[0m");
    printf("\033[1m             						2. View Expenses\n\033[0m");
    printf("\033[1m             						3. Show Summary\n\033[0m");
    printf("\033[1m             						4. Save & Exit\n\033[0m");
    printf("\033[1m             						5. Reset All Data\n\033[0m");
    printf("\033[1m             						6. Set Monthly Budget\n\033[0m");
    printf("\033[1m             						7. Remove Expense\n\033[0m");
    printf("===================================================================================================================================\n");
    printf("\t\t\t\t\t\t\tEnter choice: ");
    scanf("%d", &choice);
    printf("===================================================================================================================================\n");

    switch (choice) {
        case 1:
            add_expense(&expenses, &count);
            break;
        case 2:
            list_expenses(expenses, count);
            break;
        case 3:
            calculate_summary(expenses, count);
            break;
        case 4:
            save_expenses_to_file(expenses, count, "expenses.txt");
            printf("\t\t\t\t\t\t\tData saved. Exiting.\n");
            free(expenses);
            exit(0);
        case 5:
            reset_all_data(&expenses, &count);
            break;
        case 6:
            set_monthly_budget(&monthly_budget);
            break;
        case 7:
            remove_expense(&expenses, &count);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

return 0;
}