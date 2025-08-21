
#include"practice_mll.h"


// Membuat list kosong
void createList(MultiList &L){
    L.firstParent=NULL;

}

// Membuat node parent
Parent* createParent(string info){

    Parent* newParent= new Parent;
    newParent->infoParent=info;
    newParent->nextParent=NULL;
    newParent->firstChild=NULL;
    return newParent;
}

// Membuat node child
Child* createChild(string info){
    Child* newChild= new Child;
    newChild->infoChild=info;
    newChild->nextChild=NULL;
    return newChild;
}

// Menyisipkan parent ke akhir list
void insertParent(MultiList &L, Parent* p){

    if(L.firstParent==NULL){
        L.firstParent=p;
        return;
    }

    Parent* lastPr=L.firstParent;
    while(lastPr->nextParent!=NULL){
        lastPr=lastPr->nextParent;
    }
    lastPr->nextParent=p;
}

// Menyisipkan child ke parent tertentu
void insertChild(Parent* p, Child* c){
    if(p->firstChild==NULL){
        p->firstChild=c;
        return;
    }
    Child* lastCh=p->firstChild;
    while(lastCh->nextChild!=NULL){
        lastCh=lastCh->nextChild;
    }
    lastCh->nextChild=c;

}

// Menampilkan seluruh data (Parent + Child list)
void showList(MultiList L){
    Parent* currPr=L.firstParent;
    while(currPr!=NULL){
        Child* currCh=currPr->firstChild;
        int i=1;
        cout<<"Parent "<<currPr->infoParent<<" has child "<<endl;
        if(currCh==NULL){
            cout<<"Has no child"<<endl;
        }else{
            while(currCh!=NULL){
                cout<<"Child "<<i<<" : "<<currCh->infoChild<<endl;
                currCh=currCh->nextChild;
                i++;
            }
        }
        cout<<endl;
        currPr=currPr->nextParent;
    }

}

// Mencari parent berdasarkan info
Parent* searchParent(MultiList L, string info){
    Parent* currPr=L.firstParent;
    while(currPr!=NULL){
        if(currPr->infoParent==info){
            return currPr;
        }
        currPr=currPr->nextParent;
    }
    cout<<" Parent Not found"<<endl;


}

// Mencari child pada parent tertentu
Child* searchChild(Parent* p, string info){
    Child* currCh=p->firstChild;
    while(currCh!=NULL){
        if(currCh->infoChild==info){
            return currCh;
        }
        currCh=currCh->nextChild;
    }
    cout<<" Child Not found"<<endl;
}
// 1 2 3 4 5 6
// Menghapus child dari parent tertentu
void deleteChild(Parent* p, string info){
    Child* currCh=p->firstChild;
    Child* prevCh=NULL;

    while(currCh!=NULL){
        if(currCh->infoChild==info){
            break;
        }
        prevCh=currCh;
        currCh=currCh->nextChild;
    }

    if(currCh!=NULL){
        prevCh->nextChild=currCh->nextChild;
        currCh->nextChild=NULL;
    }else{
        cout<<"The child not found"<<endl;
    }


}

// Menghapus parent (beserta semua child-nya)
void deleteParent(MultiList &L, string info){
   Parent* currPr=L.firstParent;
   if(currPr==NULL){
        cout<<"List kosong"<<endl;
   }else{
        Parent* prevPr=NULL;
        while(currPr!=NULL){
            if(currPr->infoParent==info){
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


