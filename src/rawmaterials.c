#include <stdio.h>
#include "../include/rawmaterials.h"
#include "../include/filemanager.h"
#include "../include/utils.h"

void addRawMaterial() {
    RawMaterial r;

    printf("\n--- Add Raw Material ---\n");
    

    printf("Enter ID: ");
    scanf("%d", &r.id);

    printf("Enter material name: ");
    scanf(" %49[^\n]", r.name);

    printf("Enter quantity(in kg): ");
    scanf("%d", &r.quantity);

    saveRawMaterialToFile(r);

    printf("\nRaw material added successfully!\n");
}

void viewRawMaterials() {
    printf("\n--- Raw Material List ---\n");
    loadRawMaterialsFromFile();
}

void consumeRawMaterials(int qty) {
    FILE *fp = fopen("rawmaterials.txt", "r");
    FILE *temp = fopen("temp_raw.txt", "w");

    if (!fp) {
        printf("No raw materials available.\n");
        if (temp) fclose(temp);
        return;
    }

    RawMaterial r;
    int used = 0;

    while (fscanf(fp, "%d,%49[^,],%d\n", &r.id, r.name, &r.quantity) == 3) {

        
        if (!used) {
            if (r.quantity >= qty) {
                r.quantity -= qty;
                used = 1;
            } else {
                printf("\nNot enough raw materials!\n");
            }
        }

        fprintf(temp, "%d,%s,%d\n", r.id, r.name, r.quantity);
    }

    fclose(fp);
    fclose(temp);

    remove("rawmaterials.txt");
    rename("temp_raw.txt", "rawmaterials.txt");

    printf("\nRaw materials consumed: %d\n", qty);
}
