#include <stdio.h>
#include <stdlib.h>
#include "../include/filemanager.h"

#define MED_FILE "medicines.txt"
#define RAW_FILE "rawmaterials.txt"
#define BILL_FILE "bills.txt"

/*
 * saveMedicineToFile()
 * --------------------
 * Appends a single Medicine record to the medicines file.
 * Uses CSV format: id,name,quantity,price
 */
void saveMedicineToFile(Medicine m) {
    FILE *fp = fopen(MED_FILE, "a");     // Open file in append mode
    if (!fp) return;                     // If file fails to open, exit

    fprintf(fp, "%d,%s,%d,%.2f\n", m.id, m.name, m.quantity, m.price);

    fclose(fp);                          // Close file after writing
}

/*
 * loadMedicinesFromFile()
 * ------------------------
 * Reads all medicines from the file and displays them in table format.
 * Ensures readable alignment of values.
 */
void loadMedicinesFromFile() {
    FILE *fp = fopen(MED_FILE, "r");     // Open file in read mode
    if (!fp) {
        printf("\nNo medicines found.\n");
        return;
    }

    Medicine m;

    // Display table header
    printf("\n-----------------------------------------------\n");
    printf("  ID       NAME                 QTY     PRICE\n");
    printf("-----------------------------------------------\n");

    // Read each medicine until EOF
    while (fscanf(fp, "%d,%49[^,],%d,%f\n",
                  &m.id, m.name, &m.quantity, &m.price) == 4) {
        printf("  %-7d %-20s %-7d %-7.2f\n",
               m.id, m.name, m.quantity, m.price);
    }

    printf("-----------------------------------------------\n");
    fclose(fp);      // Close file after reading
}

/*
 * saveRawMaterialToFile()
 * ------------------------
 * Appends a RawMaterial record to the raw materials file.
 * CSV format: id,name,quantity
 */
void saveRawMaterialToFile(RawMaterial r) {
    FILE *fp = fopen(RAW_FILE, "a");
    if (!fp) return;

    fprintf(fp, "%d,%s,%d\n", r.id, r.name, r.quantity);

    fclose(fp);
}

/*
 * loadRawMaterialsFromFile()
 * ---------------------------
 * Reads and displays all raw materials in a formatted table.
 */
void loadRawMaterialsFromFile() {
    FILE *fp = fopen(RAW_FILE, "r");
    if (!fp) {
        printf("\nNo raw materials found.\n");
        return;
    }

    RawMaterial r;

    // Table header
    printf("\n------------------------------------\n");
    printf("  ID       MATERIAL          QTY\n");
    printf("------------------------------------\n");

    // Read raw material records
    while (fscanf(fp, "%d,%49[^,],%d\n",
                  &r.id, r.name, &r.quantity) == 3) {
        printf("  %-7d %-17s %-7d\n",
               r.id, r.name, r.quantity);
    }

    printf("------------------------------------\n");
    fclose(fp);
}

/*
 * saveBillToFile()
 * -----------------
 * Appends a bill record to the bill file.
 * CSV format: billId,medicineId,quantitySold,totalPrice
 */
void saveBillToFile(Bill b) {
    FILE *fp = fopen(BILL_FILE, "a");
    if (!fp) return;

    fprintf(fp, "%d,%d,%d,%.2f\n",
            b.billId, b.medicineId, b.quantitySold, b.totalPrice);

    fclose(fp);
}

/*
 * loadBillsFromFile()
 * --------------------
 * Reads and displays all bills in table format.
 */
void loadBillsFromFile() {
    FILE *fp = fopen(BILL_FILE, "r");
    if (!fp) {
        printf("\nNo bills found.\n");
        return;
    }

    Bill b;

    // Table header
    printf("\n----------------------------------------------\n");
    printf(" BILL ID   MED ID     QTY      TOTAL\n");
    printf("----------------------------------------------\n");

    // Read bill records until EOF
    while (fscanf(fp, "%d,%d,%d,%f\n",
                  &b.billId, &b.medicineId, &b.quantitySold, &b.totalPrice) == 4) {
        printf(" %-8d %-10d %-8d %.2f\n",
               b.billId, b.medicineId, b.quantitySold, b.totalPrice);
    }

    printf("----------------------------------------------\n");
    fclose(fp);
}
