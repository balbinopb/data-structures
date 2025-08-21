#include <iostream>

#include"practice_stack.h"

int main()
{
    stack s;
    createStack(s);
    push(s,'B');
    push(s,'A');
    push(s,'L');
    push(s,'B');
    push(s,'I');
    push(s,'N');
    push(s,'0');
    infotype x=pop(s);
    cout<<x<<" get pop from stack \n\n"<<endl;
    printInfo(s);
    cout<<"\n\n"<<s.info[s.top-1]<<endl;
    return 0;
}
