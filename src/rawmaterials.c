#include <stdio.h>
#include "../include/rawmaterials.h"
#include "../include/filemanager.h"
#include "../include/utils.h"

// Adds a new raw material to the database
void addRawMaterial() {
    RawMaterial r;

    printf("\n--- Add Raw Material ---\n");

    // Get raw material ID
    printf("Enter ID: ");
    scanf("%d", &r.id);

    // Get material name (allows spaces)
    printf("Enter material name: ");
    scanf(" %49[^\n]", r.name);

    // Get quantity in kg
    printf("Enter quantity(in kg): ");
    scanf("%d", &r.quantity);

    // Save data to file
    saveRawMaterialToFile(r);

    printf("\nRaw material added successfully!\n");
}

// Displays all raw materials stored in the file
void viewRawMaterials() {
    printf("\n--- Raw Material List ---\n");
    loadRawMaterialsFromFile();
}

// Reduces raw material quantity when production happens
void consumeRawMaterials(int qty) {
    FILE *fp = fopen("rawmaterials.txt", "r");
    FILE *temp = fopen("temp_raw.txt", "w");

    // If raw materials file is missing
    if (!fp) {
        printf("No raw materials available.\n");
        if (temp) fclose(temp);
        return;
    }

    RawMaterial r;
    int used = 0;  // Tracks if required quantity is already deducted

    // Read each raw material entry
    while (fscanf(fp, "%d,%49[^,],%d\n", &r.id, r.name, &r.quantity) == 3) {

        // Deduct quantity from the first available material
        if (!used) {
            if (r.quantity >= qty) {
                r.quantity -= qty;
                used = 1;
            } else {
                printf("\nNot enough raw materials!\n");
            }
        }

        // Write updated or unchanged data to temporary file
        fprintf(temp, "%d,%s,%d\n", r.id, r.name, r.quantity);
    }

    fclose(fp);
    fclose(temp);

    // Replace old file with updated data
    remove("rawmaterials.txt");
    rename("temp_raw.txt", "rawmaterials.txt");

    printf("\nRaw materials consumed: %d\n", qty);
}
