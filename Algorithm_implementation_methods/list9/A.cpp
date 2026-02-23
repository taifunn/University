#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int adj[105][105];
int deg[105];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
        deg[u]++;
        deg[v]++;
    }
    int grp = 0;

    while(true){
        vector<int> to_kick;
        for(int i=1; i<=n; i++){
            if(deg[i] == 1){
                to_kick.push_back(i);
            }
        }
        if(to_kick.size() == 0) break;

        grp++;
        for(int u : to_kick){
            deg[u] = 0;
            for(int v=1; v<=n; v++){
                if(adj[u][v]==1){
                    adj[u][v] = 0;
                    adj[v][u] = 0;
                    deg[v]--;
                }
            }
        }
    }
    cout << grp << "\n";
    return 0;
}
