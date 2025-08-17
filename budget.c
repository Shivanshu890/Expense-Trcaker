
#include <stdio.h>
#include <stdlib.h>

static float monthly_budget = 0;

void set_monthly_budget(float *budget) {
    printf("\t\t\t\t\tEnter your monthly budget: Rs ");
    scanf("%f", budget);

    monthly_budget = *budget;

    FILE *fp = fopen("budget.txt", "w");
    if (fp) {
        fprintf(fp, "%.2f", monthly_budget);
        fclose(fp);
    }
    printf("\t\t\t\t\tBudget set successfully.\n");
}

float get_monthly_budget() {
    FILE *fp = fopen("budget.txt", "r");
    if (fp) {
        fscanf(fp, "%f", &monthly_budget);
        fclose(fp);
    }
    return monthly_budget;
}
