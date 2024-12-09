#include "matrix.h"
#include <iostream>
#include <fstream>

void test_matrix_methods() {
    int n = 4;
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    // Test konstruktorów
    std::cout << "Test konstruktorów:\n";
    matrix m1; // Konstruktor domyślny
    matrix m2(n); // Konstruktor z wymiarem
    matrix m3(n, data); // Konstruktor z danymi
    matrix m4(m3); // Konstruktor kopiujący

    // Wyświetlenie macierzy
    std::cout << "Macierz m2 (pusta, rozmiar 4x4):\n" << m2 << "\n";
    std::cout << "Macierz m3 (zainicjalizowana danymi):\n" << m3 << "\n";
    std::cout << "Macierz m4 (kopiowana z m3):\n" << m4 << "\n";

    // Test alokacji
    m1.alokuj(5);
    std::cout << "Macierz m1 po alokacji (5x5):\n" << m1 << "\n";

    // Test wstawiania i pokazywania
    m2.wstaw(1, 1, 42);
    std::cout << "Element (1, 1) macierzy m2: " << m2.pokaz(1, 1) << "\n";

    // Test losowania
    m2.losuj();
    std::cout << "Macierz m2 po losowaniu:\n" << m2 << "\n";

    // Test odwracania
    m3.dowroc();
    std::cout << "Macierz m3 po odwróceniu (transpozycja):\n" << m3 << "\n";

    // Test diagonalnej
    int diagonal[] = {1, 2, 3, 4};
    m2.diagonalna(diagonal);
    std::cout << "Macierz m2 po ustawieniu diagonalnej:\n" << m2 << "\n";

    // Test szachownicy
    m1.szachownica();
    std::cout << "Macierz m1 jako szachownica:\n" << m1 << "\n";

    // Test operatorów arytmetycznych
    matrix m5 = m3 + m4;
    std::cout << "Macierz m5 (m3 + m4):\n" << m5 << "\n";

    matrix m6 = m3 * 2;
    std::cout << "Macierz m6 (m3 * 2):\n" << m6 << "\n";

    m3 += 5;
    std::cout << "Macierz m3 po dodaniu 5 do każdego elementu:\n" << m3 << "\n";

    // Test operatorów porównania
    std::cout << "Czy m3 == m4? " << (m3 == m4 ? "Tak" : "Nie") << "\n";
    std::cout << "Czy m3 > m4? " << (m3 > m4 ? "Tak" : "Nie") << "\n";
    std::cout << "Czy m3 < m4? " << (m3 < m4 ? "Tak" : "Nie") << "\n";

    // Test przekątna, nad_przekatna, pod_przekatna
    m2.przekatna();
    std::cout << "Macierz m2 z przekątną:\n" << m2 << "\n";

    m2.nad_przekatna();
    std::cout << "Macierz m2 z nad przekątną:\n" << m2 << "\n";

    m2.pod_przekatna();
    std::cout << "Macierz m2 z pod przekątną:\n" << m2 << "\n";

    // Test destruktora
    std::cout << "Usuwanie macierzy m1, m2, m3, m4, m5, m6...\n";
}

int main() {
    try {
        test_matrix_methods();
    } catch (const std::exception& e) {
        std::cerr << "Błąd: " << e.what() << "\n";
    }

    return 0;
}
