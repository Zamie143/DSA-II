#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second 
const int N=1e3+2;
int dp[N][N];
char dir[N][N];

void printLCS(string &s1,string &s2,int n,int m){
    if(n==0||m==0)
    return ;
    
    if(dir[n][m]=='D'){
        printLCS(s1,s2,n-1,m-1);
        cout<<s1[n-1];
    }else if(dir[n][m]=='U'){
         printLCS(s1,s2,n-1,m);
    }else{
         printLCS(s1,s2,n,m-1);
    }
}

int main(){
rep(i,0,N){
    rep(j,0,N){
        dp[i][j]=-1;
        dir[i][j]=' ';
    }
}
string s1,s2;
cout<<"Enter 1st String:";
cin>>s1;
cout<<"Enter 2nd String:";
cin>>s2;
int n=s1.size();
int m=s2.size();

rep(i,0,n+1){
    rep(j,0,m+1){
        if(i==0||j==0){
            dp[i][j]=0;
        }else if(s1[i-1]==s2[j-1]){
             dp[i][j]=1+dp[i-1][j-1];
             dir[i][j]='D';
        }else{
            if(dp[i-1][j]>=dp[i][j-1]){
                dp[i][j]=dp[i-1][j];
                dir[i][j]='U';
            }else{
                dp[i][j]=dp[i][j-1];
                dir[i][j]='L';
            }
        }
    }
}
cout<<"\nPrint LCS Length Table:\n";
rep(j,0,m){
     cout<<"0 ";
}
cout<<endl;
rep(i,1,n+1){
    rep(j,1,m+1){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
}
cout<<"\nDirection Table:\n";
rep(i,1,n+1){
    rep(j,1,m+1){
        cout<<dir[i][j]<<" ";
    }
    cout<<endl;
}
cout<<"Length of LCS:"<<dp[n][m]<<endl;
cout<<"LCS:";
printLCS(s1,s2,n,m);
cout<<endl;
return 0;
}
