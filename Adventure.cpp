#include<bits/stdc++.h>
using namespace std;


// dp array
int dp[1005][1005];
int knapsack(int N, int W, int v[], int w[]){
    if(N==0 || W ==0 ) return 0;

    if(dp[N][W] != -1) return dp[N][W];

    if(w[N-1]<=W){

        int op1= knapsack(N-1, W-w[N-1], v, w)+ v[N-1];
        int op2= knapsack(N-1, W, v, w);
        dp[N][W]= max(op1, op2);
        return dp[N][W];
    }
    else{
        return dp[N][W]= knapsack(N-1, W, v, w);
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
       

        int w[N];
        for(int i=0; i<N; i++){
            cin>>w[i];
        }

        int v[N];
        for(int i=0; i<N; i++){
            cin>>v[i];
        }
        for(int i=0; i<= N; i++){
            for(int j=0; j<=W; j++){
                dp[i][j]=-1;
            }
        }

        cout<<knapsack(N, W, v,w)<<endl;
       
    }
    return 0;
}