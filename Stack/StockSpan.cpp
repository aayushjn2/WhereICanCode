#include <bits/stdc++.h>
using namespace std;

vector<int> NextGreaterElementOnLeft(vector<int> & stock){
    if(stock.size()==0){
        return vector<int>();
    }
    stack<int> s;
    vector<int> res(stock.size());
    for(int i = stock.size()-1;i>=0;i--){
        while(!s.empty() && stock[i] > stock[s.top()]){
            res[s.top()] = s.top()-i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        res[s.top()] = s.top()+1;
        s.pop();
    }
    return res;
}
//Method 2
vector<int> calc(vector<int> & stock){
    if(stock.size()==0){
        return vector<int>();
    }
    stack<int> s;
    vector<int> res(stock.size());
    s.push(0);
    res[0] = 1;
    for(int i=1;i<stock.size();i++){
        while(!s.empty() && stock[s.top()] <= stock[i])
            s.pop();
        res[i] = (s.empty()) ? i+1 : (i-s.top());
        s.push(i);
    }
    return res;
}

int main() {
	int t;cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> stock(n);
	    for(int i=0;i<n;i++){
	        cin>>stock[i];
	    }
	    //vector<int> res = NextGreaterElementOnLeft(stock);
        vector<int> res = calc(stock);
	    for(int i=0;i<res.size();i++){
	        cout<<res[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}