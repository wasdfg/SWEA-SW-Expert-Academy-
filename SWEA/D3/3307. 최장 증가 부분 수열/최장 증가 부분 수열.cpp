#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int t,n;
    cin>>t;
    for(int i = 1;i <= t;i++){
        cin>>n;
        vector<int> num(n,0);
        vector<int> lis;
        for(int j = 0;j < n;j++){
            cin>>num[j];
        }
        for(int j = 0;j < n;j++){
            if(lis.empty() || lis.back() < num[j]){
                lis.push_back(num[j]);
            }
            else{
                int x = lower_bound(lis.begin(),lis.end(),num[j])-lis.begin();
                lis[x] = num[j];
            }
        }
        cout<<"#"<<i<<" "<<lis.size()<<endl;
    }
    return 0;
}