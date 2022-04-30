#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

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

    void push_back(int data, int w)
    {
        if (head == NULL)
        {
            head = new Node(data, w);
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(data, w);
    }
};
class Graph
{
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
    void ShortestPath(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(vertex, INF);
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty())
        {

            int u = pq.top().second;
            pq.pop();
            Node *temp = adj[u].head;
            while (temp != NULL)
            {
                int v = temp->data;
                int weight = temp->weight;

                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
                temp = temp->next;
            }
        }

        cout << "Vertex distance from Source\n";
        for (int i = 0; i < vertex; i++)
        {
            cout << i << "\t\t" << dist[i] << "\n";
        }
    }
};

int main()
{
    int V = 9;
    Graph g(V);

    //  making above shown graph
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

    g.ShortestPath(0);
}