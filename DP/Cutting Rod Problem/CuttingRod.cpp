#include <bits/stdc++.h>
using namespace std;
// link 1 :  https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
int calMaxSellingPrice(int price[], int rodLength)
{
    int mem[rodLength + 1];
    mem[0] = 0;
    for (int eachLength = 1; eachLength <= rodLength; eachLength++)
    {
        int max_val = INT_MIN;
        for (int tillLength = 0; tillLength < eachLength; tillLength++)
        {
            max_val = max(max_val, price[tillLength] + mem[eachLength - tillLength - 1]);
        }
        mem[eachLength] = max_val;
        cout << mem[eachLength] << " ";
    }
    cout << endl;
    return mem[rodLength];
}

//  link 2 : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
int minCostCutStick()
{
}
int main()
{
    int rodLength;
    cin >> rodLength;
    int price[rodLength];
    for (int i = 0; i < rodLength; i++)
        cin >> price[i];
    cout << calMaxSellingPrice(price, rodLength);
    return 0;
}