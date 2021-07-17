#include <iostream>

using namespace std;

struct insert1{
 //int id;
 char data;
 insert1 *next;

};

class stack1{
    insert1* top;
    int size;

public:
    stack1(){
        top = NULL;
        size = 0;


    }
bool isempty(){

    return top == NULL;

}

int length(){

    return size;

}

void push(char d){

    insert1* in = new insert1();
    in->data = d;
    insert1* todelete = top;
    in->next = top;
   // delete todelete;
    top = in;

    size++;


}

char pop(){

    if(isempty()){
        cout<<"List is Empty";
    }
    char result = top->data;
    top = top->next;
    size--;
    return result;

}

void peek(){

    if(isempty()){
        cout<<"List is Empty";
    }
    //return top->data;
    cout<<top->data;
}
};
int main()
{
    char value[7];
    stack1 s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');
    s.push('F');
    s.push('G');
   // s.peek();

    cout<<"Length of the stack before:  "<<s.length()<<"\n";
    for(int i=0;i<=6;i++){
        value[i] = s.pop();

    }
    for(int i=0;i<=6;i++){

        cout<<value[i];
    }
    cout<<"\n";


    cout<<"\nLength of the stack after:  "<<s.length()<<"\n";

    s.peek();
    return 0;
}
