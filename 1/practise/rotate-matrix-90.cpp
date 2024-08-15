#include <iostream>
void invertMatrix(int **&matrix, const int size_rows, const int size_cols);
void printMatrix(int **matrix, const int size_rows, const int size_cols);
int main()
{
    int rows = 3;
    int cols = 10;
    //?   1 2 3        1 1 1
    //?   1 2 3   ->   2 2 2
    //?   1 2 3        3 3 3
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    };
    printMatrix(matrix, rows, cols);
    invertMatrix(matrix, rows, cols);
    printMatrix(matrix, cols, rows);
    for (int i = 0; i < cols; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void invertMatrix(int **&matrix, const int size_rows, const int size_cols)
{
    int cols = size_rows;
    int rows = size_cols;
    int **new_matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        new_matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            new_matrix[i][j] = matrix[j][i];
        }
    }
    for (int i = 0; i < size_rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = new_matrix;
}
void printMatrix(int **matrix, const int size_rows, const int size_cols)
{
    std::cout << "*********************" << std::endl;
    for (int i = 0; i < size_rows; i++)
    {
        for (int j = 0; j < size_cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "*********************" << std::endl;
}