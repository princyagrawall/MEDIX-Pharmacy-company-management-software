#include <stdio.h>
#include "../include/production.h"
#include "../include/rawmaterials.h"
#include "../include/filemanager.h"
#include "../include/utils.h"

#define MED_FILE "medicines.txt"          // Main medicine database file
#define MED_TEMP "temp_medicines.txt"     // Temporary file used during update

// -------------------------------------------------------------
// Function: createProductionBatch
// Purpose : Increase medicine stock by producing new units and 
//           deduct required raw materials.
// -------------------------------------------------------------
void createProductionBatch() {
    int medId, addQty;

    printf("\n--- Create Production Batch ---\n");

    // Take medicine ID to update its stock
    printf("Enter Medicine ID: ");
    scanf("%d", &medId);

    // Take quantity to be produced
    printf("Enter batch quantity to produce: ");
    scanf("%d", &addQty);

    // Raw materials required for production are consumed
    printf("\nUsing Raw Materials...\n");
    consumeRawMaterials(addQty);

    FILE *fp = fopen(MED_FILE, "r");      // Open existing file in read mode
    FILE *temp = fopen(MED_TEMP, "w");    // Open temp file in write mode

    // Handle missing medicine file
    if (!fp) {
        printf("\nError: No medicine database found.\n");
        if (temp) fclose(temp);
        return;
    }

    Medicine m;
    int found = 0;     // Tracks if the medicine ID exists in file

    // Read each medicine record from file
    while (fscanf(fp, "%d,%49[^,],%d,%f\n", 
                  &m.id, m.name, &m.quantity, &m.price) == 4) {

        // When the medicine ID matches, update its quantity
        if (m.id == medId) {
            m.quantity += addQty;
            found = 1;
        }

        // Write updated/unchanged record into temp file
        fprintf(temp, "%d,%s,%d,%.2f\n", 
                m.id, m.name, m.quantity, m.price);
    }

    fclose(fp);
    fclose(temp);

    // If given medicine ID does not exist
    if (!found) {
        printf("\nError: Medicine ID %d not found.\n", medId);
        remove(MED_TEMP);   // Remove temporary file
        return;
    }

    // Replace old file with updated file
    remove(MED_FILE);
    rename(MED_TEMP, MED_FILE);

    // Display production summary
    printf("\nProduction batch completed successfully!\n");
    printf("----------------------------------------------\n");
    printf(" Medicine ID     : %d\n", medId);
    printf(" Quantity Added  : %d\n", addQty);
    printf("----------------------------------------------\n");
}

// -------------------------------------------------------------
// Function: showProductionReport
// Purpose : Display updated stock information for medicines
//           and raw materials.
// -------------------------------------------------------------
void showProductionReport() {
    printf("\n=========== PRODUCTION REPORT ===========\n");

    // Show updated medicine stock by reading file
    printf("\n---- Medicines (Updated Stock) ----\n");
    loadMedicinesFromFile();

    // Show remaining raw materials after production
    printf("\n---- Raw Materials (Current Stock) ----\n");
    loadRawMaterialsFromFile();

    printf("=========================================\n");
}
