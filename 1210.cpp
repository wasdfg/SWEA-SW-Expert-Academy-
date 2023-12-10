#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> ladder(100,vector<int>(100,0));
int start,now;

int left(){
    if(ladder[now][start-1] == 1 && start-1 >= 0){
        start--;
        left();
    }
    return 0;
}

int right(){
    if(ladder[now][start+1] == 1 && start+1<=99){
        start++;
        right();
    }
    return 0;
}

int main(void){
    int x;
    for(int tcase = 1;tcase <= 10;tcase++){
        cin>>x;
        now = 99;
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            cin>>x;
            ladder[i][j] = x;
        }
    }
    for(int i = 0;i < 100;i++){
        if(ladder[now][i] == 2){
            start = i;
            break;
        }
    }
    while(1){
        if(now == 0){
            break;
        }
        else if(ladder[now][start-1] == 1 && start-1 >= 0){
            left();
        }
        else if(ladder[now][start+1] == 1 && start+1 <= 99){
            right();
        }
            now--;
    }
    cout<<"#"<<tcase<<" "<<start<<endl;
    }
    return 0;
}