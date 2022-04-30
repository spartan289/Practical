#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
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
            head = new Node(data);
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new Node(data);
        }
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
    void bfs(int s)
    {
        bool *visited = new bool[vertex];
        for (int i = 0; i < vertex; i++)
        {
            visited[i] = false;
        }
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty())
        {
            int tmp = q.front();
            q.pop();
            cout << tmp << " ";
            Node *temp = adj[tmp].head;
            while (temp != NULL)
            {
                if (!visited[temp->data])
                {
                    visited[temp->data] = true;
                    q.push(temp->data);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    g.bfs(3);
}