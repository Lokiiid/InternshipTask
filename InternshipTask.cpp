#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector < vector<int> > graph;
    int nodeCount, start, edgeCount, a, b;
    ifstream f("graph.txt"); // Открывается файл graph.txt находящийся там же где и .cpp файл с кодом программы
    string line;
    if (f.is_open()) {
        getline(f, line);
        nodeCount = stoi(line);
        graph.resize(nodeCount);
        getline(f, line);
        edgeCount = stoi(line);
        for (int i = 0; i < edgeCount; i++) {
            getline(f, line);
            stringstream ss(line);
            ss >> line;
            a = stoi(line);
            ss >> line;
            b = stoi(line);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        getline(f, line);
        start = stoi(line);
    }
    else {
        return 0;
    }
    queue<int> q;
    q.push(start);
    vector<bool> used(nodeCount);
    vector<int> distance(nodeCount);
    used[start] = true;
    distance[start] = 0;
    int current, next;
    while (!q.empty()) {
        current = q.front();
        q.pop();
        for (int i = 0; i < graph[current].size(); i++) {
            next = graph[current][i];
            if (!used[next]) {
                used[next] = true;
                q.push(next);
                distance[next] = distance[current] + 1;
            }
        }
    }
    for (int i = 0; i < nodeCount; i++) {
        cout << distance[i] << endl;
    }
    f.close();
    return 0;
}

