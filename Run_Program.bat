@echo off
echo Compiling program...
g++ -c main.cpp
g++ -c matrixcalculator.cpp
g++ -o MatrixCalculator.exe main.o matrixcalculator.o
echo Running program...
MatrixCalculator.exe
echo Program finished.
pause