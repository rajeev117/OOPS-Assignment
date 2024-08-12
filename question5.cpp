#include<iostream>
using namespace std;

void alphabeticallySort(string & temp){
  //sort(temp.begin(),temp.end())

  //Bubble Sort
  for(int i=1;i<temp.length();i++){
    for(int j=0;j<temp.length()-i;j++){
      if(temp[j]>temp[j+1]){
        swap(temp[j],temp[j+1]);
      }
    }
  }

  cout<<"String after sorting is : "<<temp<<endl;
}


int main(){
  string s;
  cout<<"Enter the string  to sort it : ";
  cin>>s;
  alphabeticallySort(s);
  return 0;
}