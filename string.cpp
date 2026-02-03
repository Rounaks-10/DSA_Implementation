#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> index;
        int maxE=-1;
        int firstE=-1;
        for(int i=0;i<n;i++){
            if(a[i]==-1){
                index.push_back(i);
            }
            maxE=max(maxE,a[i]);
        }
        if(a[0]!=-1){
            firstE=a[0];
        }
        int size=index.size();
        sort(index.begin(),index.end());
        if(index[0]==0 && index[size-1]==n-1){
            a[index[0]]=0;
            a[index[size-1]]=0;
        }
        else if(index[0]==0){
            a[index[0]]=maxE;
        }
        else if(index[size-1]==n-1){
            a[index[size-1]]=firstE;
        }
        
        for(int i=1;i<size-1;i++){
            a[index[i]]=0;
        }
        
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
}