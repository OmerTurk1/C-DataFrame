# C++ Linked List DataFrame
A lightweight, header-only C++ implementation of a DataFrame-like structure using nested linked lists. This project demonstrates dynamic memory management and custom data structures without relying on heavy external libraries.

## 📌 Overview
The library organizes data into a two-dimensional structure where:

- Columns are managed via a horizontal linked list.
- Elements within each column are managed via a vertical linked list.
- Each column can grow independently, allowing for "jagged" data structures where columns have different lengths.

## 🚀 Features
- Dynamic Column Insertion: Add new columns by name at any time.
- Targeted Data Insertion: Add values to specific columns using their string names.
- Flexible Shape Calculation: Automatically calculates the maximum row count and total column count.
- Data Preview: Print a formatted view of the data with a configurable number of rows.

## 🛠 Class Structure
The implementation consists of three primary classes:

- Element: Represents a single node containing an integer value and a pointer to the next element.
- Column: Represents a column header containing the column name, a pointer to the first element (top of the column), and a pointer to the next column.
- DataFrame: The main interface that manages the head of the column list and provides data manipulation methods.

## 💻 Usage Example

#include "DataFrame.h"

int main() {
    DataFrame df;

    // Adding columns
    df.addColumn("ID");
    df.addColumn("Score");

    // Adding values to specific columns
    df.addValue("ID", 1);
    df.addValue("ID", 2);
    df.addValue("Score", 95);
    df.addValue("Score", 88);

    // Get shape (rows, columns)
    pair<int, int> dims = df.shape(); // Returns {2, 2}

    // Print the first 5 rows
    df.print(5);

    return 0;
}
