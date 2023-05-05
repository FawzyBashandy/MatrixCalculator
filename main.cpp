#include <iostream>
#include "MatrixCalculator.h"

using namespace std;

int main()
{
    int RowsA, CoulomnsA;
    int RowsB, CoulomnsB;
    long matrixA[Max_Rows][Max_Coulomns];
    long matrixB[Max_Rows][Max_Coulomns];
        cout << "Please enter dimensions of Matrix A:" << endl;
        cin >> RowsA >> CoulomnsA;
        cout << "Please enter dimensions of Matrix B:" << endl;
        cin >> RowsB >> CoulomnsB;
        cout << "Please enter values of Matrix A:" << endl;
        matrx_Filler(matrixA, RowsA, CoulomnsA);
        cout << "Please enter values of Matrix B:" << endl;
        matrx_Filler(matrixB, RowsB, CoulomnsB);
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
        int Operation_Picker;
        do {
            cin >> Operation_Picker;
            switch (Operation_Picker)
            {
            case 1:
                if (RowsA != RowsB || CoulomnsA != CoulomnsB)
                {
                    cout << "The operation you chose is invalid for the given matrices." << endl;
                    cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                    break;
                }
                matrx_Adder(matrixA, matrixB, RowsA, CoulomnsA);//the last two parameters can be rows b and coulomns b it doesn't matter since both are equal
                cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                break;

            case 2:
                if (RowsA != RowsB || CoulomnsA != CoulomnsB)
                {
                    cout << "The operation you chose is invalid for the given matrices." << endl;
                    cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                    break;
                }
                matrx_substractor(matrixA, matrixB, RowsA, CoulomnsA);
                cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                break;
            case 3:
                if (CoulomnsA != RowsB)
                {
                    cout << "The operation you chose is invalid for the given matrices." << endl;
                    cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                    break;
                }
                matrx_MultiPlier(matrixA, matrixB, RowsA, RowsB, CoulomnsB);
                cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                break;
            case 4:
                matrx_divider(matrixA, matrixB, RowsA, RowsB, CoulomnsA, CoulomnsB);
                cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                break;
            case 5:
                if (RowsA != CoulomnsA)
                {
                    cout << "The operation you chose is invalid for the given matrices." << endl;
                    cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                    break;
                }
                cout << matrx_Determinant(matrixA, RowsA) << endl;
                cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                break;
            case 6:
                if (RowsB != CoulomnsB)
                {

                    cout << "The operation you chose is invalid for the given matrices." << endl;
                    cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                    break;

                }
                cout << matrx_Determinant(matrixB, RowsB) << endl;
                cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                break;
            case 7:
                cout << "Thank you!";
                break;
            default:
                cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
            }
        } while (Operation_Picker != 7);

}