#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void){
    int t,n,a,b,c,p;
    vector<int> busstop;
    cin>>t;
    for(int i = 1;i <= t;i++){
        cin>>n;
        busstop.assign(5000,0);
        string s = "";
        for(int j = 0;j < n;j++){
            cin>>a>>b;
            for(int k = a;k <= b;k++){
                busstop[k-1]++;
            }
        }
        cin>>p;
        for(int j = 0;j < p;j++){
            cin>>c;
            s+=to_string(busstop[c-1]);
            s+=" ";
        }
        cout<<"#"<<i<<" "<<s<<endl;
    }
    return 0;
}