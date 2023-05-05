#include "MatrixC.h"

void matrx_Filler(long matrx[][Max_Coulomns], int r, int c)
{
    int x;
    for (int i = 0; i < r; i++)
    {
        for (int k = 0; k < c; k++)
        {
            cin >> x;
            matrx[i][k] = x;
        }
    }


}


long long matrx_Determinant(long A[][Max_Coulomns], int r) /*we don't need either r or c as both of them are equal*/
{
    long long ans = 0;
    if (r == 1 || r == 2)
    {
        if (r == 1)
            ans = A[0][0];
        else
        {
            ans = long(A[0][0] * A[1][1] - (A[1][0] * A[0][1]));
        }
    }
    else
    {
        int s, e, First_Coulomn_Elements, Initializer, thesign = 1;
        long  long   innerDet;
        long  innermatrx[Max_Rows - 1][Max_Coulomns];
        for (int i = 0; i < r; i++)
        {
            s = 0;
            e = 0;
            First_Coulomn_Elements = A[0][i];
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < r; k++)
                {
                    Initializer = A[j][k];
                    if (j == 0 || i == k) // This will make me neglect the items of the chosen row and colomn
                        continue;
                    else
                    {

                        innermatrx[e][s] = Initializer;
                        if (s < r - 2)
                            s = s + 1;
                        else
                        {
                            s = 0;
                            e = e + 1;
                        }
                    }
                }

            }
            innerDet = thesign * long(First_Coulomn_Elements) * matrx_Determinant(innermatrx, r - 1);
            ans = ans + innerDet;
            thesign = thesign * -1;
        }
    }
    return ans;
}


void matrx_Adder(long A[][Max_Coulomns], long B[][Max_Coulomns], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int k = 0; k < c; k++)
        {
            cout << A[i][k] + long(B[i][k]) << " ";
        }
        if (i <= r - 1)
            cout << endl;
    }
}


void matrx_substractor(long A[][Max_Coulomns], long B[][Max_Coulomns], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int k = 0; k < c; k++)
        {
            cout << A[i][k] - long(B[i][k]) << " ";
        }
        if (i <= r - 1)
            cout << endl;
    }
}


void matrx_MultiPlier(long A[][Max_Coulomns], long B[][Max_Coulomns], int ra, int rb, int cb)
{
    long long sum = 0;
    for (int j = 0; j < ra; j++)
    {
        for (int i = 0; i < cb; i++)
        {
            sum = 0;
            for (int k = 0; k < rb; k++)
            {

                sum += A[j][k] * (B[k][i]);
            }
            sum = round(sum);
            if (sum == -0)
                cout << abs(sum) << " ";
            else
                cout << sum << " ";
        }
        if (j <= ra - 1)
            cout << endl;
    }
}


void matrx_divider(long A[][Max_Coulomns], long B[][Max_Coulomns], int ra, int rb, int ca, int cb)
{
    long long detofB = matrx_Determinant(B, rb);
    if (detofB == 0 || rb != cb || ca != rb)
    {
        cout << "The operation you chose is invalid for the given matrices." << endl;
        return;
    }
    long transposed[Max_Rows][Max_Coulomns];
    for (int j = 0; j < rb; j++)
    {
        for (int k = 0; k < rb; k++)
        {
            transposed[k][j] = B[j][k];
        }
    }
    int s, e, Initializer;
    long innertransposed[Max_Rows - 1][Max_Coulomns];
    double adj[Max_Rows][Max_Coulomns];
    for (int Rows = 0; Rows < rb; Rows++)
    {
        for (int i = 0; i < rb; i++)
        {
            s = 0;
            e = 0;
            for (int j = 0; j < rb; j++)
            {
                for (int k = 0; k < rb; k++)
                {
                    Initializer = transposed[j][k];
                    if (j == Rows || i == k) // This will make me neglect the items of the chosen row and colomn
                        continue;
                    else
                    {

                        innertransposed[e][s] = Initializer; // this will give us the small inner matrices of B whill will be used to get the determinants
                        if (s < rb - 2)
                            s = s + 1;
                        else
                        {
                            s = 0;
                            e = e + 1;
                        }
                    }
                }

            }

            adj[Rows][i] = pow(-1, (Rows + i)) * (1.0 / detofB) * double(matrx_Determinant(innertransposed, rb - 1)); // this will fill the matrix with determinants of B


        }
    }
    double sum = 0;
    for (int j = 0; j < ra; j++)
    {
        for (int i = 0; i < cb; i++)
        {
            sum = 0;
            for (int k = 0; k < rb; k++)
            {

                sum += A[j][k] * (adj[k][i]);
            }
            sum = round(sum);
            if (sum == -0)
                cout << abs(sum) << " ";
            else
                cout << sum << " ";
        }
        if (j <= ra - 1)
            cout << endl;
    }
}
