#include<bits/stdc++.h>
using namespace std;

//dp array
int dp[1005][1005];

//subset marks implementation
bool subset_marks(int n, int m, int a[]){
    //base case
    if(n==0){
        if(m==0){
            return true;
        }
        else{
            return false;
        }
    }

    //memoization
    if(dp[n][m] != -1) return dp[n][m];

    if(a[n-1]<= m){
        bool op1 = subset_marks(n-1, m-a[n-1], a);
        bool op2 = subset_marks(n-1, m, a);
        dp[n][m]= op1 || op2;
        return dp[n][m];
    }
    else{
        return dp[n][m]= subset_marks(n-1, m, a);
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        //dp array initialization as -1
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j]=-1;
            }
        }

        if(subset_marks(n, m, a)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}