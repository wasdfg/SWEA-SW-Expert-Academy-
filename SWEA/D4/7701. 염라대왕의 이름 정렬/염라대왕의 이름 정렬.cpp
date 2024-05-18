#include<iostream>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

struct compare {
	bool operator() (const string &a, const string &b) const{
		if (a.size() == b.size())
			return a < b;
		else
			return a.size() < b.size();
	}
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    for(int i = 1;i <= t;i++){
        cin>>n;
        set<string,compare> count;
        for(int j = 0;j < n;j++){
            cin>>s;
            count.insert(s);
        }
        cout<<"#"<<i<<'\n';
        for(auto a = count.begin();a != count.end();a++){
            cout<<*a<<'\n';
        }
    }
    return 0;
}