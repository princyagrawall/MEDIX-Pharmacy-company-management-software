#include <stdio.h>
#include "../include/billing.h"
#include "../include/filemanager.h"
#include "../include/utils.h"

/*
 * generateBill
 * Handles the process of creating a bill.
 * Steps:
 * 1. Take bill ID, medicine ID, and quantity as input.
 * 2. Search for the medicine in medicines.txt.
 * 3. Calculate total amount.
 * 4. Save the bill to file.
 * 5. Display the bill neatly.
 */ 

void generateBill() {
    int medId, qty , billid;

    printf("\n--- Generate Bill ---\n\n");

    // Take required details from user

    printf("Enter Bill ID: ");
    scanf("%d", &billid);
    printf("Enter Medicine ID: ");
    scanf("%d", &medId);

    printf("Enter quantity: ");
    scanf("%d", &qty);

    FILE *fp = fopen("medicines.txt", "r");
    if (!fp) {
        printf("No medicines available.\n");
        return;
    }

    Medicine m;
    int found = 0; 

    /*
     * File Format: id,name,quantity,price
     * Read file line-by-line and match medicine ID.
     */

    
    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &m.id, m.name, &m.quantity, &m.price) == 4) {
        if (m.id == medId) {
            found = 1;
            break;
        }
    }
    fclose(fp);
     // If ID not found in file

    if (!found) {
        printf("Medicine not found.\n");
        return;
    }

    float total = qty * m.price;
    /*
     * Fill bill structure with collected and calculated details
     */

    Bill b;
    b.billId = billid;
    b.medicineId = medId;
    b.quantitySold = qty;
    b.totalPrice = total;
     // Save bill record into bill file

    saveBillToFile(b);

    printf("\n----------- BILL ------------\n");
    printf("Bill ID      : %d\n", b.billId);
    printf("Medicine ID  : %d\n", b.medicineId);
    printf("Quantity     : %d\n", b.quantitySold);
    printf("Total Amount : %.2f\n", b.totalPrice);
    printf("------------------------------\n");
}
/*
 * showBillHistory
 * Loads and displays all previous bills from the file.
 */

void showBillHistory() {
    printf("\n--- Bill History ---\n");
    loadBillsFromFile();
}