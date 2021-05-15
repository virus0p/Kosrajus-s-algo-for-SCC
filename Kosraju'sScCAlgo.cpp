#include <bits/stdc++.h>
using namespace std;


void dfs(int node,vector<int> graph[],bool*visited,vector<int> &st){
	visited[node] = true;

	for(auto x:graph[node]){
		if(!visited[x]){
			dfs(x,graph,visited,st);
		}
	}

	st.push_back(node);
}
void dfs2(int node,vector<int> graph[],bool*visited){
	visited[node] = true;
	cout << node <<"->";
	for( auto x:graph[node]){
		if(!visited[x]){
			dfs2(x,graph,visited);
		}
	}

}

void solve(vector<int> graph[],vector<int> reverse[],int N){
      bool visited[N];
      memset(visited,0,N);

      std::vector<int> st;

      //store the vertices acc to dfs finish time
      for(int i=0;i<N;i++){
      	 if(!visited[i]){
      	 	dfs(i,graph,visited,st);
      	 }
      }

      // initiate dfs from end of the st
      memset(visited,0,N);
      char component = 'A';
      for(int i=st.size()-1;i >=0;i--){
      	  
      	  int node  = st[i];
      	  if(!visited[node]){
      	  	cout << "component "<<component<<" --> ";
      	  	dfs2(node,reverse,visited);
      	  	cout <<"\n";
      	  	component++;
      	  }
      }
}

int main(){
	int N; cin >> N;
	int M; cin >> M;
	vector<int> graph[N];
	std::vector<int> reverse[N];

	while(M--){
		int x,y; cin >> x >> y;
		graph[x].push_back(y);
		reverse[y].push_back(x);
	}

    solve(graph,reverse,N);
}