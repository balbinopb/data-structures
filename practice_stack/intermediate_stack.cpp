#include"practice_stack.h"

// ===== Fungsi Intermediate =====

// Menghitung jumlah elemen di stack
int countElements(stack S){
    return S.top;
}

// Mencari elemen dalam stack
bool searchStack(stack S, infotype x){
   for(int i=0; i<S.top; i++){
    if(S.info[i]==x){
        return true;
    }
   }
    return false;

}

// Menghapus semua elemen stack
void clearStack(stack &S){
    S.top=0;
}

// Menyalin stack ke stack baru
stack copyStack(stack S){
    stack temp;
    temp.top = S.top;
    for (int i = 0; i < S.top; i++) {
        temp.info[i] = S.info[i];
    }
    return temp;
}


