#include<bits/stdc++.h>
using namespace std;
class Point{
    public:
        int x,y;
}
int dotProduct(Point A, Point B, Point C){
    Point AB,BC;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    BC.x = C.x - B.x;
    BC.y = C.y - B.y;
    int dot = AB.x*BC.x + AB.y*BC.y;
    return dot;
}

int main(){
    Point A,B,C;
    cout<<"Coordinates for point A"<<endl;
    cin>>A.x>>A.y;
    cout<<"Coordinates for point B"<<endl;
    cin>>B.x>>B.y;
    cout<<<"Coordinated for point C"<<endl;
    cin>>C.x>>C.y;
    int dotProductValue = dotProduct(A,B,C);
    return 0;
}