#include<bits/stdc++.h>
using namespace std;
//range
const int N= 1e5+5;
int dp[N];
int make_it(int curr,int n){
    
    //base case
    if(curr == n) return 1;
    if(curr> n) return 0;
    
    //memoization
    if(dp[curr] != -1) return dp[curr];
    int choice1= make_it(curr+3, n);
    int choice2= make_it(curr*2, n);
    dp[curr]= choice1 || choice2;
    return  dp[curr];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<=n; i++){
            dp[i]=-1;
        }
        if(make_it(1,n)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}