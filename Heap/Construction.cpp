#include<iostream>
using namespace std;
class heap{
public:
int arr[100];
int size;

heap(){
    arr[0]=-1;
    size=0;
}

void insert(int data){
    size=size+1;
    int index=size;
    arr[size]=data;

    while(index>1){
        int parent=index/2;
        if(arr[parent] < arr[index]){
            swap(arr[parent],arr[index]);
        }
        index=parent;
        
    }
    return;
}

void deletenode(){
    arr[1]=arr[size];
    size--;

    int i=1;
    while(i<size){
        int leftindex=2*i;
        int rightindex=2*i+1;

        if(leftindex<size && arr[i]<arr[leftindex]){
            swap(arr[i],arr[leftindex]);
            i=leftindex;
        }
        else if(rightindex<size && arr[i]<arr[rightindex]){
            swap(arr[i],arr[rightindex]);
            i=rightindex;
        }
        else{
            return;
        }
    }
    return;
}

void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}

void heapify(int arr[],int size,int index){
    int largest=index;
    int left=2*index;
    int right=2*index+1;

    if(left<=size && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=size && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}
void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

};
int main() {
    heap h;
    h.insert(41);
    h.insert(10);
    h.insert(15);
    h.insert(35);
    h.insert(20);
    h.insert(30);
    h.insert(5);

    cout<<"Printing the values ";
    h.print();

    int arr[10]={-1,54,53,55,52,50,56,57,59,60};
    int n=9;
    for(int i=n/2;i>0;i--){
        h.heapify(arr,n,i);
    }
    cout<<endl;
    cout<<"Printing the array now "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Printing the sorted array "<<endl;
    h.heapsort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

return 0;
}