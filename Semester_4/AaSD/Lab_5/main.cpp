#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Класс для представления графа
class Graph {
    int V; // Количество вершин
    vector<vector<int>> adj; // Список смежности

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // Добавление ребра в граф
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // DFS для первого прохода
    void DFSUtil(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited, Stack);
            }
        }

        Stack.push(v);
    }

    // Транспонирование графа
    Graph transpose() {
        Graph transposed(V);
        for (int v = 0; v < V; ++v) {
            for (int neighbor : adj[v]) {
                transposed.addEdge(neighbor, v);
            }
        }
        return transposed;
    }

    // DFS для второго прохода
    void DFSUtil2(int v, vector<bool>& visited, ofstream& outputFile) {
        visited[v] = true;
        outputFile << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil2(neighbor, visited, outputFile);
            }
        }
    }

    // Функция для нахождения сильно связных компонент
    void findSCCs(ofstream& outputFile) {
        stack<int> Stack;
        vector<bool> visited(V, false);
        int sccCount = 0;

        // Первый проход DFS
        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                DFSUtil(v, visited, Stack);
            }
        }

        // Транспонирование графа
        Graph transposed = transpose();

        fill(visited.begin(), visited.end(), false); // Сброс флагов посещенных вершин

        // Второй проход DFS в порядке убывания времени завершения первого прохода
        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();

            if (!visited[v]) {
                transposed.DFSUtil2(v, visited, outputFile);
                outputFile << endl;
                sccCount++;
            }
        }

        outputFile << "Количество сильно связных компонент: " << sccCount << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("configuration/input.txt"); // Файл с матрицей смежности графа
    if (!inputFile.is_open()) {
        cout << "Не удалось открыть файл." << endl;
        return 1;
    }

    int V; // Количество вершин
    inputFile >> V;

    Graph graph(V);

    // Чтение матрицы смежности и добавление ребер в граф
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int val;
            inputFile >> val;
            if (val == 1) {
                graph.addEdge(i, j);
            }
        }
    }

    inputFile.close();

    ofstream outputFile("output.txt"); // Выходной файл для записи сильно связных компонент
    if (!outputFile.is_open()) {
        cout << "Не удалось открыть выходной файл." << endl;
        return 1;
    }
    graph.findSCCs(outputFile);

    outputFile.close();

    return 0;
}
