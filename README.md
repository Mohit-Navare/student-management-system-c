# student-management-system-c

A professional **Student Management System** developed in **C** using a modular architecture, file handling, and CSV storage. This project demonstrates CRUD (Create, Read, Update, Delete) operations with clean code organization and reusable modules.

---

## Features

-  Add Student
-  Display All Students
-  Search Student by ID
-  Update Student Details
-  Delete Student
-  Prevent Duplicate Student IDs
-  Store Data in CSV File
-  Modular Programming
-  Input Validation
-  Professional Console Interface

---

## Project Structure

```
StudentManagementSystem/
│
├── src/
│   ├── main.c
│   ├── student.c
│   ├── file.c
│   ├── menu.c
│   └── utility.c
│
├── include/
│   ├── student.h
│   ├── file.h
│   ├── menu.h
│   └── utility.h
│
├── data/
│   └── students.csv
│
├── build/
│
└── README.md
```

---

## Technologies Used

- C Programming Language
- GCC Compiler (MinGW)
- Standard C Library
- CSV File Handling

---

## Data Storage Format

Student records are stored in:

```
data/students.csv
```

Example:

```csv
101,Mohit,20,A
102,Rahul,19,B+
103,Priya,21,A+
```

---

## Compilation

### Windows (MinGW)

```bash
gcc src/*.c -Iinclude -o build/StudentManagementSystem.exe
```

Run:

```bash
build\StudentManagementSystem.exe
```

### Linux

```bash
gcc src/*.c -Iinclude -o build/StudentManagementSystem
```

Run:

```bash
./build/StudentManagementSystem
```

---

## Main Menu

```
==========================================
      STUDENT MANAGEMENT SYSTEM
==========================================

1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit

==========================================
```

---

## Concepts Used

- Structures
- Functions
- Modular Programming
- Header Files
- File Handling
- CSV Storage
- Loops
- Conditional Statements
- Arrays
- String Functions
- Input Validation

---

## Learning Objectives

This project demonstrates practical implementation of:

- CRUD Operations
- File Handling
- Modular Design
- Data Validation
- Software Engineering Practices
- Code Reusability

---

## Future Improvements

- Login System
- Search by Name
- Sort by Name, Age, or Grade
- Student Statistics
- Backup & Restore
- Colored Console Output
- Password Protection
- Binary File Support
- Report Generation

---

## Author

**Mohit Navare**

Bachelor of Engineering (Computer Engineering)

G.V. Acharya Institute of Engineering & Technology

GitHub:
https://github.com/Mohit-Navare

---

## License

This project is developed for educational purposes.
