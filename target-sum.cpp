#include<bits/stdc++.h>
using namespace std;
int main(){
    //test case
    int t;
    cin>>t;
    while(t--){
        //input n and m;
        int n, m;
        cin>>n>>m;
        int a[n], s=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            s+=a[i];
        }

        if(s+m % 2 ==0  && s+m >= 0){
            int s1 = (s+m)/2;
            int dp[n+1][s1+1];
            dp[0][0]= true;
            for(int i=1; i<=s1; i++) dp[0][i]=false;
            for(int i=1; i<=n; i++){
            for(int j=0; j<=s1; j++){
               if(a[i-1]<= j){
                bool op1 = dp[i-1][j-a[i-1]];
                bool op2 = dp[i-1][j];
                 dp[i][j]= op1 || op2;
            }
               else{
                 dp[i][j]= dp[i-1][j];
               }
            }
        }
        if(dp[n][s1]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
       
    }
    else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}