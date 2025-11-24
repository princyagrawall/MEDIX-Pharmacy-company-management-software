#include <stdio.h>
#include <stdlib.h>
#include "../include/filemanager.h"

#define MED_FILE "medicines.txt"
#define RAW_FILE "rawmaterials.txt"
#define BILL_FILE "bills.txt"

void saveMedicineToFile(Medicine m) {
    FILE *fp = fopen(MED_FILE, "a");
    if (!fp) return;
    fprintf(fp, "%d,%s,%d,%.2f\n", m.id, m.name, m.quantity, m.price);
    fclose(fp);
}

void loadMedicinesFromFile() {
    FILE *fp = fopen(MED_FILE, "r");
    if (!fp) {
        printf("\nNo medicines found.\n");
        return;
    }

    Medicine m;

    printf("\n-----------------------------------------------\n");
    printf("  ID       NAME                 QTY     PRICE\n");
    printf("-----------------------------------------------\n");

    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &m.id, m.name, &m.quantity, &m.price) == 4) {
        printf("  %-7d %-20s %-7d %-7.2f\n", m.id, m.name, m.quantity, m.price);
    }

    printf("-----------------------------------------------\n");
    fclose(fp);
}

void saveRawMaterialToFile(RawMaterial r) {
    FILE *fp = fopen(RAW_FILE, "a");
    if (!fp) return;
    fprintf(fp, "%d,%s,%d\n", r.id, r.name, r.quantity);
    fclose(fp);
}

void loadRawMaterialsFromFile() {
    FILE *fp = fopen(RAW_FILE, "r");
    if (!fp) {
        printf("\nNo raw materials found.\n");
        return;
    }

    RawMaterial r;

    printf("\n------------------------------------\n");
    printf("  ID       MATERIAL          QTY\n");
    printf("------------------------------------\n");

    while (fscanf(fp, "%d,%49[^,],%d\n", &r.id, r.name, &r.quantity) == 3) {
        printf("  %-7d %-17s %-7d\n", r.id, r.name, r.quantity);
    }

    printf("------------------------------------\n");
    fclose(fp);
}

void saveBillToFile(Bill b) {
    FILE *fp = fopen(BILL_FILE, "a");
    if (!fp) return;
    fprintf(fp, "%d,%d,%d,%.2f\n", b.billId, b.medicineId, b.quantitySold, b.totalPrice);
    fclose(fp);
}

void loadBillsFromFile() {
    FILE *fp = fopen(BILL_FILE, "r");
    if (!fp) {
        printf("\nNo bills found.\n");
        return;
    }

    Bill b;

    printf("\n----------------------------------------------\n");
    printf(" BILL ID   MED ID     QTY      TOTAL\n");
    printf("----------------------------------------------\n");

    while (fscanf(fp, "%d,%d,%d,%f\n", &b.billId, &b.medicineId, &b.quantitySold, &b.totalPrice) == 4) {
        printf(" %-8d %-10d %-8d %.2f\n", b.billId, b.medicineId, b.quantitySold, b.totalPrice);
    }

    printf("----------------------------------------------\n");
    fclose(fp);
}
