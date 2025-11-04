// #include<iostream>
// #include<vector>
// using namespace std;
// // Memoization and Recusion
// int fibonacci(int num, vector<int>& dp){
//     if(num==0) return 0;
//     if(num==1) return 1;
//     if(dp[num]!=-1) return dp[num];
//     return dp[num] = fibonacci(num-1, dp)+fibonacci(num-2, dp);
// }
// int main() {
//     int n;
//     cout<<"Enter the index of fibonacci number to be found: ";
//     cin>>n;
//     vector<int> dp(n+1,-1);
//     cout<<fibonacci(n,dp);

// return 0;
// }

#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cout<<"Enter the index of fibonacci number to be found: ";
    cin>>n;
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<"Fibonacci number at index "<<n<<" is "<<dp[n];

return 0;
}