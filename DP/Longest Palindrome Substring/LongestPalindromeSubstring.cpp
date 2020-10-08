#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string str) {
    int n = str.size();
    if(n==0 || n==1)
        return str;
    bool mem[n][n]; 
    long long res = 0;
    memset(mem, 0, sizeof(mem)); 
    int maxLength = 1; 
    for (int i = 0; i < n; i++){
        mem[i][i] = true; 
        res++;
    }
    int start = 0; 
    for (int i = 0; i < n - 1; i++) { 
        if (str[i] == str[i + 1]) { 
            mem[i][i + 1] = true; 
            start = i; 
            maxLength = 2; 
            res++;
        } 
    } 
    for (int length = 3; length <= n; length++) {  
        for (int i = 0; i < n -length + 1; ++i) {
            int j = i + length - 1; 
            if (mem[i + 1][j - 1] && str[i] == str[j]) { 
                mem[i][j] = true; 
                res++;
                if (length > maxLength) { 
                    start = i; 
                    maxLength = length; 
                } 
            } 
        } 
    }
    string res="";
    for(int i=start;i<start+maxLength;i++)
        res +=str[i];
    return res;
}

int main(){
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}