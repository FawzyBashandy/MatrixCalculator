#include <iostream>
#include <cmath>
#include "MatrixCalculator.h"

using namespace std;

void matrx_Filler(long matrx[][Max_Coulomns], int r, int c)
{
    int x;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter row " << i + 1 << " column " << j + 1 << ": ";
            cin >> x;
            matrx[i][j] = x;
        }
    }
}

long long matrx_Determinant(long A[][Max_Coulomns], int r)
{
    long long det = 0;
    if (r == 1)
    {
        return A[0][0];
    }
    else if (r == 2)
    {
        return ((A[0][0] * A[1][1]) - (A[0][1] * A[1][0]));
    }
    else
    {
        for (int i = 0; i < r; i++)
        {
            long temp[Max_Rows][Max_Coulomns] = {0};
            for (int j = 0; j < r - 1; j++)
            {
                for (int k = 0; k < r - 1; k++)
                {
                    if (k < i)
                        temp[j][k] = A[j + 1][k];
                    else
                        temp[j][k] = A[j + 1][k + 1];
                }
            }
            det += (pow(-1, i) * A[0][i] * matrx_Determinant(temp, r - 1));
        }
    }
    return det;
}

void matrx_Adder(long A[][Max_Coulomns], long B[][Max_Coulomns], int r, int c)
{
    long result[Max_Rows][Max_Coulomns] = {0};
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    cout << "Addition of the given matrices is:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void matrx_substractor(long A[][Max_Coulomns], long B[][Max_Coulomns], int r, int c)
{
    long result[Max_Rows][Max_Coulomns] = {0};
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    cout << "Subtraction of the given matrices is:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void matrx_MultiPlier(long A[][Max_Coulomns], long B[][Max_Coulomns], int ra, int rb, int cb)
{
    long result[Max_Rows][Max_Coulomns] = {0};
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            for (int k = 0; k < rb; k++)
            {
                result[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    cout << "Multiplication of the given matrices is:\n";
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void matrx_divider(long A[][Max_Coulomns], long B[][Max_Coulomns], int ra, int rb, int ca, int cb)
{
    long A_T[Max_Rows][Max_Coulomns] = {0}, adj[Max_Rows][Max_Coulomns] = {0}, inverse[Max_Rows][Max_Coulomns] = {0};
    long long det = matrx_Determinant(B, rb);
    if (det == 0)
    {
        cout << "Division not possible\n";
        return;
    }
    else
    {
        for (int i = 0; i < rb; i++)
        {
            for (int j = 0; j < rb; j++)
            {
                long temp[Max_Rows][Max_Coulomns] = {0};
                for (int x = 0; x < rb; x++)
                {
                    for (int y = 0; y < rb; y++)
                    {
                        if (x < i && y < j)
                            temp[x][y] = B[x][y];
                        else if (x < i && y > j)
                            temp[x][y - 1] = B[x][y];
                        else if (x > i && y < j)
                            temp[x - 1][y] = B[x][y];
                        else if (x > i && y > j)
                            temp[x - 1][y - 1] = B[x][y];
                    }
                }
                adj[j][i] = pow(-1, i + j) * matrx_Determinant(temp, rb - 1);
            }
        }
        for (int i = 0; i < rb; i++)
        {
            for (int j = 0; j < rb; j++)
            {
                inverse[i][j] = adj[i][j] / det;
            }
        }
        for (int i = 0; i < ca; i++)
        {
            for (int j = 0; j < rb; j++)
            {
                A_T[i][j] = A[j][i];
            }
        }
        long result[Max_Rows][Max_Coulomns] = {0};
        for (int i = 0; i < ca; i++)
        {
            for (int j = 0; j < rb; j++)
            {
                for (int k = 0; k < rb; k++)
                {
                    result[i][j] += (A_T[i][k] * inverse[k][j]);
                }
            }
        }
        cout << "Division of the given matrices is:\n";
        for (int i = 0; i < ca; i++)
        {
            for (int j = 0; j < cb; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
}