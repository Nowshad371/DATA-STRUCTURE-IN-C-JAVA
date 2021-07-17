#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    string name = "Nowshad";
    int n = name.length();
    bool flag = true;
    //creating char array
    char char_array[n + 1];

    //converting string to array
    strcpy(char_array, name.c_str());

    //char arr[4] = {'A','B','C','D'};
    cout<<"BEFORE: ";
    for(int i=0;i<n;i++){

        cout<<char_array[i];


    }
    //creating string and with the help of push taking words in stack
    stack<char> stack;

    for(int i=0;i<n;i++){

        stack.push(char_array[i]);


    }


    //puting top element of stack in previuos array and removing top
    for(int i=0;i<n;i++){

       if(char_array[i] != stack.top()){
          flag = false;
       }
       stack.pop();
    }


    if(flag){
        cout<<"\n\nYES " <<name << " is A Palindrome " ;
    }
    else{
        cout<<"\n\nNO, " <<name << " is not a Palindrome ";
    }
    //printing the sorting array
    /*cout<<"\nAFTER: ";

    for(int i=0;i<n;i++){

        cout<<char_array[i];


    }*/


    return 0;
}
