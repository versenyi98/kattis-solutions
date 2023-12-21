#include <bits/stdc++.h>

using namespace std;

enum State {
    VISITED,
    UNVISITED,
    VISITING
};

map<string, vector<string>> connections;
map<string, State> state;
map<string, bool> can_reach_cycle;
map<string, string> parent;

void dfs(string node) {
    state[node] = VISITING;

    for (auto neighbour : connections[node]) {
        if (state[neighbour] == UNVISITED) {
            parent[neighbour] = node;
            dfs(neighbour);
        } else if (state[neighbour] == VISITING) {
            string current_city = node;
            can_reach_cycle[current_city] = true;

            do {
                current_city = parent[current_city];
                can_reach_cycle[current_city] = true;
            } while(parent[current_city] != "");
        } else if (state[neighbour] == VISITED) {
            can_reach_cycle[node] |= can_reach_cycle[neighbour];
        }
    }

    state[node] = VISITED;
}

int main() {

    int n;
    cin >> n;

    while (n--) {
        string src, dst;
        cin >> src >> dst;

        connections[src].push_back(dst);
        state[src] = UNVISITED;
        state[dst] = UNVISITED;

        parent[src] = "";
        parent[dst] = "";

        can_reach_cycle[src] = false;
        can_reach_cycle[dst] = false;
    }

    string src;
    while (cin >> src) {
        dfs(src);
        cout << src << (can_reach_cycle[src] ? " safe" : " trapped") << endl;
    }




    return 0;
}