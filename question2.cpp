#include <iostream>
using namespace std;
int main() {
    int n=10;
    int cnt=0;
    int guess=0;
    
    
    while(guess!=n){
        cout<<"Guess The Number ( hint : less than 100 )"<<endl;
        cin>>guess;
        cnt++;
        
        if(guess==n) break;
        else if(guess >n){
            cout<<"😔 Original Number is less than "<<guess<<endl;
        }
        else{
            cout<<"😔 Original Number is greater than "<<guess<<endl;
        }
            
    
    }
    cout<<"🎉 YOU GUESSED CORRECTLY !"<<" IN "<<cnt<<" ATTEMPT "<<endl;
    return 0;
}