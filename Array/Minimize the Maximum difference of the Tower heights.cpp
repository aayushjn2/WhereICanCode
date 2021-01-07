#include<bits/stdc++.h>
using namespace std;
/*
[1,15,10],6 => [1+6, 15-6, 10-6] => [7,9,4] => 5 (answer)
each element has 2 possible values 
2^n cases

add => [6,16,21]
given=>[1,10,15]
sub => [-5,4,9]
*/
int bruteForce(vector<int> &A, int k){
    int n = A.size();
}

// Modifies the array by subtracting/adding k to every element such that the difference 
// between maximum and minimum is minimized 
int method_1(vector<int> &A, int k){
    if (n == 1) 
       return 0; 
  
    // Sort all elements 
    sort(A.begin(), A.end()); 
  
    // Initialize result 
    int ans = A[n-1] - A[0]; 
  
    // Handle corner elements 
    int small = A[0] + k; 
    int big = A[n-1] - k; 
    if (small > big) 
       swap(small, big); 
  
    // Traverse middle elements 
    for (int i = 1; i < n-1; i ++) { 
        int subtract = A[i] - k; 
        int add = A[i] + k;  
  
        // If both subtraction and addition do not change diff 
        if (subtract >= small || add <= big) 
            continue; 
  
        // Either subtraction causes a smaller number or addition causes a greater 
        // number. Update small or big using greedy approach (If big - subtract 
        // causes smaller diff, update small Else update big) 
        if (big - subtract <= add - small) 
            small = subtract; 
        else
            big = add; 
    }
    return  min(ans, big - small); 
} 


int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    int res = bruteForce(A);
    return 0;
}