
#include <stdio.h>
#include <stdlib.h>

static float income = 0;

void add_income() {
    float amount;
    printf("\t\t\t\t\tEnter income amount: Rs ");
    scanf("%f", &amount);
    income += amount;

    FILE *fp = fopen("income.txt", "w");
    if (fp) {
        fprintf(fp, "%.2f", income);
        fclose(fp);
    }
    printf("\t\t\t\t\tIncome added successfully.\n");
}

float get_income() {
    FILE *fp = fopen("income.txt", "r");
    if (fp) {
        fscanf(fp, "%f", &income);
        fclose(fp);
    }
    return income;
}
