# Probability distribution tables (C)

A console program that looks up values in statistical tables stored as CSV files. I wrote it as a project in the Data Science master's programme at UFAZ in September 2020. The task is described in `ProjectDescription.pdf`; the source tables are in `Tables.pdf`.

## Supported tables

| File | Distribution | Input |
|---|---|---|
| `Normal.csv` | standard normal N(0, 1) | z with two decimal places, e.g. 1.22 |
| `Binomial.csv` | binomial (cumulative) | n ∈ {5, 10, 15, 20, 25}, and x |
| `Student.csv` | Student's t | probability P and degrees of freedom v (1–30) |
| `Chi.csv` | chi-squared χ² | probability P and degrees of freedom v (1–30) |
| `Fisher.csv` | Fisher F | p (0.95 or 0.99), n1 and n2 |

The program reads the CSV file (`;` as separator), works out the row and column from your input, and prints the value from the table.

## How to run

```bash
cc -o readAll readAll.c
./readAll Normal.csv
```

Replace `Normal.csv` with any other table from the list. The program then asks for its parameters in the console.

## Tech stack

C (standard library: `stdio`, `stdlib`, `string`)
