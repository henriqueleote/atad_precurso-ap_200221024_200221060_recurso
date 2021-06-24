# Project_Recurso_Template

This is a C program template tailored for:

- GCC, GDB, MAKE, VALGRING and DOXYGEN
- VS CODE editor

## What's included?

### CSV Files

The following *comma separaved value* (CSV) files contain all information that must be imported:

- `csv_data/netflix_titles.csv` - All available titles (7787 titles).

- `csv_data/netflix_titles_1000.csv` - A smaller subset of random 1000 titles (useful for development).

- `csv_data/netflix_titles_clean.csv` - All available titles except those with *missing values* (4808 titles).

**The file [IMPORTANT.md](IMPORTANT.md) contains useful information to define data structures.**

#### Reading CSV files

You have examples on *parsing* CSV files in the course repositories.

Some **useful notes**:

- Be aware that you should *right trim* each CSV line before *tokenizing* the *string* (see `rtrim`), because there are usually some unwanted characters at the end of each line read, e.g., *newlines* and *carriage returns*.

- The `atof` function expects the decimal point as a *point* `.`. If some input value contain comma as the
decimal point, i.e., `,`, you can use the provided `replace` function to convert them.

### Abstract Data Types

Includes the **ADT List** and **ADT Map** to support the project's development. You can add others from the course materials.

### Miscellaneous utilities

The following modules are provided; they can be extended/modified, if you wish:

- **`date`** module

- **`input`** module: for user data input, includes the `splitString` function useful spliting CSV file lines.

- **`stringutils`** module: includes some utilitary functions, namely `rtrim` and `replace`.
