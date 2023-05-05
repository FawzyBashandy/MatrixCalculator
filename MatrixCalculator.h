#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H

const int Max_Rows = 10;
const int Max_Coulomns = 10;

void matrx_Filler(long matrx[][Max_Coulomns], int r, int c);
long long matrx_Determinant(long A[][Max_Coulomns], int r);
void matrx_Adder(long A[][Max_Coulomns], long B[][Max_Coulomns], int r, int c);
void matrx_substractor(long A[][Max_Coulomns], long B[][Max_Coulomns], int r, int c);
void matrx_MultiPlier(long A[][Max_Coulomns], long B[][Max_Coulomns], int ra, int rb, int cb);
void matrx_divider(long A[][Max_Coulomns], long B[][Max_Coulomns], int ra, int rb, int ca, int cb);

#endif