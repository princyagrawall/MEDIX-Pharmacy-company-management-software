#ifndef COMMON_H
#define COMMON_H

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

typedef struct {
    int id;
    char name[50];
    int quantity;
} RawMaterial;

typedef struct {
    int billId;
    int medicineId;
    int quantitySold;
    float totalPrice;
} Bill;

#endif
