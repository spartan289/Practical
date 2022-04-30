#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
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

    void push_back(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(data);
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
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS()
    {
        bool visited[vertex] = {false};
        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
                DFSutil(i, visited);
        }
    }
    void DFSutil(int i, bool visited[])
    {
        visited[i] = true;
        cout << i << " ";
        Node *temp = adj[i].head;
        while (temp != NULL)
        {
            if (!visited[temp->data])
            {
                DFSutil(temp->data, visited);
            }
            temp = temp->next;
        }
    }
};

int main()
{
    Graph g(9);

    g.addEdge(0, 1);
    g.addEdge(0, 7);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 3);
    g.addEdge(2, 8);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 8);

    g.DFS();
}