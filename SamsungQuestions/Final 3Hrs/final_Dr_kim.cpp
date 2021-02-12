/*
5 (Starting test case #1)
0 0 100 100 70 40 30 10 10 5 90 70 50 20
#1 => 200

6 (Starting test case #2)
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
#2 => 304
10
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36
#3 => 366
*/

#include <iostream>
#include <climits>
using namespace std;
bool visited[11];

struct coordinate
{
    int x;
    int y;
};

int dist(coordinate one, coordinate two)
{
    return (abs(one.x - two.x) + abs(one.y - two.y));
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int solve(coordinate current, coordinate home, coordinate customer[], int n, int cnt)
{
    if (n == cnt)
    {
        return dist(current, home);
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            int val = dist(current, customer[i]);
            int temp = solve(customer[i], home, customer, n, cnt + 1);
            ans = min(ans, val + temp);
            visited[i] = false;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        coordinate customer[11];
        coordinate office;
        coordinate home;
        cin >> office.x >> office.y;
        cin >> home.x >> home.y;
        for (int i = 0; i < n; i++)
        {
            cin >> customer[i].x >> customer[i].y;
            visited[i] = false;
        }
        int ans = solve(office, home, customer, n, 0);
        cout << ans << endl;
    }
    return 0;
}