#include <iostream>
#include <queue>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int infinity = numeric_limits<int>::max();

struct Node
{
    string name;
    int weight;
    Node* sibling;

    Node(const string& nm, int w, Node* s = 0)
        : name(nm), weight(w), sibling(s) {}
};


unordered_map<string, int> BellmanFord(const unordered_map<string, Node*>& graph, const string& start)
{
    unordered_map<string, int> dist;
    for (auto vertex : graph)
        dist[vertex.first] = start == vertex.first ? 0 : infinity;

    unordered_set<string> visited;
    queue<string> q;
    q.push(start);
    while (!q.empty())
    {
        string vertex = q.front();
        q.pop();

        if (visited.find(vertex) != visited.end())
            continue;

        for (auto ch = graph.at(vertex); ch; ch = ch->sibling)
        {
            dist[ch->name] = min(dist[ch->name], ch->weight + dist[vertex]);
            if (ch->name != vertex)
                q.push(ch->name);
        }

        visited.insert(vertex);
    }

    return dist;
}

int main()
{
    unordered_map<string, Node*> graph;
    graph["A"] = new Node("B", -1, new Node("C", 4));
    graph["B"] = new Node("C",3, new Node("D", 2, new Node("E", 2)));
    graph["C"] = 0;
    graph["D"] = new Node("B", 1, new Node("C", 5));
    graph["E"] = new Node("D", -3);

    for (auto vertex : graph)
    {
        string startNodeName = vertex.first;

        unordered_map<string, int> distances = BellmanFord(graph, startNodeName);
        for (auto d = distances.begin(); d != distances.end(); ++d)
        {
            cout << "From " << startNodeName << " to " << d->first << " is ";
            if (d->second != infinity)
                cout << d->second << endl;
            else
                cout << "oo" << endl;
        }

        cout << endl;
    }
}
