#include <stdio.h>
#include <string.h>
#include "../include/inventory.h"
#include "../include/filemanager.h"
#include "../include/utils.h"

void addMedicine() {
    Medicine m;

    printf("\n--- Add Medicine ---\n");

    printf("Enter Medicine ID: ");
    scanf("%d", &m.id);

    printf("Enter medicine name: ");
    scanf(" %49[^\n]", m.name);

    printf("Enter quantity: ");
    scanf("%d", &m.quantity);

    printf("Enter price: ");
    scanf("%f", &m.price);

    saveMedicineToFile(m);
    printf("\nMedicine added successfully!\n");
}

void showAllMedicines() {
    printf("\n--- Medicine List ---\n");
    loadMedicinesFromFile();
}

void searchMedicine() {
    int id;
    printf("Enter Medicine ID: ");
    scanf("%d", &id);

    FILE *fp = fopen("medicines.txt", "r");
    if (!fp) {
        printf("No medicines found.\n");
        return;
    }

    Medicine m;
    int found = 0;

    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &m.id, m.name, &m.quantity, &m.price) == 4) {
        if (m.id == id) {
            printf("\nMedicine Found:\n");
            printf("---------------------------\n");
            printf("ID: %d\nName: %s\nQty: %d\nPrice: %.2f\n", m.id, m.name, m.quantity, m.price);
            printf("---------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) printf("Medicine not found.\n");

    fclose(fp);
}