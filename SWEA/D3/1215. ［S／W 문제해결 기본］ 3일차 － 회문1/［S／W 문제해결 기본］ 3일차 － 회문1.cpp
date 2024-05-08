#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    string s;
    int x,count;
    for(int a = 0;a < 10;a++){
        count = 0;
        cin>>x;
        vector<string> text;
        for(int i = 0;i < 8;i++){
            cin>>s;
            text.push_back(s);
        }
        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8-x+1;j++){
                string temp = "";
                for(int k = j;k < j+x;k++){
                    temp+=text[i][k];
                }
                string check = temp;
                reverse(temp.begin(),temp.end());
                if(check.compare(temp) == 0){
                    count++;
                }
            }
            for(int j = 0;j < 8-x+1;j++){
                string temp = "";
                for(int k = j;k < j+x;k++){
                    temp+=text[k][i];
                }
                string check = temp;
                reverse(temp.begin(),temp.end());
                if(check.compare(temp) == 0){
                    count++;
                }
            }
        }
        cout<<"#"<<a+1<<" "<<count<<endl;
    }
    return 0;
}