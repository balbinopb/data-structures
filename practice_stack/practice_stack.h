#ifndef PRACTICE_STACK_H_INCLUDED
#define PRACTICE_STACK_H_INCLUDED


#include<iostream>


using namespace std;

const int MAX=15;

typedef char infotype;

struct stack{
    infotype info[MAX];
    int top;
};

// ===== Fungsi Dasar =====
void createStack(stack &S);              // Membuat stack kosong
bool isEmpty(stack S);                   // Mengecek apakah stack kosong
bool isFull(stack S);                    // Mengecek apakah stack penuh
void push(stack &S, infotype x);         // Menambahkan elemen ke stack
infotype pop(stack &S);                  // Menghapus elemen teratas dari stack
infotype peek(stack S);                  // Melihat elemen teratas tanpa menghapus

// ===== Fungsi Intermediate =====
void printInfo(stack S);                 // Menampilkan isi stack
int countElements(stack S);              // Menghitung jumlah elemen di stack
bool searchStack(stack S, infotype x);   // Mencari elemen dalam stack
void clearStack(stack &S);               // Menghapus semua elemen stack
stack copyStack(stack S);                // Menyalin stack ke stack baru

// ===== Fungsi Advanced =====
void reverseStack(stack &S);             // Membalik urutan elemen stack
void sortStack(stack &S, bool ascending = true); // Mengurutkan elemen di stack
stack mergeStack(stack S1, stack S2);    // Menggabungkan dua stack menjadi satu
void removeSpecific(stack &S, infotype x); // Menghapus semua elemen tertentu
bool isPalindrome(stack S);              // Mengecek apakah isi stack palindrome

#endif // PRACTICE_STACK_H_INCLUDED
