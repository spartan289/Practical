#include <bits/stdc++.h>

using namespace std;

class DSU
{
public:
    int *parent;
    int *rank;

    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }
    int unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s1] += rank[s2];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Node
{

public:
    int data;
    int weight;
    Node *next;
    Node(int data, int weight)
    {
        this->data = data;
        this->weight = weight;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void push_back(int data, int weight)
    {
        if (head == NULL)
        {
            head = new Node(data, weight);
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(data, weight);
    }
};
class Graph
{
public:
    int vertex;
    LinkedList *adj = new LinkedList[vertex];

public:
    Graph(int v)
    {
        vertex = v;
    }
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(v, w);
        adj[v].push_back(u, w);
    }

    void krsukal_mst()
    {
        vector<vector<int>> sortedlist;
        for (int i = 0; i < vertex; i++)
        {
            Node *temp = adj[i].head;
            while (temp != NULL)
            {
                sortedlist.push_back({temp->weight, i, temp->data});
                temp = temp->next;
            }
        }
        int ans = 0;
        sort(sortedlist.begin(), sortedlist.end());
        DSU s(vertex);
        for (auto edge : sortedlist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
                cout << x << "--" << y << endl;
            }
        }
        cout << "Minimum spanning tree cost " << ans;
    }
};

int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.krsukal_mst();
}