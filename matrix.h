/**
 * @file matrix.h
 * @brief Definicja klasy matrix oraz jej metod operujących na macierzach.
 * 
 * Plik nagłówkowy zawiera definicję klasy `matrix`, która umożliwia manipulację macierzami 
 * o wymiarach n x n. Klasa oferuje funkcje do alokacji pamięci, wstawiania i wyświetlania 
 * wartości, generowania losowych macierzy, a także operacje arytmetyczne i operatory porównań.
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @class matrix
 * @brief Klasa reprezentująca macierz o wymiarach n x n.
 * 
 * Klasa umożliwia tworzenie, manipulowanie i wykonywanie operacji matematycznych na macierzach,
 * takich jak dodawanie, mnożenie czy operacje porównań.
 */
class matrix {
private:
    int** data; /**< Wskaźnik do przechowywania macierzy */
    int size;   /**< Rozmiar macierzy (n x n) */

    /**
     * @brief Alokuje pamięć dla macierzy o wymiarach n x n.
     * @param n Rozmiar macierzy.
     */
    void allocateMemory(int n);

    /**
     * @brief Zwalnia pamięć zajmowaną przez macierz.
     */
    void deallocateMemory();

public:
    /**
     * @brief Konstruktor domyślny.
     * Inicjalizuje pustą macierz.
     */
    matrix();

    /**
     * @brief Konstruktor z wymiarem.
     * Tworzy macierz o wymiarach n x n.
     * @param n Wymiar macierzy.
     */
    matrix(int n);

    /**
     * @brief Konstruktor z danymi.
     * Tworzy macierz o wymiarach n x n i wypełnia ją danymi.
     * @param n Wymiar macierzy.
     * @param t Tablica danych.
     */
    matrix(int n, int* t);

    /**
     * @brief Konstruktor kopiujący.
     * Tworzy nową macierz na podstawie innej macierzy.
     * @param m Obiekt macierzy, z którego kopiujemy dane.
     */
    matrix(const matrix& m);

    /**
     * @brief Destruktor.
     * Zwalnia pamięć zajmowaną przez macierz.
     */
    ~matrix();

    /**
     * @brief Alokuje pamięć dla macierzy o wymiarach n x n.
     * @param n Rozmiar macierzy.
     * @return Referencja do obiektu macierzy.
     */
    matrix& alokuj(int n);

    /**
     * @brief Wstawia wartość do macierzy na pozycji (x, y).
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @param wartosc Wartość do wstawienia.
     * @return Referencja do obiektu macierzy.
     */
    matrix& wstaw(int x, int y, int wartosc);

    /**
     * @brief Zwraca wartość elementu macierzy na pozycji (x, y).
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @return Wartość elementu macierzy.
     */
    int pokaz(int x, int y) const;

    /**
     * @brief Odwraca macierz.
     * @return Referencja do odwróconej macierzy.
     */
    matrix& dowroc();

    /**
     * @brief Losuje wartości w macierzy.
     * @return Referencja do obiektu macierzy.
     */
    matrix& losuj();

    /**
     * @brief Losuje wartości w macierzy w zależności od parametru x.
     * @param x Zakres wartości do losowania.
     * @return Referencja do obiektu macierzy.
     */
    matrix& losuj(int x);

    /**
     * @brief Tworzy macierz diagonalną z tablicy t.
     * @param t Tablica wartości.
     * @return Referencja do obiektu macierzy.
     */
    matrix& diagonalna(int* t);

    /**
     * @brief Tworzy macierz diagonalną o przesunięciu k.
     * @param k Przesunięcie.
     * @param t Tablica wartości.
     * @return Referencja do obiektu macierzy.
     */
    matrix& diagonalna_k(int k, int* t);

    /**
     * @brief Wstawia wartości do kolumny x.
     * @param x Numer kolumny.
     * @param t Tablica wartości.
     * @return Referencja do obiektu macierzy.
     */
    matrix& kolumna(int x, int* t);

    /**
     * @brief Wstawia wartości do wiersza y.
     * @param y Numer wiersza.
     * @param t Tablica wartości.
     * @return Referencja do obiektu macierzy.
     */
    matrix& wiersz(int y, int* t);

    /**
     * @brief Tworzy macierz z wartościami na przekątnej.
     * @return Referencja do obiektu macierzy.
     */
    matrix& przekatna();

    /**
     * @brief Tworzy macierz z wartościami poniżej przekątnej.
     * @return Referencja do obiektu macierzy.
     */
    matrix& pod_przekatna();

    /**
     * @brief Tworzy macierz z wartościami powyżej przekątnej.
     * @return Referencja do obiektu macierzy.
     */
    matrix& nad_przekatna();

    /**
     * @brief Tworzy macierz szachownicy.
     * @return Referencja do obiektu macierzy.
     */
    matrix& szachownica();

    /**
     * @brief Operator dodawania dwóch macierzy.
     * @param m Druga macierz.
     * @return Referencja do obiektu wynikowej macierzy.
     */
    matrix& operator+(const matrix& m);

    /**
     * @brief Operator mnożenia dwóch macierzy.
     * @param m Druga macierz.
     * @return Referencja do obiektu wynikowej macierzy.
     */
    matrix& operator*(const matrix& m);

    /**
     * @brief Operator dodawania liczby całkowitej do macierzy.
     * @param a Liczba całkowita.
     * @return Referencja do obiektu wynikowej macierzy.
     */
    matrix& operator+(int a);

    /**
     * @brief Operator mnożenia macierzy przez liczbę całkowitą.
     * @param a Liczba całkowita.
     * @return Referencja do obiektu wynikowej macierzy.
     */
    matrix& operator*(int a);

    /**
     * @brief Operator odejmowania liczby całkowitej od macierzy.
     * @param a Liczba całkowita.
     * @return Referencja do obiektu wynikowej macierzy.
     */
    matrix& operator-(int a);

    /**
     * @brief Operator dodawania liczby całkowitej do macierzy.
     * @param a Liczba całkowita.
     * @param m Macierz.
     * @return Nowa macierz wynikowa.
     */
    friend matrix operator+(int a, const matrix& m);

    /**
     * @brief Operator mnożenia liczby całkowitej przez macierz.
     * @param a Liczba całkowita.
     * @param m Macierz.
     * @return Nowa macierz wynikowa.
     */
    friend matrix operator*(int a, const matrix& m);

    /**
     * @brief Operator odejmowania liczby całkowitej od macierzy.
     * @param a Liczba całkowita.
     * @param m Macierz.
     * @return Nowa macierz wynikowa.
     */
    friend matrix operator-(int a, const matrix& m);

    /**
     * @brief Operator inkrementacji (postfix).
     * @return Referencja do obiektu macierzy.
     */
    matrix& operator++(int);

    /**
     * @brief Operator dekrementacji (postfix).
     * @return Referencja do obiektu macierzy.
     */
    matrix& operator--(int);

    /**
     * @brief Operator dodawania liczby do macierzy (przypisanie).
     * @param a Liczba całkowita.
     * @return Referencja do obiektu macierzy.
     */
    matrix& operator+=(int a);

    /**
     * @brief Operator odejmowania liczby od macierzy (przypisanie).
     * @param a Liczba całkowita.
     * @return Referencja do obiektu macierzy.
     */
    matrix& operator-=(int a);

    /**
     * @brief Operator mnożenia macierzy przez liczbę (przypisanie).
     * @param a Liczba całkowita.
     * @return Referencja do obiektu macierzy.
     */
    matrix& operator*=(int a);

    /**
     * @brief Operator przypisania macierzy.
     * @param m Druga macierz.
     * @return Referencja do obiektu macierzy.
     */
    matrix& operator=(const matrix& m);

    /**
     * @brief Operator przypisania liczby do macierzy.
     * @param a Liczba.
     * @return Referencja do obiektu macierzy.
     */
    matrix& operator=(double a);

    /**
     * @brief Operator wyjścia dla macierzy (do strumienia).
     * @param o Strumień wyjściowy.
     * @param m Macierz.
     * @return Strumień wyjściowy.
     */
    friend std::ostream& operator<<(std::ostream& o, const matrix& m);

    /**
     * @brief Operator porównania macierzy (równość).
     * @param m Druga macierz.
     * @return True, jeśli macierze są równe, false w przeciwnym razie.
     */
    bool operator==(const matrix& m) const;

    /**
     * @brief Operator porównania macierzy (większe).
     * @param m Druga macierz.
     * @return True, jeśli macierz jest większa, false w przeciwnym razie.
     */
    bool operator>(const matrix& m) const;

    /**
     * @brief Operator porównania macierzy (mniejsze).
     * @param m Druga macierz.
     * @return True, jeśli macierz jest mniejsza, false w przeciwnym razie.
     */
    bool operator<(const matrix& m) const;
};

#endif
