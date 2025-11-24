#include <stdio.h>
#include "../include/inventory.h"
#include "../include/billing.h"
#include "../include/rawmaterials.h"
#include "../include/production.h"
#include "../include/utils.h"

void printBanner() {
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║                                 Driven by Quality,             ║\n");
    printf("║                                              Measured by Trust ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n\n");

    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                ║\n");
    printf("║        ███╗   ███╗ ███████╗ ██████╗ ███╗ ███╗ ███╗             ║\n");
    printf("║        ████╗ ████║ ██╔════╝ ██╔══██╗ ██║ ╚██╗ ██╔╝             ║\n");
    printf("║        ██╔████╔██║ █████╗   ██║  ██║ ██║  ╚████╔╝              ║\n");
    printf("║        ██║╚██╔╝██║ ██╔══╝   ██║  ██║ ██║  ██╔██╗               ║\n");
    printf("║        ██║ ╚═╝ ██║ ███████╗ ██████╔╝ ███║ ██╔╝ ╚██╗            ║\n");
    printf("║        ╚═╝     ╚═╝ ╚══════╝ ╚═════╝  ╚═╝   ╚═╝   ╚═╝           ║\n");
    printf("║                                                                ║\n");
    printf("║             Curing the World, Caring Beyond                    ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n\n");

    printf("\tWhere biotechnology meets innovation,\n");
    printf("\tWhere safety meets reliability,\n");
    printf("\tWhere every breakthrough begins with care.\n\n");
}

int main() {
    int choice, opt;

    while (1) {
        clearScreen();
        printBanner();   

        printf("=========================================\n");
        printf("        MEDIX PHARMA MANAGEMENT          \n");
        printf("=========================================\n");
        printf("1. Inventory\n");
        printf("2. Billing\n");
        printf("3. Raw Materials\n");
        printf("4. Production\n");
        printf("5. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clearScreen();
                printf("\n------INVENTORY MENU------\n\n");
                printf("1. Add Medicine\n");
                printf("2. View Medicines\n");
                printf("3. Search Medicine\n");
                printf("Enter option: ");
                scanf("%d", &opt);

                if (opt == 1) addMedicine();
                else if (opt == 2) showAllMedicines();
                else if (opt == 3) searchMedicine();
                else printf("Invalid option!\n");
                break;

            case 2:
                clearScreen();
                printf("\n------BILLING MENU-------\n\n");
                printf("1. Generate Bill\n");
                printf("2. View Bill History\n");
                printf("Enter option: ");
                scanf("%d", &opt);

                if (opt == 1) generateBill();
                else if (opt == 2) showBillHistory();
                else printf("Invalid option!\n");
                break;

            case 3:
                clearScreen();
                printf("\n-------RAW MATERIALS MENU-------\n\n");
                printf("1. Add Raw Material\n");
                printf("2. View Raw Materials\n");
                printf("Enter option: ");
                scanf("%d", &opt);

                if (opt == 1) addRawMaterial();
                else if (opt == 2) viewRawMaterials();
                else printf("Invalid option!\n");
                break;

            case 4:
                clearScreen();
                printf("\n-------PROUCTION MENU-------\n\n");
                printf("1. Produce Batch\n");
                printf("2. View Production Report\n");
                printf("Enter option: ");
                scanf("%d", &opt);

                if (opt == 1) createProductionBatch();
                else if (opt == 2) showProductionReport();
                else printf("Invalid option!\n");
                break;

            case 5:
                printf("\nExiting... Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }

        pauseScreen();
    }
}
