#include<iostream>
#define ull unsigned long long

using namespace std;

int main(void){
    int t;
    ull n,a,b,c;
    cin>>t;
    for(int i = 1;i <= t;i++){   
        cin>>n;
        a = n*(n+1)/2;
        b = n*(2+(n-1)*2)/2;
        c = n*(4+(n-1)*2)/2; 
        cout<<"#"<<i<<" "<<a<<" "<<b<<" "<<c<<" "<<endl;
    }
    return 0;
}