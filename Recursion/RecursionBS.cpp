#include<iostream>
using namespace std;
int Binary_search(int arr[],int s,int e,int key){
    //base case
    if(s>e){ return -1;}
    //recursive case
    int mid=s+(e-s)/2;
    if(arr[mid]==key){ return mid;}
    else if(arr[mid]>key){return Binary_search(arr ,s,mid+1,key);}
    else{ return Binary_search(arr ,mid+1,e,key);}
}

   
int main() {
    int arr[5]={1,2,3,4,5};
    cout<<Binary_search(arr,0,4,3)<<endl;
return 0;
}