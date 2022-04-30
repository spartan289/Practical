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

    void prims(int s)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> key(vertex, INF);
        vector<int> parent(vertex, -1);
        vector<bool> inMST(vertex, false);

        pq.push(make_pair(0, s));
        key[s] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u])
            {
                continue;
            }
            inMST[u] = true;
            Node *temp = adj[u].head;
            while (temp != NULL)
            {
                int v = temp->data;
                int weight = temp->data;

                if (!inMST[v] && key[v] > weight)
                {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
                temp = temp->next;
            }
        }

        for (int i = 1; i < vertex; i++)
        {
            printf("%d - %d\n", parent[i], i);
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

    g.prims(0);
}