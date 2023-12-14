#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<vector<int>> map1;
vector<vector<int>> check;
queue<pair<int,int>> visit;
int area;
int nx[4] = {0,0,-1,1};
int ny[4] = {1,-1,0,0};

int bfs(){
	while(!visit.empty()){
		int x = visit.front().first;
		int y = visit.front().second;
		visit.pop();
	for(int i = 0;i < 4;i++){
		int dx = x+nx[i];
		int dy = y+ny[i];
		if(dx >= 0 && dx < area && dy >= 0 && dy < area){
			if(check[dx][dy] > map1[dx][dy] + check[x][y]){
				visit.push({dx,dy});
				check[dx][dy] = map1[dx][dy] + check[x][y];
			}
		}
	}
	}
	return 0;
}

int main(void) {
	int tcase;
	cin >> tcase;
	for (int i = 0; i < tcase; i++){
		cin >> area;
		map1.assign(area, vector<int>(area, 0));
		check.assign(area, vector<int>(area,9999999));
		for (int j = 0; j < area; j++) {
			for (int k = 0; k < area; k++) {
				scanf("%1d", &map1[j][k]);
			}
		}
		check[0][0] = 0;
		visit.push({0,0});
		bfs();
		cout << "#" << i + 1 << " " <<check[area-1][area-1]<< endl;
	}
}