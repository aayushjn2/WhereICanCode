#include <iostream>
using namespace std;
int main() {
	int t;cin>>t;
	while(t--){
	    string s;cin>>s;s = "." + s+".";
	    string res="";
	    for(int i=1;i<s.size()-1;i++){
	        if(s[i]==s[i+1]){
	            continue;
	        }
	        else{
	            if(s[i]!=s[i-1]){
                    res +=s[i];i--;
                }
	        }
	        cout<<res<<endl;
	    }
	    cout<<res<<endl;
	}
	return 0;
}