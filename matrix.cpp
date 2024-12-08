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

