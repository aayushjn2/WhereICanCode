#include<bits/stdc++.h>
using namespace std;
class Point{
    public:
        int x,y;
}
int crossProduct(Point A, Point B, Point C){
    Point AB,BC;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    BC.x = C.x - B.x;
    BC.y = C.y - B.y;
    int cross = AB.x*BC.y - AB.y*BC.x;
    return cross;
}

int main(){
    Point A,B,C;
    cout<<"Coordinates for point A"<<endl;
    cin>>A.x>>A.y;
    cout<<"Coordinates for point B"<<endl;
    cin>>B.x>>B.y;
    cout<<<"Coordinated for point C"<<endl;
    cin>>C.x>>C.y;
    int crossProductValue = crossProduct(A,B,C);
    return 0;
}