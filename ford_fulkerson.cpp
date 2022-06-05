#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define V 6

bool bfs(int graph[V][V], int s, int t, int parent[]){
    bool visited[V];
    for(int i = 0; i<V; i++) visited[i] = 0;

    queue<int> q;
    visited[s] = true;
    q.push(s);
    parent[s] = -1;
    // cout<<s<<" ";

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 0; v<V; v++){
            if(visited[v]==false && graph[u][v]>0){
                visited[v] = true;
                q.push(v);
                parent[v] = u;
                // cout<<v<<" ";
            }
        }
    }
    return (visited[t]==true);
}

int ford_fulkerson(int graph[V][V], int s, int t){
    int rgraph[V][V];
    for(int u=0; u<V; u++){
        for(int v=0; v<V; v++){
            rgraph[u][v] = graph[u][v];
        }
    }

    int max_flow = 0;
    int parent[V];
    
    bool bb = bfs(rgraph, s, t, parent);

    while(bfs(rgraph, s, t, parent)){
        int path_flow = INT_MAX;
        for(int v=t; v!=s; v=parent[v]){
            int u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }

        for(int v=t; v!=s; v=parent[v]){
            int u = parent[v];
            rgraph[u][v]-=path_flow;
            rgraph[v][u]+=path_flow;
        }
        // cout<<path_flow<<endl;
        max_flow+=path_flow;
    }

    return max_flow;
}


int main(){

    int graph[6][6] = {{0, 8, 0, 0, 3, 0},
                    {0, 0, 9, 0 ,0 ,0},
                    {0, 0, 0, 0, 7, 2},
                    {0, 0, 0, 0, 0, 5},
                    {0, 0, 7, 4, 0, 0},
                    {0, 0, 0, 0, 0, 0}};
    
    int max_flow = ford_fulkerson(graph, 0, 5);
    cout<<"max flow: "<<max_flow<<endl;
    return 0;
}