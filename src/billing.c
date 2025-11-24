#include <stdio.h>
#include "../include/billing.h"
#include "../include/filemanager.h"
#include "../include/utils.h"

void generateBill() {
    int medId, qty , billid;

    printf("\n--- Generate Bill ---\n\n");

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

    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &m.id, m.name, &m.quantity, &m.price) == 4) {
        if (m.id == medId) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Medicine not found.\n");
        return;
    }

    float total = qty * m.price;

    Bill b;
    b.billId = billid;
    b.medicineId = medId;
    b.quantitySold = qty;
    b.totalPrice = total;

    saveBillToFile(b);

    printf("\n----------- BILL ------------\n");
    printf("Bill ID      : %d\n", b.billId);
    printf("Medicine ID  : %d\n", b.medicineId);
    printf("Quantity     : %d\n", b.quantitySold);
    printf("Total Amount : %.2f\n", b.totalPrice);
    printf("------------------------------\n");
}

void showBillHistory() {
    printf("\n--- Bill History ---\n");
    loadBillsFromFile();
}