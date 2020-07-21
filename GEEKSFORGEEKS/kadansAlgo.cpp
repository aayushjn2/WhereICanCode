#include <iostream>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int res = -10000000;
	    int localmax = 0;
	    for(int i=0;i<n;i++){
	        int x;cin>>x;
	        localmax +=x;
	        if(localmax>res)
	            res = localmax;
	        if(localmax<0)
	            localmax = 0;
	    }
	    cout<<res<<endl;;
	}
	return 0;
}