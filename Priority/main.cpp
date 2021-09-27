#include <iostream>

using namespace std;
struct insert1{
 string data;
 string group;
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
        cout<<"No data in the List";
        return;
    }
    cout<<"Next customer is  ";

        insert1*current = head;


        for(int i =0;i<1;i++){}{
            cout<<current->data<<"  "<<current->group;
            return;
            //current = current->next;

        }



}


void inserFirst(string word,string g){

    insert1*in = new insert1();
    in->data = word;
    in->group = g;


        if(g == "platinium"){
             if(isempty()){
               tail = in;
              }
              else{
                  head->previous = in;
              }
              in->next = head;
               head = in;
        }
       else if(g == "gold"){

            if(isempty()){
               tail = in;
               in->next = head;
               head = in;
              }
              else{
                int i = 0;
                insert1* pre = tail;
                while(i < 5 || i<length()){

                    if(pre->group == "platinum"){
                        insert1* current = pre->next;
                        in->next = current;
                        pre->next = in;
                        return;

                    }
                    pre = pre->previous;
                    i++;
             }
                insert1* current = pre->next;
                in->next = current;
                pre->next = in;
          }


        }
        else if(g == "silver"){

            if(isempty()){
             head = in;
             }

            else{

               tail->next = in;

                }
                in->previous = tail;
                tail = in;

        }

        size++;

   }











void deletefirst(){
    if(head == NULL){
        head =NULL;
    }
    else{
     insert1* current = head;
     head = head->next;
     head->previous = NULL;
     current->next = NULL;
     delete current;

    }
    return;


}
};
int main()
{
  LinkList L;
  int option;


  do {
    cout << "\n\n1. Register Customer\t\t";
    cout << "2. next customer" << endl;
    cout << "3. Waiting Customers\t\t";
    cout << "0. Exit\n";
    cout<<"\nEnter your option: ";
    cin >> option;
    switch (option) {
    case 0:
      break;
      case 1:{
        string name,g;
        cout<<"\nEnter your name for registration:  ";
        cin>>name;
        cout<<"\nEnter group platinium/silver/gold:  ";
        cin>>g;

        L.inserFirst(name,g);
      break;
      }
      case 2:
        L.deletefirst();
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


