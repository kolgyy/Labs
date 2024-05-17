// Алгоритм Беллмана - Форда:
// Имеет сложность O(V * E), где V — количество вершин, E — количество рёбер.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int INF = 1e9; // Бесконечность для хранения бесконечно больших значений

// Структура для представления ребра графа
struct Edge {
    int from, to, weight;
};

void BellmanFord(vector<vector<int>>& graph, int startVertex) {
    int V = graph.size(); // Количество вершин в графе
    vector<int> dist(V, INF); // Инициализация расстояний до всех вершин как бесконечность
    dist[startVertex] = 0; // Расстояние до начальной вершины равно 0

    // Релаксация всех ребер V-1 раз
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) { //  Внутренние циклы перебирают все возможные пары вершин u и v в графе.
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) { /* Условие проверяет, существует ли ребро между вершинами u и v
                    ,и если текущее расстояние до вершины u плюс вес ребра между u и v меньше текущего расстояния до вершины v
                    , то мы обновляем расстояние до вершины v значением dist[u] + graph[u][v].
                    Это условие проверяет, можно ли улучшить текущее известное расстояние до вершины v, используя ребро от вершины u.*/
                    dist[v] = dist[u] + graph[u][v]; // Обновление расстояния до вершины v
                }
            }
        }
    }


    // Запись результатов в файл
    ofstream output("output.txt");
    for (int i = 0; i < V; ++i) {
        output << "Расстояние от вершины " << startVertex << " до вершины " << i << " равно " << dist[i] << endl;
    }
}

int main() {
    ifstream input("configuration/input.txt");

    int V;
    input >> V; // Считываем количество вершин

    vector<vector<int>> graph(V, vector<int>(V));

    // Считывание матрицы смежности из файла
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            input >> graph[i][j]; // Заполняем матрицу смежности
        }
    }

    int startVertex = 0; // Начальная вершина для поиска кратчайших путей

    BellmanFord(graph, startVertex); // Запускаем алгоритм Беллмана-Форда

    return 0;
}
