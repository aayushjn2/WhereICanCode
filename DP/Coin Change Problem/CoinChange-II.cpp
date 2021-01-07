//Problem Link : https://leetcode.com/problems/coin-change/
//complexity will be O(coins.size()*amount)
//Space Complexity : O(coins.size()*amount)
//NOTE : space will highly depend on amount variable.
#include <bits/stdc++.h>
using namespace std;
// Idea: include and exclude the concept of each coin
// if ( j - coins[i-1] >=0 ) : we need to include that (i-1)th  coin
// and now take select minimum coins that make jth amount.
//this can be done by taking min of 1 + mem[i][j-coins[i-1]]and  mem[i-1][j]
int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    if (coins.size() == 0)
        return 0;
    int mem[coins.size() + 1][amount + 1];
    for (int i = 0; i <= amount; i++)
        mem[0][i] = INT_MAX;
    for (int i = 0; i <= coins.size(); i++)
        mem[i][0] = 0;

    for (int i = 1; i <= coins.size(); i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (j - coins[i - 1] >= 0)
            {
                if (mem[i][j - coins[i - 1]] == INT_MAX)
                    mem[i][j - coins[i - 1]]--;
                mem[i][j] = min(1 + mem[i][j - coins[i - 1]], mem[i - 1][j]);
            }
            else
            {
                mem[i][j] = mem[i - 1][j];
            }
        }
    }
    return mem[coins.size()][amount] == INT_MAX ? -1 : mem[coins.size()][amount];
}
int main()
{
    int amount;
    cin >> amount;
    int n;
    cin > n;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }
    cout << change(amount, coins);
    return 0;
}