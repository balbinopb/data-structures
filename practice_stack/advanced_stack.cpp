#include"practice_stack.h"


// ===== Fungsi Advanced =====

 // Membalik urutan elemen stack
void reverseStack(stack &S){
    stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        infotype val = pop(S);
        push(temp, val);
    }
    S = temp;

}

// Mengurutkan elemen di stack

/*
void sortStack(stack &S){
     bool ascending = true;
    stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        infotype curr = pop(S);

        // Sisipkan di stack temp secara terurut
        while (!isEmpty(temp) &&
              ((ascending && peek(temp) > curr) || (!ascending && peek(temp) < curr))) {
            push(S, pop(temp));
        }
        push(temp, curr);
    }
    S = temp;

}
*/

// Menggabungkan dua stack menjadi satu
stack mergeStack(stack S1, stack S2){
    stack result;
    createStack(result);

    stack temp;
    createStack(temp);

    // Masukkan semua dari S1
    while (!isEmpty(S1)) {
        push(temp, pop(S1));
    }
    // Balik lagi biar urutan sama
    while (!isEmpty(temp)) {
        push(result, pop(temp));
    }

    // Masukkan semua dari S2
    while (!isEmpty(S2)) {
        push(temp, pop(S2));
    }
    while (!isEmpty(temp)) {
        push(result, pop(temp));
    }

    return result;

}

// Menghapus semua elemen tertentu
void removeSpecific(stack &S, infotype x){
    stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        infotype val = pop(S);
        if (val != x) {
            push(temp, val);
        }
    }
    reverseStack(temp); // Balik urutan
    S = temp;

}

// Mengecek apakah isi stack palindrome
bool isPalindrome(stack S){

    stack temp;
    createStack(temp);
    stack copy = S;

    // Balik stack copy
    reverseStack(copy);

    while (!isEmpty(S)) {
        if (pop(S) != pop(copy)) {
            return false;
        }
    }
    return true;

}
