
#ifndef EXPENSE_H
#define EXPENSE_H

typedef struct {
    char date[11];
    char category[30];
    char description[100];
    float amount;
} Expense;
// Budget functions
void set_monthly_budget(float *budget);
float get_monthly_budget();

// Expense functions
void add_expense(Expense **expenses, int *count);
void list_expenses(Expense *expenses, int count);
void calculate_summary(Expense *expenses, int count);
void save_expenses_to_file(Expense *expenses, int count, const char *filename);
void load_expenses_from_file(Expense **expenses, int *count, const char *filename);
void reset_all_data(Expense **expenses, int *count);
void remove_expense(Expense **expenses, int *count);

// Income
float get_income();

// Auth
int authenticate_user();


#endif
