#include <stdio.h>
#include "../include/production.h"
#include "../include/rawmaterials.h"
#include "../include/filemanager.h"
#include "../include/utils.h"

#define MED_FILE "medicines.txt"
#define MED_TEMP "temp_medicines.txt"

void createProductionBatch() {
    int medId, addQty;

    printf("\n--- Create Production Batch ---\n");

    printf("Enter Medicine ID: ");
    scanf("%d", &medId);

    printf("Enter batch quantity to produce: ");
    scanf("%d", &addQty);

    printf("\nUsing Raw Materials...\n");
    consumeRawMaterials(addQty);

    FILE *fp = fopen(MED_FILE, "r");
    FILE *temp = fopen(MED_TEMP, "w");

    if (!fp) {
        printf("\nError: No medicine database found.\n");
        if (temp) fclose(temp);
        return;
    }

    Medicine m;
    int found = 0;

    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &m.id, m.name, &m.quantity, &m.price) == 4) {
        if (m.id == medId) {
            m.quantity += addQty;
            found = 1;
        }
        fprintf(temp, "%d,%s,%d,%.2f\n", m.id, m.name, m.quantity, m.price);
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        printf("\nError: Medicine ID %d not found.\n", medId);
        remove(MED_TEMP);
        return;
    }

    remove(MED_FILE);
    rename(MED_TEMP, MED_FILE);

    printf("\nProduction batch completed successfully!\n");
    printf("----------------------------------------------\n");
    printf(" Medicine ID     : %d\n", medId);
    printf(" Quantity Added  : %d\n", addQty);
    printf("----------------------------------------------\n");
}

void showProductionReport() {
    printf("\n=========== PRODUCTION REPORT ===========\n");
    printf("\n---- Medicines (Updated Stock) ----\n");
    loadMedicinesFromFile();

    printf("\n---- Raw Materials (Current Stock) ----\n");
    loadRawMaterialsFromFile();

    printf("=========================================\n");
}
