#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return;
}

void calLPS(string p,int* lps,int m){
    lps[0]=0;
    int i=1;
    int j=0;
    while(i<m){
        if(p[i]!=p[j]){
            if(j!=0)
                j = lps[j-1];
            else{
                lps[i]=0;i++;
            }
        }
        else{
            lps[i] = j+1;
            i++;j++;
        }
    }
    printArray(lps,m);
    return;
}
void kmp(string t, string p){
    int n = t.size();
    int m = p.size();
    int lps[m];
    calLPS(p,lps,m);
    int i = 0;
    int j = 0;
    while (i < n) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        }
        if (j == m) { 
            printf("Found pattern at index %d ", i - j); 
            j = lps[j - 1]; 
        }
        else if (i < n && pat[j] != txt[i]) {
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
}
int main(){
    int t;cin>>t;
    while(t--){
        string t,p;cin>>t>>p;
        kmp(t,p);
    }
    return 0;
}