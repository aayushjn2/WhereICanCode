#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int i,int j){
    if(i>=s1.size() || j>=s2.size()){
        return 0;
    }
    int ans = 0;
    if(s1[i]==s2[j]){
        ans  = 1+ lcs(s1, s2, i+1,j+1);//rejecting character at ith position in s1 and jth position in s2
    }
    else{
        int temp1 = lcs(s1,s2,i+1,j);//rejecting character at ith position in s1
        int temp2 = lcs(s1,s2,i,j+1);//rejecting character at jth position in s2
        ans = max(temp1, temp2);
    }
    return ans;
}
//FOR LPS REVERSE GIVEN STRING AND FIND LCS.
int main(){
    string s1,s2;cin>>s1>>s2;
    int ans = lcs(s1,s2,0,0);
}