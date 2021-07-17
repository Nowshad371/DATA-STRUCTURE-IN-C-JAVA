#include <iostream>

using namespace std;
struct insert1{
 //int id;
 char data;
 insert1 *next;
 insert1* previous;
};

class LinkList{
    insert1* head;
    insert1*tail;
    int size;

public:
    LinkList(){

        head = NULL;
        tail = NULL;
        size = 0;


    }
bool isempty(){

    return head == NULL;

}

int length(){

    return size;

}

void insertAtEnd(char value){

    insert1*in = new insert1();
    in->data = value;

    if(isempty()){
        head = in;
    }

    else{

        tail->next = in;

    }
    in->previous = tail;
    tail = in;
    size++;


}

void displayforward(){

    if(head == NULL){

        return;
    }
    cout<<"HEAD = ";

        insert1*current = head;
        while(current != NULL){
            cout<<current->data<<"--> ";
            current = current->next;


        }
        cout<<" = TAIL.next-->NULL\n";


}

void Backward(){

    if(tail == NULL){
        return;
    }
    cout<<"TAIL = ";
    insert1*current = tail;
    while(current != NULL){

        cout<<current->data<<"--> ";
        current = current->previous;


    }
    cout<<" = HEAD-->NULL\n";

}

void inserFirst(char word){

    insert1*in = new insert1();
    in->data = word;

    if(isempty()){
        tail = in;
    }
    else{

        head->previous = in;
    }
    in->next = head;
    head = in;



}
void deletelast(){
    if(head == NULL){
        head =NULL;
    }
    else{
     insert1* current = tail;
     tail = tail->previous;
     tail->next = NULL;
     current->previous = NULL;
     delete current;
    }


}

void deletefirst(){

    if(isempty()){
        head == NULL;
    }
    insert1* current = head;
    if(head == tail) {
			tail = NULL;
    }
    else{


        head->next->previous = NULL;
    }
    head = head->next;
    current->next = NULL;
    delete current;


}





};
int main()
{
    LinkList L;

    L.insertAtEnd('E');
    L.insertAtEnd('F');
    L.insertAtEnd('G');
    L.insertAtEnd('H');
    L.displayforward();
    L.Backward();



    L.inserFirst('D');
    L.inserFirst('C');
    L.inserFirst('B');
    L.inserFirst('A');

    L.displayforward();
    L.Backward();

    L.deletelast();

    L.displayforward();
    L.Backward();

    L.deletefirst();

    L.displayforward();
    L.Backward();
    return 0;
}

