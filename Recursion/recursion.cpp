#include<iostream>
using namespace std;
int fact(int n){
    if(n==1){
        return 0 ;
    }
    if(n==2){
        return 1 ;
    }
     return fact(n-2)+fact(n-1);
}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    cout<<fact(n);
         
return 0;
}