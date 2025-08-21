#include "practice_mll.h"

using namespace std;

int main()
{
    MultiList L;
    createList(L);

    while(true){
        string infoPr;
        cout<<"input Parent : ";
        cin>>infoPr;
        if(isdigit(infoPr[0])){
            break;
        }
        Parent* p=createParent(infoPr);
        insertParent(L,p);

        while(true){
            string infoCh;
            cout<<"input child : ";
            cin>>infoCh;
            if(isdigit(infoCh[0])){
                break;
            }
            Child* c=createChild(infoCh);
            insertChild(p,c);
        }

    }
    showList(L);

    cout<<"\nTotal All child "<<countAllChild(L)<<endl;

    cout<<"\nParent with most child: "<<parentWithMostChild(L)->infoParent<<endl;

    //this one in main
    vector<Parent*> vPr=findAllParentOfChild(L,"c");
    for(int i=0; i<vPr.size(); i++){
        cout<<vPr[i]->infoParent<<endl;
    }



    return 0;
}
