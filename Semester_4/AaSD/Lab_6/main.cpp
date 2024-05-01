#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

// Алгоритм Краскала
// В данной реализации алгоритма, где ребра сначала сортируются по весу, а затем обрабатываются по порядку, 
// сложность сортировки ребер составляет O(E logE), где E - количество ребер. 
// Затем производится обработка каждого ребра, что занимает O(E)операций. 
using namespace std;

// Структура для представления ребра графа
struct Edge {
    int src, dest, weight;
};

// Функция для сравнения ребер по весу
bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

// Функция для нахождения корня вершины в лесу (сжатие пути)
int findRoot(vector<int>& parent, int vertex) {
    if (parent[vertex] == -1) {
        return vertex;
    }
    return parent[vertex] = findRoot(parent, parent[vertex]);
}

// Функция для выполнения алгоритма Крускала
void kruskalMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<Edge> edges;

    // Создаем список ребер из матрицы смежности
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (graph[i][j] != 0) {
                edges.push_back({ i, j, graph[i][j] });
            }
        }
    }

    // Сортируем ребра по весу
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(V, -1); // Вектор для хранения родителей вершин

    vector<Edge> result; // Вектор для хранения ребер минимального покрывающего дерева
    int edgeCount = 0;
    int i = 0;

    // Применяем алгоритм Крускала
    while (edgeCount < V - 1 && i < edges.size()) {
        Edge nextEdge = edges[i++];
        int rootSrc = findRoot(parent, nextEdge.src);
        int rootDest = findRoot(parent, nextEdge.dest);

        // Проверяем, не принадлежат ли вершины одному дереву
        if (rootSrc != rootDest) {
            result.push_back(nextEdge);
            ++edgeCount;
            parent[rootSrc] = rootDest; // Объединяем деревья
        }
    }

    // Записываем ребра минимального покрывающего дерева в файл
    ofstream outFile("output.txt");
    for (const Edge& edge : result) {
        outFile << edge.src << " " << edge.dest << " WEIGHT: " << edge.weight << endl;
    }
}

int main() {
    ifstream inFile("configuration/input.txt");
    int V;
    inFile >> V;

    // Чтение матрицы смежности из файла
    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            inFile >> graph[i][j];
        }
    }

    kruskalMST(graph); // Вызов функции для выполнения алгоритма Крускала

    return 0;
}
