﻿
/*
Если граф представлен в виде матрицы смежности, то сложность алгоритма Дейкстры составляет O(V^2).

В случае использования очереди с приоритетом (priority queue) на основе кучи (heap), сложность алгоритма будет O((V + E) log V), что является более эффективным способом реализации.
2. Инициализировать массив расстояний до каждой вершины как бесконечность, за исключением стартовой вершины, расстояние до которой равно 0.
3. Инициализировать массив посещенных вершин как пустой.
4. Начать с выбранной стартовой вершины и обновлять расстояния до соседних вершин, если новое расстояние меньше текущего.
5. Повторять шаг 4 для всех вершин.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX; // Константа для представления бесконечности

void dijkstra(vector<vector<int>>& graph, int start) {
    int n = graph.size(); // Определение количества вершин в графе.
    vector<int> distance(n, INF); // Массив расстояний до каждой вершины, изначально заполненный бесконечностями
    vector<bool> visited(n, false); // Массив для отслеживания посещенных вершин

    distance[start] = 0; // Расстояние до стартовой вершины равно 0

    for (int i = 0; i < n; ++i) {
        int min_distance = INF; // Инициализация минимального расстояния как бесконечности.
        int u = -1;  // Переменная для хранения индекса вершины с минимальным расстоянием, изначально установлена на - 1.

        // Находим вершину с минимальным расстоянием
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                u = j;
            }
        }

        if (u == -1) break; // Выход из цикла, если не удалось найти следующую вершину для обработки.

        visited[u] = true; // Помечаем вершину как посещенную

        // Обновляем расстояния до соседних вершин
        for (int v = 0; v < n; ++v) { // Цикл перебирает все вершины графа, чтобы обновить расстояния до их соседей. 
            if (!visited[v] && graph[u][v] > 0 && distance[v] > distance[u] + graph[u][v]) { // Условие !visited[v] проверяет, что вершина v еще не была посещена. 
               //Условие graph[u][v] > 0 проверяет, что между вершинами u и v существует ребро(расстояние больше 0).
                distance[v] = distance[u] + graph[u][v];
                /* Условие distance[v] > distance[u] + graph[u][v] проверяет, что новое расстояние до вершины v (через вершину u) меньше текущего расстояния до вершины v. 
                Если это условие выполняется, то мы обновляем расстояние до вершины v значением distance[u] + graph[u][v].

        Таким образом, мы сравниваем текущее расстояние до вершины v с новым расстоянием, которое можно получить, пройдя через текущую вершину u.
        Если новое расстояние меньше текущего, то мы обновляем значение расстояния до вершины v.*/
            }
        }
    }

    ofstream outputFile("output.txt");
    for (int i = 0; i < n; ++i) {
        outputFile << "Расстояние от вершины " << start << " до " << i << ": " << distance[i] << endl;
    }
}

int main() {
    ifstream inputFile("configuration/input.txt");
    int n;
    inputFile >> n;

    vector<vector<int>> adjacency_matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> adjacency_matrix[i][j]; // Заполняем матрицу смежности данными из файла
        }
    }

    dijkstra(adjacency_matrix, 0); // Запускаем алгоритм Дейкстры с начальной вершиной 0

    return 0;
}
