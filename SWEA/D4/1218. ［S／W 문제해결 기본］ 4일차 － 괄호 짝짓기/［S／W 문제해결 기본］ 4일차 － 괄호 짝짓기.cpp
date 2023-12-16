#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int len,last;
    char a;
    vector<char> bracket;
    for(int i = 0;i < 10;i++){
        cin>>len;
        bracket = vector<char>();
        for(int j = 0;j < len;j++){
            cin>>a;
            bracket.push_back(a);
        }
        for(int j = 0;j < bracket.size();j++){
            if(bracket[j] == '>'){
                if(bracket[j-1] == '<'){
                    bracket.erase(bracket.begin()+j);
                    bracket.erase(bracket.begin()+j-1);
                    j-=2;
                }
            }
            else if(bracket[j] == ')'){
                if(bracket[j-1] == '('){
                    bracket.erase(bracket.begin()+j);
                    bracket.erase(bracket.begin()+j-1);
                    j-=2;
                }
            }
            else if(bracket[j] == '}'){
                if(bracket[j-1] == '{'){
                    bracket.erase(bracket.begin()+j);
                    bracket.erase(bracket.begin()+j-1);
                    j-=2;
                }
            }
            else if(bracket[j] == ']'){
                if(bracket[j-1] == '['){
                    bracket.erase(bracket.begin()+j);
                    bracket.erase(bracket.begin()+j-1);
                    j-=2;
                }
            }
        }
        if(!bracket.empty()){
            cout<<"#"<<i+1<<" 0\n";
        }
        else{
        cout<<"#"<<i+1<<" 1\n";
        }
    }
}