# MEMO-F524 - Master-Thesis - Counting-Rapidly - Triangles-And-Others-Subgraphs

This repository contains my work of Master Thesis for my graduating year at ULB in Computer Science.
It contains my experimentations about graphs and more precisely about counting triangles, 4-cycles and other things.

- Author : Oruç KAPLAN
- Date : June 2024
- University : Université Libre de Bruxelles
- ID : 540662
- Location : Brussels, Belgium

## Purpose of this Repository

This repository is intended for conducting personal experiments and research related to graph analysis and counting subgraphs. The code provided here is build specifically for my Master Thesis and may not be suitable for general usage without modifications.

## Structure of the repository

- `graphs`: This folder contains the input graphs used for the experiments.
- `plots`: This folder is used to store the generated plots and visualizations.
- `results`: This folder is used to store the output results of the experiments.
- `src`: This folder contains the source code for the experiments.

## Required Tools

To build and run the experiments in this repository, you will need the following tools:

### C++ Compiler (g++)

A C++ compiler is required to compile the source code. One commonly used C++ compiler is g++.

### OpenBLAS Library

The OpenBLAS library is used for optimized linear algebra operations in the experiments.
You can install it from: [https://www.openblas.net/](https://www.openblas.net/)
Then ensure you have modified the path to OpenBLAS in the makefile.

## Compilation and Running

To compile and run the experiments in this repository, follow these steps:

1. Open a terminal or command prompt.

2. Navigate to the `src` directory of the repository:
    ```
    cd ./MEMO-F524---Master-Thesis---Counting-Rapidly-Triangles-And-Others-Subgraphs/src
    ```

3. Make sure you have the required tools installed (C++ compiler and OpenBLAS library).

4. Run the following command to compile the source code using the provided makefile:
    ```
    make
    ```

    This will generate the executable file for the experiments.

    Note: If you want to apply optimization flags during compilation, you can use the following commands:
    - For optimization level 1:
        ```
        make optimizeO1
        ```
    - For optimization level 2:
        ```
        make optimizeO2
        ```
    - For optimization level 3:
        ```
        make optimizeO3
        ```

    If you need to modify the makefile for more compiler settings, please refer to the makefile in the `src` directory.

5. Once the compilation is successful, you can run the experiments by executing the generated executable file:
    ```
    ./Main.exe
    ```