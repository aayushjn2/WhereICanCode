/*
A Research team want to establish a research center in a region where they found some rare-elements. They want to make it closest to all the rare-elements as close as possible so that they can reduce overall cost of research over there. It is given that all the rare-element’s location is connected by roads. It is also given that Research Center can only be build on road. Team decided to assign this task to a coder. If you feel you have that much potential..
Here is the Task :- Find the shortest of the longest distance of research center from given locations of rare-elements.
Locations are given in the matrix cell form where 1 represents roads and 0 no road.. Number of rare-element and their location was also given(number<=5) and order of square matrix was less than equal to (20).
*/
/*
https://www.careercup.com/question?id=5707238197952512
https://practice.geeksforgeeks.org/problems/how-to-solve-this-bfs-problem-asked-in-samsung
https://discuss.codechef.com/t/samsung-question-geeksforgeeks/17092

1 Bsed -> https://sapphireengine.com/@/4q0evk - Ajay Verma
0 Bsed -> https://sapphireengine.com/@/iha4kq - Thusoo
*/

/*
For this you have to implement bfs for every position where road exist to find the distance of 
every research center or do Vice-versa. for each position store maximum distance of all distances
to research center and the compare each maximum distance to find minimum of them

Input - 
6
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
5 2
2 1
3 5
1 0 1 1 1
1 1 1 0 1
0 1 1 0 1
0 1 0 1 1
1 1 1 0 1

Output - 
1
2
2
12
15
4
*/

#include <iostream>
using namespace std;

struct Node{
    int x;
    int y;
    int level;
};

Node queue[100000];

int front = 0, back = 0;
int region[10000][10000];
int rare[4][2];
int n;
int c;
bool visited[10000][10000];

int dir_xx[] = {-1, 0, 1, 0};
int dir_yy[] = {0, 1, 0, -1};

void intializeQueue(){
    front = back = 0;
}

void insert(int x, int y, int level){
    queue[back].x = x;
    queue[back].y = y;
    queue[back].level = level;
    back++;
}

Node pop(){
    return queue[front++];
}

bool empty()
{
    return (front == back);
}

bool valid(int r, int c)
{
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int bfs(int sx, int sy, int dx, int dy)
{
    insert(sx, sy, 0);
    visited[sx][sy] = true;
    while (!empty())
    {
        Node frontNode = pop();
        if (frontNode.x == dx && frontNode.y == dy)
        {
            return frontNode.level;
        }
        for (int i = 0; i < 4; i++)
        {
            int new_x = frontNode.x + dir_xx[i];
            int new_y = frontNode.y + dir_yy[i];
            int new_level = frontNode.level + 1;
            if (valid(new_x, new_y))
            {
                if (region[new_x][new_y] == 1 && visited[new_x][new_y] == false)
                {
                    insert(new_x, new_y, new_level);
                    visited[new_x][new_y] = true;
                }
            }
        }
    }
}

int max(int x, int y){
    return x > y ? x : y;
}

int min(int x, int y){
    return x < y ? x : y;
}

void intializeVisitedMatrix(){
    for (int l = 0; l < 100; l++){
        for (int m = 0; m < 100; m++){
            visited[l][m] = false;
        }
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> c;
        intializeQueue();

        for (int i = 0; i < c; i++){
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            rare[i][0] = x;
            rare[i][1] = y;
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                cin >> region[i][j];
        }

        int ans = 100000;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int temp;
                if (region[i][j] == 1){
                    temp = 0;
                    for (int k = 0; k < c; k++){
                        intializeQueue();
                        intializeVisitedMatrix();
                        int res = bfs(i, j, rare[k][0], rare[k][1]);
                        temp = max(res, temp);
                    }
                    ans = min(ans, temp);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}