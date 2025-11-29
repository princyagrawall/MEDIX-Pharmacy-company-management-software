#include <stdio.h>
#include "../include/inventory.h"
#include "../include/billing.h"
#include "../include/rawmaterials.h"
#include "../include/production.h"
#include "../include/utils.h"

/*
 * printBanner()
 * ----------------------------------------------------
 * Displays the application banner and branding text.
 * Called at the start of each main menu display.
 * Purely for UI decoration and visual appeal.
 * ----------------------------------------------------
 */
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

    // Additional tagline lines
    printf("\tWhere biotechnology meets innovation,\n");
    printf("\tWhere safety meets reliability,\n");
    printf("\tWhere every breakthrough begins with care.\n\n");
}

/*
 * main()
 * ----------------------------------------------------
 * The main control loop of the pharmacy system.
 * Displays the main menu and routes user choices
 * to the corresponding feature modules:
 *   - Inventory
 *   - Billing
 *   - Raw Materials
 *   - Production
 *
 * Uses an infinite loop until the user selects Exit.
 * ----------------------------------------------------
 */
int main() {
    int choice, opt;

    while (1) {
        clearScreen();       // Clears console for clean view
        printBanner();       // Display banner before menu

        // Main menu
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

            // ---------------------- INVENTORY ----------------------
            case 1:
                clearScreen();
                printf("\n------INVENTORY MENU------\n\n");
                printf("1. Add Medicine\n");
                printf("2. View Medicines\n");
                printf("3. Search Medicine\n");
                printf("Enter option: ");
                scanf("%d", &opt);

                if (opt == 1) addMedicine();          // Add new medicine
                else if (opt == 2) showAllMedicines(); // View list
                else if (opt == 3) searchMedicine();   // Search by ID
                else printf("Invalid option!\n");
                break;

            // ---------------------- BILLING ------------------------
            case 2:
                clearScreen();
                printf("\n------BILLING MENU-------\n\n");
                printf("1. Generate Bill\n");
                printf("2. View Bill History\n");
                printf("Enter option: ");
                scanf("%d", &opt);

                if (opt == 1) generateBill();           // Create bill
                else if (opt == 2) showBillHistory();   // Show all bills
                else printf("Invalid option!\n");
                break;

            // ---------------------- RAW MATERIALS -------------------
            case 3:
                clearScreen();
                printf("\n-------RAW MATERIALS MENU-------\n\n");
                printf("1. Add Raw Material\n");
                printf("2. View Raw Materials\n");
                printf("Enter option: ");
                scanf("%d", &opt);

                if (opt == 1) addRawMaterial();      // Add raw material
                else if (opt == 2) viewRawMaterials(); // View list
                else printf("Invalid option!\n");
                break;

            // ---------------------- PRODUCTION ----------------------
            case 4:
                clearScreen();
                printf("\n-------PROUCTION MENU-------\n\n");
                printf("1. Produce Batch\n");
                printf("2. View Production Report\n");
                printf("Enter option: ");
                scanf("%d", &opt);

                if (opt == 1) createProductionBatch(); // Produce medicine batch
                else if (opt == 2) showProductionReport(); // View production logs
                else printf("Invalid option!\n");
                break;

            // ---------------------- EXIT ---------------------------
            case 5:
                printf("\nExiting... Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }

        pauseScreen();   // Wait for user before returning to menu
    }
}
