#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

// Konstruktor domyślny
/**
 * @brief Konstruktor domyślny klasy matrix. 
 * Inicjalizuje macierz o rozmiarze 0.
 */
matrix::matrix() : data(nullptr), size(0) {}

// Konstruktor z wymiarem
/**
 * @brief Konstruktor z jednym parametrem określającym rozmiar macierzy.
 * Alokuje pamięć dla macierzy o rozmiarze n x n.
 * 
 * @param n Rozmiar macierzy (n x n)
 */
matrix::matrix(int n) : size(n) {
    allocateMemory(n);
}

// Konstruktor z danymi
/**
 * @brief Konstruktor, który inicjalizuje macierz na podstawie tablicy danych.
 * Alokuje pamięć dla macierzy o rozmiarze n x n i wypełnia ją danymi przekazanymi w tablicy.
 * 
 * @param n Rozmiar macierzy (n x n)
 * @param t Tablica zawierająca dane, które mają zostać umieszczone w macierzy.
 */
matrix::matrix(int n, int* t) : size(n) {
    allocateMemory(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            data[i][j] = t[i * n + j];
        }
    }
}

// Konstruktor kopiujący
/**
 * @brief Konstruktor kopiujący, który tworzy nową macierz jako kopię innej.
 * 
 * @param m Obiekt klasy matrix, który ma zostać skopiowany.
 */
matrix::matrix(const matrix& m) : size(m.size) {
    allocateMemory(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = m.data[i][j];
        }
    }
}

// Destruktor
/**
 * @brief Destruktor klasy matrix. 
 * Zwalnia alokowaną pamięć.
 */
matrix::~matrix() {
    deallocateMemory();
}

// Alokacja pamięci
/**
 * @brief Funkcja pomocnicza do alokacji pamięci dla macierzy o wymiarach n x n.
 * 
 * @param n Rozmiar macierzy (n x n)
 */
void matrix::allocateMemory(int n) {
    data = new int*[n];
    for (int i = 0; i < n; i++) {
        data[i] = new int[n] {};  // Inicjalizuje macierz zerami
    }
}

// Dealokacja pamięci
/**
 * @brief Zwalnia pamięć alokowaną dla macierzy.
 */
void matrix::deallocateMemory() {
    for (int i = 0; i < size; i++) {
        delete[] data[i];
    }
    delete[] data;
    data = nullptr;
    size = 0;
}

// Metody klasowe

/**
 * @brief Funkcja alokująca pamięć dla nowej macierzy o rozmiarze n x n.
 * 
 * @param n Rozmiar nowej macierzy
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::alokuj(int n) {
    if (data) deallocateMemory();
    size = n;
    allocateMemory(n);
    return *this;
}

/**
 * @brief Ustawia wartość w komórce macierzy.
 * 
 * @param x Indeks wiersza
 * @param y Indeks kolumny
 * @param wartosc Wartość do ustawienia w komórce
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x < size && y < size) {
        data[x][y] = wartosc;
    }
    return *this;
}

/**
 * @brief Zwraca wartość z komórki macierzy.
 * 
 * @param x Indeks wiersza
 * @param y Indeks kolumny
 * @return int Wartość przechowywana w danej komórce
 * @throws std::out_of_range Jeśli indeksy są poza zakresem
 */
int matrix::pokaz(int x, int y) const {
    if (x < size && y < size) {
        return data[x][y];
    }
    throw std::out_of_range("Index out of range");
}

/**
 * @brief Tworzy macierz transponowaną (zamienia wiersze z kolumnami).
 * 
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::dowroc() {
    matrix temp(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp.data[i][j] = data[j][i];
        }
    }
    *this = temp;
    return *this;
}

