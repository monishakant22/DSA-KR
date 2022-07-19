#include <bits/stdc++.h>
using namespace std;
struct Graph
{
    int n;
    int G[100][100];
    Graph(int k)
    {
        n = k;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = 0;
    }
    void add(int u, int v);
    void DFS(int s, int &k, bool visited[], int a[], int low[], int parent[]);
    void articulation_points();
    void ArticulationDFT(int v, int &k, bool visites[], int num[], int low[], int parent[]);
};
void Graph::add(int u, int v)
{
    G[u][v] = 1;
    G[v][u] = 1;
}
vector<int> vertex;
void Graph::DFS(int v, int &k, bool visited[], int num[], int low[], int parent[])
{
    int child = 0;
    visited[v] = true;
    num[v] = low[v] = k++;
    for (int i = 0; i < n; i++)
    {
        if (G[v][i])
        {
            if (visited[i] == 0)
            {
                child++;
                cout << i << " a " << child << endl;
                parent[i] = v;
                DFS(i, k, visited, num, low, parent);
                low[v] = min(low[v], low[i]);
                if (parent[v] == -1 && child > 1)
                    vertex.push_back(v);
                if (parent[v] != -1 && low[i] >= num[v])
                    vertex.push_back(v);
            }
            else if (i != parent[v])
                low[v] = min(low[v], num[i]);
        }
    }
}
void Graph::articulation_points()
{
    int num[n], low[n], parent[n];
    memset(low, 0, sizeof(low));
    memset(parent, -1, sizeof(parent));
    int k = 0;
    bool visited[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            DFS(i, k, visited, num, low, parent);
    }
    sort(vertex.begin(), vertex.end());
    vector<int>::iterator it;
    it = unique(vertex.begin(), vertex.end());
    vertex.resize(distance(vertex.begin(), it));
    for (int i = 0; i < vertex.size(); i++)
        cout << vertex[i] << " ";
    cout << endl;
}
void Graph::ArticulationDFT(int v, int &k, bool visited[], int num[], int low[], int parent[])
{
    visited[v] = false;
    num[v] = low[v] = k++;
    for (int i = 0; i < n; i++)
    {
        if (G[v][i])
        {
            if (visited[i] == 0)
            {
                parent[i] = v;
                ArticulationDFT(i, k, visited, num, low, parent);
                low[v] = min(low[v], low[i]);
                if (num[v] < low[i])
                    cout << v << " " << i << endl;
            }
            else if (i != parent[v])
                low[v] = min(low[v], num[i]);
        }
    }
}
int main()
{
    int n = 7;
    Graph G(n);
    // G.add(6,6);
    G.add(0, 1);
    G.add(0, 2);
    G.add(0, 3);
    G.add(1, 2);
    G.add(3, 4);
    G.add(3, 5);
    G.articulation_points();
    return 0;
}
