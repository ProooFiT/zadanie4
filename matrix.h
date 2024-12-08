#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class matrix {
private:
    int** data; // Wskaźnik do przechowywania macierzy
    int size;   // Rozmiar macierzy (n x n)

    void allocateMemory(int n);
    void deallocateMemory();

public:
    matrix();                           // Konstruktor domyślny
    matrix(int n);                      // Konstruktor z wymiarem
    matrix(int n, int* t);              // Konstruktor z danymi
    matrix(const matrix& m);            // Konstruktor kopiujący
    ~matrix();                          // Destruktor

    matrix& alokuj(int n);              // Alokacja pamięci
    matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y) const;
    matrix& dowroc();
    matrix& losuj();
    matrix& losuj(int x);
    matrix& diagonalna(int* t);
    matrix& diagonalna_k(int k, int* t);
    matrix& kolumna(int x, int* t);
    matrix& wiersz(int y, int* t);
    matrix& przekatna();
    matrix& pod_przekatna();
    matrix& nad_przekatna();
    matrix& szachownica();

    matrix& operator+(const matrix& m);
    matrix& operator*(const matrix& m);
    matrix& operator+(int a);
    matrix& operator*(int a);
    matrix& operator-(int a);

    friend matrix operator+(int a, const matrix& m);
    friend matrix operator*(int a, const matrix& m);
    friend matrix operator-(int a, const matrix& m);

    matrix& operator++(int);
    matrix& operator--(int);
    matrix& operator+=(int a);
    matrix& operator-=(int a);
    matrix& operator*=(int a);
    matrix& operator=(const matrix& m);
    matrix& operator=(double a);

    friend std::ostream& operator<<(std::ostream& o, const matrix& m);
    bool operator==(const matrix& m) const;
    bool operator>(const matrix& m) const;
    bool operator<(const matrix& m) const;
};

#endif
