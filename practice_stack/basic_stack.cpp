
#include"practice_stack.h"



void createStack(stack &S){
    S.top=0;
}
bool isEmpty(stack S){
    return S.top==0;
}
bool isFull(stack S){
    return S.top==MAX;
}
void push(stack &S, infotype x){
    if(!isFull(S)){
        S.info[S.top]=x;
        S.top++;
    }else{
        cout<<"Stack FULL"<<endl;
    }
}
infotype pop(stack &S){

    if(isEmpty(S)){
        return NULL;
    }
    infotype x=S.info[S.top-1];
    S.top--;
    return x;
}
void printInfo(stack S){
    int i=S.top;
    while(i--){
        cout<<S.info[i]<<endl;
    }

}
