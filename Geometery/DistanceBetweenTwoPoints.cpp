#include<bits/stdc++.h>
using namespace std;
class Point{
    public:
        int x,y;
}

double distance(Point A, Point B){
    int d1 = A.x - B.x;
    int d2 = A.y - B.y;
    return sqrt(d1*d1+d2*d2);
}

int main(){
    Point A,B,C;
    cout<<"Coordinates for point A"<<endl;
    cin>>A.x>>A.y;
    cout<<"Coordinates for point B"<<endl;
    cin>>B.x>>B.y;
    cout<<<"Coordinated for point C"<<endl;
    cin>>C.x>>C.y;
    double dist = distance(A,B);
    return 0;
}