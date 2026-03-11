#ifndef CUSTOMER_H
#define CUSTOMER_H

#define MAX_10  16
#define MAX_20  32
#define MAX_30  64
#define MAX_STR 100
#define MAX_STR 100
#define MAX_CUSTOMERS 100

typedef struct {
    char lastname[MAX_STR];
    char firstname[MAX_STR];
    char patronymic[MAX_STR];
    char gender[5];
    char nationality[MAX_STR];
    int height;
    int weight;
    char birthdate[MAX_STR];
    char phone[MAX_20];
    char postal_code[MAX_20];
    char country[MAX_STR];
    char region[MAX_STR];
    char district[MAX_STR];
    char city[MAX_STR];
    char street[MAX_STR];
    char house[MAX_10];
    char apartment[MAX_10];
    char card_number[MAX_20];
    char bank_account[MAX_30];
} Customer;

int read_customers(const char *filename, Customer customers[], int *count);
void print_customers(const Customer *c, FILE *output);
void filter_by_city(const Customer customers[], int count, const char *city, FILE *output);

#endif
