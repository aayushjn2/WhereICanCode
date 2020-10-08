#include<bits/stdc++.h>
using namespace std;
int usingDP(string s){
    int n = s.size();
    int mem[n+1];
    memset(mem,0,sizeof(mem));
    mem[0] = 0;
    mem[1] = (s[0]=='0')?0:1;
    for(int i=2;i<=n;i++){
        int val = (int)s[i];
        if(0<val && val<=9){
            dp[i] +=dp[i-1];
        }
        if(10<=val && val<=26){
            dp[i] +=dp[i-2];
        }
    }
    return dp[n];
}
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        cout<<usingDP(s)<<endl;
    }
    return 0;
}