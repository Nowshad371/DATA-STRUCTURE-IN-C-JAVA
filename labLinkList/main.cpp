#include <iostream>

using namespace std;




struct Classinfo {

  int id;
  float test,assignment,quiz,finalex,total;
  Classinfo * next;

  Classinfo() {
    id = 0;
    test = 0;
    assignment = 0;
    quiz = 0;
    finalex = 0;
    total = 0;
    next = NULL;
  }
  Classinfo(int i, float t,float a,float q,float f,float to) {
    id = i;
    test = t;
    assignment =a;
    quiz = q;
    finalex = f;
    total = to;
  }
};

class SinglyLinkedList {
  public:
    Classinfo * head;
    int size;

  SinglyLinkedList() {
    head = NULL;
    size = 0;
  }
  SinglyLinkedList(Classinfo * n) {
    head = n;
  }

  Classinfo * nodeExists(int i) {
  Classinfo * temp = NULL;

    Classinfo * ptr = head;
    while (ptr != NULL) {
      if (ptr -> id == i) {
        temp = ptr;
      }
      ptr = ptr -> next;

    }
    return temp;
  }


  void insertbegin(Classinfo * n) {
    if (nodeExists(n -> id) != NULL) {
      cout << "Given id: " << n -> id << "   already exit" << endl;
    } else {
      n -> next = head;
      head = n;
      cout << "Node added" << endl;
    }
  }

    void insertAnyPosition(){


      Classinfo* n1 = new Classinfo();
      int position;
      cout << "enter position:" << endl;
      cin >> position;
      int id1,test1,assignment1,quiz1,finalex1,total1;
      cout << "enter id:" << endl;
      cin >> id1;
      cout << "enter test1 marks out of 20:" << endl;
      cin >> test1;
      cout << "enter assignment marks out of 30:" << endl;
      cin >> assignment1;
      cout << "enter quiz marks out of 10:" << endl;
      cin >> quiz1;
      cout << "enter final exam marks out of 40:" << endl;
      cin >> finalex1;
      total1 = test1 + assignment1 + quiz1 + finalex1;

      n1 -> id = id1;
      n1 -> test = test1;
      n1 -> assignment  = assignment1;
      n1 -> quiz = quiz1;
      n1 -> finalex = finalex1;
      n1 -> total = total1;
      if(nodeExists(n1->id) != NULL){
        cout << "Given id: " << n1 -> id << "  already exit" << endl;

      }

     else{

        if(position == 1){

            n1->next = head;
            head = n1;

        }
        else{

            Classinfo* pre = head;
            int count = 0;

            while(count < position-1){

                pre = pre->next;
                count++;

            }

            Classinfo* current = pre->next;
            n1->next = current;
            pre->next = n1;


        }

         }

  }

  void insertEnd(){

      Classinfo* n1 = new Classinfo();

      int id1,test1,assignment1,quiz1,finalex1,total1;
      cout << "enter id:" << endl;
      cin >> id1;
      cout << "enter test1 marks out of 20:" << endl;
      cin >> test1;
      cout << "enter assignment marks out of 30:" << endl;
      cin >> assignment1;
      cout << "enter quiz marks out of 10:" << endl;
      cin >> quiz1;
      cout << "enter final exam marks out of 40:" << endl;
      cin >> finalex1;
      total1 = test1 + assignment1 + quiz1 + finalex1;
      n1 -> id = id1;
      n1 -> test = test1;
      n1 -> assignment  = assignment1;
      n1 -> quiz = quiz1;
      n1 -> finalex = finalex1;
      n1 ->total = total1;
      if(nodeExists(n1->id) != NULL){
        cout << "Given id: " << n1 -> id << "  already exit" << endl;

      }

     else{

      if(head == NULL){

        head = n1;

      }
      else{
        Classinfo* current = head;

        while(current->next != NULL){

            current = current->next;


      }

      current->next = n1;


      }

     }
  }
      void deletefirst(){

        if(head == NULL){

                cout<<"empty"<<endl;

        }
        else{

            Classinfo* node = head;

            head = head->next;

            node->next = NULL;






        }

      }
    void deleteNode(){

        Classinfo* current = head;
        while(head != NULL){

            current = current->next;
            delete head;

            head = current;

        }



    }


    void printList() {
    if (head == NULL) {
      cout << "No Nodes in Singly Linked List\n";
    } else {
      cout << endl << "Student information: \n";
      Classinfo * temp = head;

      while (temp != NULL) {
        cout << "  id :  " << temp -> id <<"  " << "quiz number: " << temp -> quiz <<"  "<< "  assignment number :   " <<temp->assignment
        <<"  "<<"  test number: " <<temp->test <<"  " <<"  final exam marks: " << temp->finalex << "  Total Marks : "<<temp->total <<endl;
        temp = temp -> next;
      }
      cout<<"\n";
    }

  }

  void updatedetails(){
    int id;
    cout<<"Enter Id  ";
    cin>>id;
    Classinfo* current = nodeExists(id);

    if(current != NULL){

      int test1,assignment1,quiz1,finalex1,total1;

      cout << "enter test1 marks out of 20: " << endl;
      cin >> test1;
      cout << "enter assignment marks out of 30:" << endl;
      cin >> assignment1;
      cout << "enter quiz marks out of 10: " << endl;
      cin >> quiz1;
      cout << "enter final exam marks out of 40: " << endl;
      cin >> finalex1;
      total1 = test1 + assignment1 + quiz1 + finalex1;

      current -> test = test1;
      current -> assignment  = assignment1;
      current -> quiz = quiz1;
      current -> finalex = finalex1;
      current ->total = total1;
      cout << "Data Updated Successfully" << endl;


    } else {
      cout << "ID doesn't match : " << id << endl;
    }



  }
  bool searchDetails(int ID){

    Classinfo* temp = head;

    while(temp !=NULL){

        if(temp->id ==ID){
             cout << "  id :  " << temp -> id <<"  " << "quiz number: " << temp -> quiz <<"  "<< "  assignment number :   " <<temp->assignment
            <<"  "<<"  test number: " <<temp->test <<"  " <<"  final exam marks: " << temp->finalex <<"  Total Marks : " <<temp->total<<"\n"<<endl;
            return true;
        }
        else{

            temp = temp->next;

        }

    }


}
void deleteGiven(){
        int i;
        cout<<"Enter Id: ";
        cin>>i;
        Classinfo* current = head;
        Classinfo* pre = NULL;
        bool found = false;
        if(head->id == i){
            head = head->next;
            delete current;
            found = true;
        }
        else{
        while(current->id != i && current !=NULL){

            pre = current;
            current = current->next;

        }
        if(current->id == i){

                pre->next = current->next;
                delete current;
                found = true;
            }
        }

        if(found){


            cout<<"Deleted\n";
        }
        else{
            cout<<"Not Found!!\n";
        }


}

void highestMarks(){

    int total1 = 0;

     Classinfo* current = head;

     Classinfo* temp = head;

     while(current != NULL){

        if(current->total > total1){
             total1 = current->total;
        }
        current = current->next;
     }
        cout<<"  Highest number : "<<total1<<endl;
        cout<<"  Student Information:  "<<endl;
     while(temp != NULL){
        if(temp->total == total1){
        cout << " id :  " << temp -> id <<"  " << "quiz number: " << temp -> quiz <<"  "<< "  assignment number :   " <<temp->assignment
        <<"  "<<"  test number: " <<temp->test <<"  " <<"  final exam marks: " << temp->finalex << "  Total Marks : "<<temp->total <<"\n"<<endl;
        return;
        }
        temp = temp->next;
     }



}
void failed(){

    int PassMark = 50;
    Classinfo* temp = head;
    int i = 0;
    while(temp != NULL){
        if(temp->total < PassMark){
        cout << " id :  " << temp -> id <<"  " << "quiz number: " << temp -> quiz <<"  "<< "  assignment number :   " <<temp->assignment
        <<"  "<<"  test number: " <<temp->test <<"  " <<"  final exam marks: " << temp->finalex << "  Total Marks : "<<temp->total <<endl;
        i++;
        }
        temp = temp->next;

        }

        if(i >0){
            cout<<"Total Students failed : "<<i<<"\n";
        }
        else{
            cout<<"No Student failed!!\n";

        }
        cout<<"\n";



}

~SinglyLinkedList (){

    Classinfo* current = head;
    while(head !=NULL){

        current = current->next;
        delete head;

        head = current;

    }

    cout<<"cleaned\n";

}

};

int main()
{
  SinglyLinkedList s;
  int option;
  int id1,test1,assignment1,quiz1,finalex1,total1;
  do {

    cout << "1. insertFirst\t\t\t";
    cout << "2. InsertEnd" << endl;
    cout << "3. Insert at any position\t";
    cout << "4. delete all"<< endl;
    cout << "5. delete First Node\t\t";
    cout << "6. Update details"<< endl;
    cout << "7. Search \t\t\t";
    cout << "8. Delete By id" << endl;
    cout << "9. Highest Marks\t\t";
    cout << "10.Display" << endl;
    cout << "11.Failed\t\t\t";
    cout << "12. Reset All" << endl;
    cout << "0. Exit" << endl;
    cout << "\nEnter option: " ;

    cin >> option;
    Classinfo * n1;
    switch (option) {
    case 0:
      break;
      case 1:
      n1 = new Classinfo();
      cout << "enter id:" << endl;
      cin >> id1;
      cout << "enter test1 marks out of 20: " << endl;
      cin >> test1;
      cout << "enter assignment marks out of 30: " << endl;
      cin >> assignment1;
      cout << "enter quiz marks out of 10: " << endl;
      cin >> quiz1;
      cout << "enter final exam marks out of 40: " << endl;
      cin >> finalex1;
      total1 = test1 + assignment1 + quiz1 + finalex1;

      n1 -> id = id1;
      n1 -> test = test1;
      n1 -> assignment  = assignment1;
      n1 -> quiz = quiz1;
      n1 -> finalex = finalex1;
      n1 ->total = total1;
      s.insertbegin(n1);
      break;

      case 4:
      s.deleteNode();
      break;

      case 2:
      s.insertEnd();

      break;

      case 3:
      s.insertAnyPosition();

      break;

      case 5:
      s.deletefirst();
      break;

      case 6:
      s.updatedetails();
      break;
      case 7:
          int ID;
          cout<<"Enter Id  ";
          cin>>ID;
          if(s.searchDetails(ID)){

            cout<<"FOUND!!\n";
          }
          else{
            cout<<ID <<"NOT FOUND!!\n";
          }
       break;
      case 8:
      s.deleteGiven();

      break;

      case 9:
      s.highestMarks();
      break;
      case 10:
      s.printList();
      break;
      case 11:
      s.failed();
      break;

      case 12:
      s.~SinglyLinkedList();
      break;

      default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);




 return 0;


};
