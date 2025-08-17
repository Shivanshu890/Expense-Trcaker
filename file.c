
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expense.h"

void save_expenses_to_file(Expense *expenses, int count, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("\t\t\t\t\tFailed to open file for saving.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%s,%s,%.2f\n", expenses[i].date, expenses[i].category,
                expenses[i].description, expenses[i].amount);
    }
    fclose(fp);
}

void load_expenses_from_file(Expense **expenses, int *count, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("\t\t\t\t\tNo previous data found, starting fresh.\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        *expenses = realloc(*expenses, (*count + 1) * sizeof(Expense));
        if (*expenses == NULL) {
            printf("\t\t\t\t\tMemory allocation failed.\n");
            exit(1);
        }
        sscanf(line, "%10[^,],%29[^,],%99[^,],%f",
               (*expenses)[*count].date, (*expenses)[*count].category,
               (*expenses)[*count].description, &(*expenses)[*count].amount);
        (*count)++;
    }
    fclose(fp);
}

void reset_all_data(Expense **expenses, int *count) {
    free(*expenses);
    *expenses = NULL;
    *count = 0;

    FILE *fp = fopen("expenses.txt", "w");
    if (fp) fclose(fp);

    printf("All data has been reset.\n");
}
