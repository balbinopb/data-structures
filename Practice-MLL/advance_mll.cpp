#include"practice_mll.h"


//--------advance------------
int countAllChild(MultiList L){
    Parent* Pr=L.firstParent;
    int countCh=0;
    while(Pr!=NULL){
        Child* Ch=Pr->firstChild;
        while(Ch!=NULL){
            countCh++;
            Ch=Ch->nextChild;
        }
        Pr=Pr->nextParent;
    }
    return countCh;
}
Parent* parentWithMostChild(MultiList L){
    Parent* Pr=L.firstParent;
    Parent* prMost;
    int countCh=0,tempCount;
    while(Pr!=NULL){
        Child* Ch=Pr->firstChild;
        while(Ch!=NULL){
            tempCount++;
            Ch=Ch->nextChild;
        }
        if(tempCount>countCh){
            prMost=Pr;
        }
        Pr=Pr->nextParent;
    }
    return prMost;

}
Parent* findParentOfChild(MultiList L, string childInfo){
    Parent* Pr=L.firstParent;
    while(Pr!=NULL){
        Child* Ch=Pr->firstChild;
        while(Ch!=NULL){
            if(Ch->infoChild==childInfo){
                return Pr;
            }
            Ch=Ch->nextChild;
        }
        Pr=Pr->nextParent;
    }
    return NULL;

}


vector<Parent*> findAllParentOfChild(MultiList L, string childInfo){
    Parent* Pr=L.firstParent;
    vector<Parent*> vPr;
    while(Pr!=NULL){
        Child* Ch=Pr->firstChild;
        while(Ch!=NULL){
            if(Ch->infoChild==childInfo){
                vPr.push_back(Pr);
                break;
            }
            Ch=Ch->nextChild;
        }
        Pr=Pr->nextParent;
    }
    return vPr;

}
void deleteParentWithoutChild(MultiList &L){
    Parent* currPr=L.firstParent;
   if(currPr==NULL){
        cout<<"List kosong"<<endl;
   }else{
        Parent* prevPr=NULL;
        while(currPr!=NULL){
            if(currPr->firstChild==NULL){
                break;
            }
            prevPr=currPr;
            currPr=currPr->nextParent;
        }
        if(currPr==NULL){
            cout<<"Parent tidak ketemu"<<endl;
        }else if(currPr==L.firstParent){
            L.firstParent=currPr->nextParent;
        } else{
            prevPr->nextParent=currPr->nextParent;
            currPr->nextParent=NULL;
            delete currPr;
        }
   }
}

void moveChild(Parent* fromParent, Parent* toParent, string childInfo){
    vector<string> tanpungCh;
    while(fromParent!=NULL){
        Child* Ch=fromParent->firstChild;
        while(Ch!=NULL){
            if(Ch->infoChild==childInfo){
                tanpungCh.push_back(Ch->infoChild);
                deleteChild(fromParent,Ch->infoChild);
            }
            Ch=Ch->nextChild;
        }
        fromParent=fromParent->nextParent;
    }

    //insert ke toParent
    for(int i=0; i<tanpungCh.size(); i++){
        Child* Ch=createChild(tanpungCh[i]);
        insertChild(toParent,Ch);
    }

}

void copyAllChild(Parent* fromParent, Parent* toParent){


}

void swapChild(Parent* p1, Parent* p2){

}

// 1 -> 2 -> 3 -> 4
void reverseChildList(Parent* p){

}

void reverseParentList(MultiList &L);

void showParentWithMinChild(MultiList L, int minChild);
