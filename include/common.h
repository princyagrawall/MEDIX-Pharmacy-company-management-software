#ifndef COMMON_H
#define COMMON_H

// Structure to store medicine information
// Contains ID, name, available quantity, and price
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

// Structure to store raw material information
// Contains ID, name, and quantity
typedef struct {
    int id;
    char name[50];
    int quantity;
} RawMaterial;

// Structure to store billing information
// Contains Bill ID, Medicine ID, quantity sold, and total price
typedef struct {
    int billId;
    int medicineId;
    int quantitySold;
    float totalPrice;
} Bill;

#endif
