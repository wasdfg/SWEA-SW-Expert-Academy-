#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
    int n,w;
    for(int i = 0;i < 10;i++){
        stack<int> num;
        cin>>n;
        for(int a = 0;a < n;a++){
            scanf("%1d",&w);
            if(num.empty() || w != num.top()){
                num.push(w);
            }
            else{
                num.pop();
            }
        }
        string s = "";
        while(!num.empty()){
            s+=to_string(num.top());
            num.pop();
        }
        reverse(s.begin(),s.end());
        cout<<"#"<<i+1<<" "<<s<<endl;
    }
    return 0;
}