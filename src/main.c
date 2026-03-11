#include <stdio.h>
#include "customer.h"

int main() {
    Customer customers[MAX_CUSTOMERS];
    int count = 0;
    printf("=== Customer data processor ===\n\n");
    // Чтение данных из файла
    if (!read_customers("data/input.txt", customers, &count)) {
        printf("Failed to read input file.\n");
        return 1;
    }
    printf("Loaded %d customers from file.\n", count);
    // Фильтрация по городу Брест и запись в выходной файл
    FILE *output = fopen("data/output.txt", "w");
    if (!output) {
        printf("Error creating output file.\n");
        return 1;
    }
    filter_by_city(customers, count, "Брест", output);
    fclose(output);
    printf("Results saved to data/output.txt\n");
    return 0;
}
