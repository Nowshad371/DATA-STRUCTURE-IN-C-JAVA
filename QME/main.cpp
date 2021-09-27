#include <iostream>

using namespace std;
struct insert1{
 string data;
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



void displayforward(){

    if(head == NULL){

        return;
    }
    cout<<"Next customer is  ";

        insert1*current = tail;
        for(int i =0;i<1;i++){}{
            cout<<current->data;
           // current = current->next;


        }



}



void inserFirst(string word){

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
};
int main()
{
  LinkList L;
  int option;


  do {
    cout << "\n\n1. Register Customer\t\t";
    cout << "2. next customer" << endl;
    cout << "3. Waiting Customers\n";
    cout<<"\nEnter your option: ";
    cin >> option;
    switch (option) {
    case 0:
      break;
      case 1:{
        string name;
        cout<<"\nEnter your name for registration:  ";
        cin>>name;
        L.inserFirst(name);
      break;
      }
      case 2:
        L.deletelast();
      break;

      case 3:
        L.displayforward();
        break;
      default:
      cout << "\n\nEnter Proper Option number " << endl;
    }

  } while (option != 0);


 return 0;


}


