#ifndef PRACTICE_MLL_H_INCLUDED
#define PRACTICE_MLL_H_INCLUDED

#include<bits/stdc++.h>

using namespace std;


// --- Child Node ---
struct Child {
    string infoChild;
    Child* nextChild;
};

// --- Parent Node ---
struct Parent {
    string infoParent;
    Child* firstChild;     // pointer ke list anak
    Parent* nextParent;    // pointer ke parent berikutnya
};

// --- Multi Linked List ---
struct MultiList {
    Parent* firstParent;
};

// --- Function ---

//basic
void createList(MultiList &L);
Parent* createParent(string info);
Child* createChild(string info);
void insertParent(MultiList &L, Parent* p);
void insertChild(Parent* p, Child* c);
void showList(MultiList L);
Parent* searchParent(MultiList L, string info);
Child* searchChild(Parent* p, string info);
void deleteChild(Parent* p, string info);
void deleteParent(MultiList &L, string info);

//intermediate
int countParent(MultiList L);
int countChild(Parent* p);
void showAllParent(MultiList L);
void showAllChild(Parent* p);
void clearAllChild(Parent* p);
void clearAll(MultiList &L);
void updateParent(Parent* p, string newInfo);
void updateChild(Child* c, string newInfo);
bool hasChild(Parent* p, string info);
Child* searchChildGlobal(MultiList L, string info);

//advance
int countAllChild(MultiList L);
Parent* parentWithMostChild(MultiList L);
Parent* findParentOfChild(MultiList L, string childInfo);
vector<Parent*> findAllParentOfChild(MultiList L, string childInfo);
void deleteParentWithoutChild(MultiList &L);
void moveChild(Parent* fromParent, Parent* toParent, string childInfo);
void copyAllChild(Parent* fromParent, Parent* toParent);
void swapChild(Parent* p1, Parent* p2);
void reverseChildList(Parent* p);
void reverseParentList(MultiList &L);
void showParentWithMinChild(MultiList L, int minChild);




#endif // PRACTICE_MLL_H_INCLUDED
