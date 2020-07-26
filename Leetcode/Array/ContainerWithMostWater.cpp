#include<bits/stdc++.h>
using namespace std;
//Idea : need to maximise distance and maximum smaller height among two.
int maxArea(vector<int>& height) {
    int res  = 0;
    int n = height.size();
    int i=0,j=n-1;
    while(i<j){
        int amount = (j-i)*min(height[j],height[i]);
        res = max(res,amount);
        if(height[i]<height[j])i++;
        else j--;
    }
    return res;
}

int main(){
    int n;cin>>n;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    int maxA = maxArea(height);
    cout<<"Maximum Area of container is "<<maxA<<endl;
    return 0;
}