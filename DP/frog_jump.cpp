#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int frog_jump(int index,vector<int>&height,vector<int>&dp){
    if(index==0) return 0;
    if(dp[index]!=-1) return dp[index];
    int left=frog_jump(index-1,height,dp)+ abs(height[index]-height[index-1]);
    int right=INT_MAX;
    if(index>1){
         right=frog_jump(index-2,height,dp)+ abs(height[index]-height[index-2]);
    }
    return dp[index]=min(left,right);
    
}
int main() {
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cout<<frog_jump(n-1,height,dp);

return 0;
}