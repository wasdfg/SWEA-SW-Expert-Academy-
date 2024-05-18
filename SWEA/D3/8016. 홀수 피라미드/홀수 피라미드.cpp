#include<iostream>
#define ull unsigned long long

using namespace std;

int main(void){
    int t;
    ull n,a,b;
    cin>>t;
    for(int i = 1;i <= t;i++){   
        cin>>n;
        a = 1+(n-1)*(4+(n-2)*4)/2;
        b = 1+(n-1)*(12+(n-2)*4)/2;
        cout<<"#"<<i<<" "<<a<<" "<<b<<endl;
    }
    return 0;
}