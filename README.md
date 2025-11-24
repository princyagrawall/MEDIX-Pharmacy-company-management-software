--------------------------------------------------------------------------------------------

                       *****MEDIX PHARMACY MANAGEMENT SOFTWARE*****
                           Driven by Quality, Measured by Trust

MEDIX is a C language-based application designed to manage a pharmacy company's daily operations efficiently. It provides features for managing medicines, raw materials, production, and billing in a simple and organized way.

--------------------------------------------------------------------------------------------

📝 FEATURES:

Inventory Management:
Track medicines and raw materials, add or remove stock, and maintain a clear overview of available resources.

Production Management:
Manage production batches, update availability, and keep records of manufactured items.

Billing System:
Generate and save customer bills, calculate total amounts automatically, and store billing history in text files.

Data Storage:
Persistent storage using .txt files (medicines.txt, rawmaterials.txt, bills.txt) for all records.

User-Friendly Interface:
Simple console interface with a clean banner and menu-driven system.

--------------------------------------------------------------------------------------------

📂 PROJECT STRUCTURE:

MEDIX-Pharmacy-company-management-software/
.
├── assets
│   ├── Add_medicine.png
│   ├── Add_raw_materials.png
│   ├── Bill_history.png
│   ├── Create_production_batch.png
│   ├── Exit.png
│   ├── first_interface.png
│   ├── Generating_bill.png
│   ├── Production_report.png
│   ├── search_medicine.png
│   ├── View_medicine.png
│   └── View_raw_materials.png
├── bills.txt
├── docs
│   ├── :docs:ProjectReport.pdf
│   └── project_report.txt
├── include
│   ├── billing.h
│   ├── common.h
│   ├── filemanager.h
│   ├── inventory.h
│   ├── production.h
│   ├── rawmaterials.h
│   └── utils.h
├── medicines.txt
├── medix
├── rawmaterials.txt
├── README.md
├── sample_input.txt
└── src
    ├── billing.c
    ├── filemanager.c
    ├── inventory.c
    ├── main.c
    ├── production.c
    ├── rawmaterials.c
    └── utils.c

--------------------------------------------------------------------------------------------

💻 COMPILATION & EXECUTION:


Clone the repository:

git clone https://github.com/princyagrawall/MEDIX-Pharmacy-company-management-software.git
cd MEDIX-Pharmacy-company-management-software


Compile the source code:

gcc src/*.c -o medix


Run the program:

./medix

--------------------------------------------------------------------------------------------

☑️ SYSTEM REQUIREMENTS:

- Operating System: macOS / Linux

- Compiler: GCC or c compiler

--------------------------------------------------------------------------------------------

🧠 CONCEPTS DEMONSTRATED:

File operations (fopen, fwrite, fread, remove, rename)

Modular programming in C (using multiple .c and .h files)

Structure and arrays for inventory and billing management

Macros and constants for reusable code

--------------------------------------------------------------------------------------------

⌛️ LICENSE:

This project is open-source for educational purposes. You can use and modify it with credit.

--------------------------------------------------------------------------------------------


📄 AUTHOR

Princy Agrawal

GitHub: princyagrawall

Location: India

--------------------------------------------------------------------------------------------