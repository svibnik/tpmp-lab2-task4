#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "customer.h"

int read_customers(const char *filename, Customer customers[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return 0;
    }
    *count = 0;
    char line[512];
    while (fgets(line, sizeof(line), file) && *count < MAX_CUSTOMERS) {
        Customer *c = &customers[*count];
        sscanf(line, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;]",
               c->lastname, c->firstname, c->patronymic, c->gender, c->nationality,
               &c->height, &c->weight, c->birthdate, c->phone,
               c->postal_code, c->country, c->region, c->district, c->city,
               c->street, c->house, c->apartment, c->card_number, c->bank_account);
        (*count)++;
    }
    fclose(file);
    return 1;
}

void print_customer(const Customer *c, FILE *output) {
    fprintf(output, "%-15s %-15s %-15s | %-3s | %-10s | %3d | %3d | %-10s | %-15s | %-30s | %-20s\n",
            c->lastname, c->firstname, c->patronymic, c->gender, c->nationality,
            c->height, c->weight, c->birthdate, c->phone, c->city, c->card_number);
}

void filter_by_city(const Customer customers[], int count, const char *city, FILE *output) {
    fprintf(output, "Customers from %s:\n", city);
    fprintf(output, "--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(output, "%-15s %-15s %-15s | Пол | Нац-ть    | Рост| Вес | Дата рожд. | Телефон        | Город                     | Номер карты\n", "Фамилия", "Имя", "Отчество");
    fprintf(output, "--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(customers[i].city, city) == 0) {
            print_customer(&customers[i], output);
            found = 1;
        }
    }
    if (!found) {
        fprintf(output, "No customers found from %s.\n", city);
    }
    fprintf(output, "--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
