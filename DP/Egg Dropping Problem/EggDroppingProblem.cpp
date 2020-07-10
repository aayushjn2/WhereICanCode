#include<bits/stdc++.h>
using namespace std;
int eggTrials(int eggs, int floors){
    int mem[floors+1][eggs+1];
    for(int egg=0;egg<=eggs;egg++){
        mem[0][egg] = 0;
        mem[1][egg] = 1;
    }
    for(int floor=0;floor<=floors;floor++){
        mem[floor][0] = 0;
        mem[floor][1] = floor;
    }
    for(int floor=2;floor<=floors;floor++){
        for(int egg=2;egg<=eggs;egg++){
            mem[floor][egg] = INT_MAX;
            for(int x=1;x<floor;x++){
                int res = max(mem[x-1][egg-1],mem[floor-x][egg]) + 1;
                if(res < mem[floor][egg])
                    mem[floor][egg] = res;
            }
        }
    }
    return mem[floors][eggs];
}

int main(){ 
    int eggs,floors;
    cout<<"Enter total eggs and then floors";
    cin>>eggs>>floors;
    int trials;
    trials = eggTrials(eggs,floors);
    cout<<"Total number of trials required "<<trials<<endl;
    return 0;
}