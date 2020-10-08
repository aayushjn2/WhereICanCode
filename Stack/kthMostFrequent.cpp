#include <bits/stdc++.h> 
using namespace std; 
bool sortByVal(const pair<char, int>& a, 
               const pair<char, int>& b) 
{ 
    return a.second > b.second; 
} 

string KFrequency(string str, int k){
    map<char, int> m;
    for (int i = 0; i < str.length(); ++i) 
        m[str[i]]++; 
    vector<pair<char, int> > v; 
    copy(m.begin(), m.end(), back_inserter(v));  
    sort(v.begin(), v.end(), sortByVal);
    int count = 0;
    string res = ""; 
    for (int i = 0; i < v.size(); i++) { 

        if (i == 0 || v[i].second != v[i - 1].second) 
            count++; 
  
        if (count == k){
            res += v[i].first; i++;
            while(i < v.size() && v[i].second == v[i-1].second){
                res +=v[i].first;
                i++;
            }
            sort(res.begin(), res.end());
            return res;
        }
    } 
    return "-1";
} 

int main() 
{ 
    string str = "geeksforgeeks"; 
    int k = 3; 
    string res = sortByFreq(str, k);
    if(res.size() == 0){
        cout<<-1<<endl;
    }
    else{
        cout<< res<<endl;
    }
    return 0; 
}