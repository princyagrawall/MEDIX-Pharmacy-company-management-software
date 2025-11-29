#include <stdio.h>
#include <string.h>
#include "../include/inventory.h"
#include "../include/filemanager.h"
#include "../include/utils.h"

/*
 * addMedicine()
 * --------------
 * Collects medicine details from the user and saves them to file.
 * Ensures the data entered is stored using saveMedicineToFile().
 */
void addMedicine() {
    Medicine m;

    printf("\n--- Add Medicine ---\n");

    // Get unique medicine ID
    printf("Enter Medicine ID: ");
    scanf("%d", &m.id);

    // Read the medicine name including spaces
    printf("Enter medicine name: ");
    scanf(" %49[^\n]", m.name);

    // Quantity in stock
    printf("Enter quantity: ");
    scanf("%d", &m.quantity);

    // Price per unit
    printf("Enter price: ");
    scanf("%f", &m.price);

    // Save the collected data to the medicines file
    saveMedicineToFile(m);

    printf("\nMedicine added successfully!\n");
}

/*
 * showAllMedicines()
 * -------------------
 * Simply displays all medicines by calling the loader function.
 * Keeps UI and file-handling separated.
 */
void showAllMedicines() {
    printf("\n--- Medicine List ---\n");
    loadMedicinesFromFile();   // Display all medicines from file
}

/*
 * searchMedicine()
 * -----------------
 * Searches for a medicine using its ID.
 * Reads file line by line, compares ID, and prints details if found.
 */
void searchMedicine() {
    int id;
    
    // Ask user which medicine ID to look for
    printf("Enter Medicine ID: ");
    scanf("%d", &id);

    FILE *fp = fopen("medicines.txt", "r");   // Open file for reading
    if (!fp) {
        printf("No medicines found.\n");
        return;
    }

    Medicine m;
    int found = 0;

    /*
     * Read every record (CSV format) and match the ID.
     * Continue until found or file ends.
     */
    while (fscanf(fp, "%d,%49[^,],%d,%f\n",
                  &m.id, m.name, &m.quantity, &m.price) == 4) {
        
        if (m.id == id) {
            // Display details when the matching ID is found
            printf("\nMedicine Found:\n");
            printf("---------------------------\n");
            printf("ID: %d\nName: %s\nQty: %d\nPrice: %.2f\n",
                   m.id, m.name, m.quantity, m.price);
            printf("---------------------------\n");

            found = 1;
            break;
        }
    }

    // If no record matched the ID
    if (!found)
        printf("Medicine not found.\n");

    fclose(fp);     // Close file after operation
}
