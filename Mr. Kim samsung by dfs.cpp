#include<iostream>
using namespace std;
int x[20],y[20],n,ans;

int abs(int i){//Absolute function
	if(i>0){
		return i;
	}
	return -i;
}

int dist(int i, int j){//Calc dist between 2 points
    int x1 = x[i], x2 = x[j];
    int y1 = y[i], y2 = y[j];

    return (abs(x1-x2) + abs(y1-y2));
}

// basically permutation

void optimalPath(int now,bool visited[],int nodes,int value){
	if(n == nodes){//If number of nodes equal n then set value of answer
		ans = min(ans,value + dist(now,n+1));
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			visited[i] = true;
			optimalPath(i,visited,nodes+1,value + dist(now,i)); //Dfs call
			visited[i] = false;
		}
	}
}

int main()
{
	int tCases;
	cin >> tCases;
	for(int i=0;i<tCases;i++){
		ans = 100000000;  //Set ans to max value
		cin >> n;
		cin >> x[n+1] >> y[n+1] >> x[0] >> y[0];//Input destination and source now,y coordinates

		for(int i=1;i<=n;i++){//Input drop off location coordinates
			cin >> x[i] >> y[i];
		}

		bool visited[n+2];
		for(int i=0;i<n+2;i++) visited[i] = false;

		optimalPath(0,visited,0,0);

		cout << "#" << i+1 << " " << ans << endl;
	}
	return 0;
}
