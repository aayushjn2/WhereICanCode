#include <bits/stdc++.h>
using namespace std;
bool sortFirstAscSecondAsc(const pair<int, int> &a, const pair<int, int> &b)
{
    //ascending order by first element
    if (a.first < b.first)
        return true;
    else if (a.first > b.first)
        return false;
    else
    {
        //ascending order by first element
        if (a.second < b.second)
            return true;
        else
            return false;
    }
}

bool sortFirstAscSecondDsc(const pair<int, int> &a, const pair<int, int> &b)
{
    //ascending order by first element
    if (a.first < b.first)
        return true;
    else if (a.first > b.first)
        return false;
    else
    {
        //ascending order by first element
        if (a.second > b.second)
            return true;
        else
            return false;
    }
}

void printVector(vector<int> &A)
{
    for (auto val : A)
        cout << val << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    // vector<int> A(n);
    // for(int i = 0;i<n;i++){
    //     cin>>A[i];
    // }
    // printVector(A);
    // //sort vector in ascending order
    // sort(A.begin(), A.end());
    // printVector(A);

    // //sort vector in descending order
    // sort(A.begin(), A.end(), greater<int>());
    // printVector(A);

    /*Vector of pairs -> A pair is a container which stores two values mapped to each other,
     and a vector containing multiple number of such pairs is called a vector of pairs. */

    vector<pair<int, int>> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i].first >> B[i].second;
    }
    cout << "Vector B is :" << endl;
    for (auto pair_ : B)
        cout << pair_.first << " " << pair_.second << endl;

    //first(ascending), second(ascending)
    sort(B.begin(), B.end());

    //first(ascending), second(descending);

    cout << "After sorting Vector B is :" << endl;
    for (auto pair_ : B)
        cout << pair_.first << " " << pair_.second << endl;

    sort(B.begin(), B.end(),sortFirstAscSecondAsc);
    cout << "After sorting vector B in ascending order by first element and in ascending order by second :" << endl;
    for (auto pair_ : B)
        cout << pair_.first << " " << pair_.second << endl;

    sort(B.begin(), B.end(),sortFirstAscSecondDsc);
    cout << "After sorting vector B in ascending order by first element and in descending order by second :" << endl;
    for (auto pair_ : B)
        cout << pair_.first << " " << pair_.second << endl;
    return 0;
}

/*
    
*/