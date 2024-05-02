#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
    int t,n,a,result;
    cin>>t;
    vector<int> candy;
    for(int i = 0;i < t;i++){
        cin>>n>>a;
        candy.assign(n,0);
        for(int i = 0;i < n;i++){
            cin>>candy[i];
        }
        sort(candy.begin(),candy.end(),greater<int>());
        result = 2147483647;
        for(int i = 0; i < candy.size(); i++){
			if (i + (a-1) < candy.size()){
				result = min(candy[i] - candy[i+(a-1)],result);
			}
		}
        cout<<"#"<<i+1<<" "<<result<<endl;
    }
    return 0;
}