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

/**
 * @brief Losuje wartości w macierzy z zakresu 1-100.
 * 
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::losuj() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Inicjalizacja generatora losowego
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = std::rand() % 100 + 1; // Losowa liczba od 1 do 100
        }
    }
    return *this;
}

/**
 * @brief Ustawia wartości na przekątnej macierzy na podstawie podanej tablicy.
 * 
 * @param t Tablica z danymi do wstawienia na przekątną
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::diagonalna(int* t) {
    for (int i = 0; i < size; i++) {
        data[i][i] = t[i]; // Ustawienie wartości na przekątnej
    }
    return *this;
}

/**
 * @brief Tworzy macierz szachownicy (przeplatane 0 i 1).
 * 
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::szachownica() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = (i + j) % 2; // 1 lub 0 w zależności od sumy indeksów
        }
    }
    return *this;
}

/**
 * @brief Tworzy macierz jednostkową (1 na przekątnej, 0 w pozostałych miejscach).
 * 
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::przekatna() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = (i == j) ? 1 : 0;
        }
    }
    return *this;
}

/**
 * @brief Tworzy macierz z 1 poniżej przekątnej (pozostałe miejsca to 0).
 * 
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::pod_przekatna() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = (i > j) ? 1 : 0;
        }
    }
    return *this;
}

/**
 * @brief Tworzy macierz z 1 powyżej przekątnej (pozostałe miejsca to 0).
 * 
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::nad_przekatna() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = (i < j) ? 1 : 0;
        }
    }
    return *this;
}

// Operator wyjścia
/**
 * @brief Operator wyjścia do strumienia.
 * 
 * @param o Strumień wyjściowy
 * @param m Obiekt klasy matrix
 * @return std::ostream& Strumień wyjściowy
 */
std::ostream& operator<<(std::ostream& o, const matrix& m) {
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            o << m.data[i][j] << " ";
        }
        o << "\n";
    }
    return o;
}

// Operator przypisania
/**
 * @brief Operator przypisania kopii macierzy.
 * 
 * @param m Obiekt klasy matrix do przypisania
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::operator=(const matrix& m) {
    if (this == &m) return *this;
    if (data) deallocateMemory();
    size = m.size;
    allocateMemory(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = m.data[i][j];
        }
    }
    return *this;
}

/**
 * @brief Operator przypisania dla liczby, ustawia wszystkie wartości w macierzy na tę liczbę.
 * 
 * @param a Wartość, którą należy przypisać wszystkim komórkom macierzy
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::operator=(double a) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = static_cast<int>(a);
        }
    }
    return *this;
}

/**
 * @brief Operator dodawania macierzy.
 * 
 * @param m Macierz, którą dodajemy do bieżącej macierzy
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::operator+(const matrix& m) {
    if (size != m.size) throw std::invalid_argument("Matrix sizes must be the same");
    matrix temp(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp.data[i][j] = data[i][j] + m.data[i][j];
        }
    }
    return *this = temp;
}

/**
 * @brief Operator mnożenia macierzy przez liczbę.
 * 
 * @param a Liczba, przez którą mnożymy wszystkie elementy macierzy
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::operator*(int a) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] *= a;
        }
    }
    return *this;
}

/**
 * @brief Operator += dla dodawania liczby do wszystkich elementów macierzy.
 * 
 * @param a Liczba, którą dodajemy do wszystkich elementów
 * @return matrix& Odwołanie do obecnego obiektu macierzy
 */
matrix& matrix::operator+=(int a) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] += a;
        }
    }
    return *this;
}

/**
 * @brief Operator porównania == dla macierzy.
 * 
 * @param m Obiekt klasy matrix, z którym porównujemy
 * @return bool Zwraca true, jeśli macierze są równe
 */
bool matrix::operator==(const matrix& m) const {
    if (size != m.size) return false;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i][j] != m.data[i][j]) return false;
        }
    }
    return true;
}

/**
 * @brief Operator porównania > dla macierzy.
 * 
 * @param m Obiekt klasy matrix, z którym porównujemy
 * @return bool Zwraca true, jeśli wszystkie elementy bieżącej macierzy są większe niż odpowiadające elementy macierzy m
 */
bool matrix::operator>(const matrix& m) const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i][j] <= m.data[i][j]) return false;
        }
    }
    return true;
}

/**
 * @brief Operator porównania < dla macierzy.
 * 
 * @param m Obiekt klasy matrix, z którym porównujemy
 * @return bool Zwraca true, jeśli wszystkie elementy bieżącej macierzy są mniejsze niż odpowiadające elementy macierzy m
 */
bool matrix::operator<(const matrix& m) const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i][j] >= m.data[i][j]) return false;
        }
    }
    return true;
}
