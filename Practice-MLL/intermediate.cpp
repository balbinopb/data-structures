#include"practice_mll.h"


//-----------intermediate-------

int countParent(MultiList L){
    Parent* Pr=L.firstParent;
    int count=0;
    while(Pr!=NULL){
        count++;
        Pr=Pr->nextParent;
    }
    return count;
}
int countChild(Parent* p){
    Child* Ch=p->firstChild;
    int count=0;
    while(Ch!=NULL){
        count++;
        Ch=Ch->nextChild;
    }
    return count;
}
void showAllParent(MultiList L);
void showAllChild(Parent* p);
void clearAllChild(Parent* p);
void clearAll(MultiList &L);

void updateParent(Parent* p, string newInfo){

    p->infoParent=newInfo;
}
void updateChild(Child* c, string newInfo){
    c->infoChild=newInfo;
}

bool hasChild(Parent* p, string info){
    return p->firstChild!=NULL;
}

Child* searchChildGlobal(MultiList L, string info);

