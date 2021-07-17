#include <iostream>

using namespace std;

struct insert1{
 int id;
 char data;
 int copyno;

 insert1 *next;
};

class LinkList{
    insert1* head;
    int size;

public:
    LinkList(){

        head = NULL;
        size = 0;


    }



void insertBegin(int i,char x){

    insert1*in = new insert1;
    in->id = i;
    in->data = x;


    in->next = head;
    head = in;

    size++;


}

void inserEnd(int i,char value){

    insert1*in = new insert1();

    in->data = value;
    in->id = i;
    if(head ==NULL){

        in = head;

    }
    else{

        insert1* current = head;
        while(current->next!=NULL){

            current = current->next;

        }

        current->next = in;

    }


}

void insertde(int i,char value){
    int n;
    cout<<"enter copy number:  ";
    cin>>n;
    for(int j=1;j<=n;j++){
    insert1*in = new insert1();

    in->data = value;
    in->id = i;
    in->copyno = j;
    if(head ==NULL){

        in = head;

    }
    else{

        insert1* current = head;
        while(current->next!=NULL){

            current = current->next;

        }

        current->next = in;
    }

    }

}

    void atanyposition(int i,char x,int position){



        insert1*n1 = new insert1;
        n1->id = i;
        n1->data = x;
        if(position ==1){

            n1 = head;
        }
        else{

            insert1*current = head;

            int count = 1;

            while(count < position-1){

                current = current->next;
                count++;
            }
            insert1 * temp = current->next;

            current->next = n1;
            n1->next = temp;

        }




}

void display(){

    insert1*current = head;
    int size1 = 0;
    while(current !=NULL){


        cout<<"id "<<current->id<<" name "<<current->data<<"  copy: " <<current->copyno<<"-->";

        current = current->next;
        size1++;
    }

    cout<<"null";
    cout<<"\nSize " <<size1 <<"\n";

}

/*~LinkList(){
    cout<<"\nDestructor called\n";
    cout<<"current size  "<<size<<endl;

    insert1* current = head;
    while(head !=NULL){

        current = current->next;
        delete head;

        head = current;

        cout<<"one node deleted\n";

    }

    size = 0;
    cout<<"After size = "<<size<<endl;


}*/

void deleteBegin(){

    if(head == NULL){

        head = NULL;

    }
    else{

        insert1* current = head;

        head = head->next;
        delete current;


    }


}

void deleteEnd(){

    if(head ==NULL){
        delete head;
        head =NULL;
    }
    else{

        insert1*current = head;
        insert1* pre = head;

        while(current->next!=NULL){
            pre = current;
            current = current->next;

        }

        delete pre->next;
        pre->next = NULL;

    }


}

void deleteAny(int position){

    if(head == NULL){

        delete head;
        head = NULL;

    }
    else{

        int count = 1;
        insert1* current = head;
        //insert1* pre =NULL;
        while(count < position - 1){

            //pre = current;
            current = current->next;
            count++;

        }
        /*pre->next = current->next;
        delete current;*/
        insert1* temp = current->next;
        current->next = temp->next;
        delete temp;


    }


}

void anotherDeleteAny(int position){



    if(head == NULL){

        delete head;
        head = NULL;

    }
    else{

        int count = 0;
        insert1* current = head;
        insert1* pre =NULL;
        while(count < position - 1){

            pre = current;
            current = current->next;
            count++;

        }
        pre->next = current->next;
        delete current;


    }


}

bool searchNumber(char word){

    insert1* current = head;

    while(current !=NULL){

        if(current->data ==word){
            cout<<current->data<<" "<<current->id<<"\n";
            return true;

        }
        else{

            current = current->next;

        }

    }


}


bool deleteGiven(char word){
        insert1* current = head;
        insert1* pre = NULL;

        while(current->data != word &&current !=NULL){

            pre = current;
            current = current->next;

        }
        if(current->data == word){

                pre->next = current->next;

                delete current;
                return true;

            }


}

void sorting(int i,char x){

    insert1*n1 = new insert1;
    n1->id = i;
    n1->data = x;
    insert1* current = head;
    insert1* temp = head;
    if(head==NULL){

        head = n1;

    }
    else if(n1->id == 1){
        n1->next = head;
        head = n1;

    }

    else{


        while(current->id < n1->id){

            temp = current;
            current = current->next;

        }

        n1->next = current;
        temp->next = n1;


    }

}

void middle(){

    insert1* current = head;
    insert1* currentTwice = head;
    if(head == NULL){
       head == NULL;

    }
    else{

    while(currentTwice != NULL){

        current = current->next;
        currentTwice = currentTwice->next->next;

    }
    //return current;
    cout<<"Middle node of this LinkList is : " <<current->id<<" "<<current->data<<"\n";

    }

}

bool circle(){

    insert1* current = head;
    insert1* nextToCurrent = head;

    while(nextToCurrent != NULL && nextToCurrent->next != NULL){

        current = current->next;
        nextToCurrent = nextToCurrent->next->next;

        if(current == nextToCurrent){

            //cout<<"match value " <<current->id<<" "<<current->data<<"\n";
            return true;
           // return current;

        }

    }


    }


};
int main(){

    LinkList L;
    L.insertBegin(3,'C');
    L.insertBegin(2,'B');
    L.inserEnd(5,'E');
    L.inserEnd(6,'F');
    L.insertBegin(1,'A');
    L.atanyposition(4,'D',4);
    L.atanyposition(7,'G',7);
    L.atanyposition(8,'H',8);



    L.display();

    L.deleteBegin();

    L.display();

    L.deleteEnd();

    L.display();

    L.deleteAny(4);

    L.display();

    L.anotherDeleteAny(3);

    L.display();

   if(L.searchNumber('G')){

       cout<<"FOUND!!\n";

    }
    else{

        cout<<"NOT FOUND!!\n";
    }

     if(L.deleteGiven('G')){

        cout<<"deleted\n";

    }

    else{

         cout<<"Not deleted\n";

    }

    L.display();

    if(L.deleteGiven('F')){

        cout<<"deleted\n";

    }

    else{

         cout<<"Not deleted\n";

    }
    L.inserEnd(4,'c');
    L.display();
    L.inserEnd(5,'J');
    L.inserEnd(6,'E');
    L.atanyposition(7,'D',3);
    //L.inserEnd(7,'F');
    //L.insertde(10,'N');

    L.display();




    //insert1*n1 = new insert1;

    if(L.circle()){
        cout<<"\nFound!!Circle\n";
    }
    else{
        cout<<"\nNo Loop!!\n";
    }

    L.middle();

    L.sorting(1,'A');
    L.insertde(10,'N');
    L.display();

    if(L.searchNumber('N')){

       cout<<"FOUND!!\n";

    }
    else{

        cout<<"NOT FOUND!!\n";
    }


    //delete &L;


    if(L.deleteGiven('N')){

        cout<<"deleted\n";

    }

    else{

         cout<<"Not deleted\n";

    }

    L.display();
    return 0;

};

