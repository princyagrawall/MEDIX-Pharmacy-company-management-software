MEDIX PHARMACY MANAGEMENT SOFTWARE
Driven by Quality, Measured by Trust

MEDIX is a C language-based application designed to manage a pharmacy company's daily operations efficiently. It provides features for managing medicines, raw materials, production, and billing in a simple and organized way.

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

📂 PROJECT STRUCTURE:

MEDIX-Pharmacy-company-management-software/
│
├── src/                   # Source files (.c) containing program logic
│   ├── main.c
│   ├── inventory.c
│   ├── billing.c
│   ├── rawmaterials.c
│   ├── production.c
│   └── utils.c
│
├── include/               # Header files (.h) for function declarations and macros
│   ├── billing.h
│   ├── common.h
│   ├── inventory.h
│   ├── production.h
│   ├── rawmaterials.h
│   └── utils.h
│
├── docs/                  # Documentation files or project report (PDFs, guides)
│
├── assets/                # Images/screenshots used in project
│   └── first_interface.jpg.png
│
├── bills.txt              # Saved billing records
├── medicines.txt          # Inventory of medicines
├── rawmaterials.txt       # Inventory of raw materials
├── sample_input.txt       # Example input 
└── README.md              # Project overview and instructions


💻 COMPILATION & EXECUTION:

Clone the repository:

git clone https://github.com/princyagrawall/MEDIX-Pharmacy-company-management-software.git
cd MEDIX-Pharmacy-company-management-software


Compile the source code:

gcc src/*.c -o medix


Run the program:

./medix


Ensure all .txt files (medicines.txt, rawmaterials.txt, bills.txt) remain in the same directory as the executable for proper functionality.

🧠 CONCEPTS DEMONSTRATED:

File operations (fopen, fwrite, fread, remove, rename)

Modular programming in C (using multiple .c and .h files)

Structure and arrays for inventory and billing management

Macros and constants for reusable code

📄 AUTHOR

Princy Agrawal

GitHub: princyagrawall

Location: India