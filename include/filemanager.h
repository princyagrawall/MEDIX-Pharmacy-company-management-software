#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "common.h"


void saveMedicineToFile(Medicine m);
void loadMedicinesFromFile();
void rewriteMedicineFile();


void saveRawMaterialToFile(RawMaterial r);
void loadRawMaterialsFromFile();
void rewriteRawMaterialFile();


void saveBillToFile(Bill b);
void loadBillsFromFile();

#endif
