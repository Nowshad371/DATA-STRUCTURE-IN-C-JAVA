#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isPalindrome(string s){

    int length = s.size();
    cout<<"\nLength of the word "<<s<<" is = " <<length<< endl;

    int i;int mid = length/2;

    // Creating a Stack
    stack<char> st;

    for(i = 0;i<mid;i++){

        st.push(s[i]);
    }
    if(length % 2 != 0){
        i++;
    }
    char check;
    while(s[i] != '\0'){

        check = st.top();
        st.pop();

        if(check != s[i] ){
            return false;
        }
        i++;

    }


    return true;



}
void equalS(string& s){

    int length = s.size();

    for(int i = 0;i<length;i++){
        int c = s[i];
        if (islower(c))
            s[i] = toupper(c);
    }

}
int main()
{
    string s;
    cout << "Enter name: " << endl;
    cin>>s;
    equalS(s);


    if(isPalindrome(s)){
        cout<<"\nYES "<<s<<" IS PALINDROME";
    }
    else{
        cout<<"\nNO " <<s<<" IS NOT PALINDROME";
    }
    int a;
    cout << "\n\nDo you want to type again : " << endl;
    cout << "1.Continue : " << endl;
    cout << "2.Exit: " << endl;
    cout << "Enter option: " << endl;
    cin>>a;
    if(a==1){
          main();
    }
    else{
        exit;
    }

    return 0;


}
