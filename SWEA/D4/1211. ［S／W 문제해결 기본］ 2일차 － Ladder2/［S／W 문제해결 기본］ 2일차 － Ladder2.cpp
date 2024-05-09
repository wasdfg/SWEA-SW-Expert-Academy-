#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> ladder;

int dfs(int y){
    int count = 1;
    int x = 0;
    int direct = 0;
    while(1){
        if(direct == 0){
            x++;
            count++;
            while(1){
                if(x == 99){
                    return count;
                }
                if(y-1 >= 0){
                    if(ladder[x][y-1] == 1){
                        direct = 1;
                        break;
                    }
                }
                if(y+1 < 100){
                    if(ladder[x][y+1] == 1){
                        direct = 2;
                        break;
                    }
                }
                x++;
                count++;
            }
        }
        if(direct == 1){
            y--;
            count++;
            while(1){
                if(x+1 < 100){
                    if(ladder[x+1][y] == 1){
                        direct = 0;
                        break;
                    }
                }
                y--;
                count++;
            }
        }
        if(direct == 2){
            y++;
            count++;
            while(1){
                if(x+1 < 100){
                    if(ladder[x+1][y] == 1){
                        direct = 0;
                        break;
                    }
                }
                y++;
                count++;
            }
        }
    }
}

int main(void){
    int t,result,len;
    for(int i = 1;i <= 10;i++){
        cin>>t;
        len = 987654321;
        ladder.assign(100,vector<int>(100,0));
        for(int a = 0;a < 100;a++){
            for(int b = 0;b < 100;b++){
                cin>>ladder[a][b];
            }
        }
        for(int a = 0;a < 100;a++){
            if(ladder[0][a] == 1){
                int check = dfs(a);
                if(check < len){
                    len = check;
                    result = a;
                }
            }
        }
        cout<<"#"<<t<<" "<<result<<endl;
    }
}