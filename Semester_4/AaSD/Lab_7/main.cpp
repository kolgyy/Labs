#include <iostream>
#include <vector>
#include <fstream>

// Алгоритм Прима. Сложность O(V^2).
using namespace std;

const int INF = 9999999; // Бесконечность для обозначения несуществующих ребер

int main() {
    ifstream fin("configuration/input.txt"); // Открываем файл на чтение
    ofstream fout("output.txt"); // Открываем файл на запись

    int V;
    fin >> V; // Считываем количество вершин
    vector<vector<int>> G(V, vector<int>(V)); // Создаем матрицу смежности

    // Считываем матрицу смежности из файла
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            fin >> G[i][j];
        }
    }

    vector<bool> selected(V, false); // Массив для отслеживания выбранных вершин
    selected[0] = true; // Начинаем с первой вершины
    int no_edge = 0; // Счетчик ребер
    int total_weight = 0; // Общий вес минимального остовного дерева

    fout << "Edge : Weight\n";

    // Поиск минимального остовного дерева
    while (no_edge < V - 1) {
        int minimum = INF;
        int x = 0, y = 0; // Переменные для хранения вершин ребра

        // Перебираем все вершины
        for (int i = 0; i < V; ++i) {
            if (selected[i]) { // Если вершина i уже выбрана
                for (int j = 0; j < V; ++j) {
                    if (!selected[j] && G[i][j]) { // Если вершина j не выбрана и есть ребро между i и j
                        if (minimum > G[i][j]) {
                            minimum = G[i][j]; // Обновляем минимальное значение и вершины ребра
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        fout << x << "-" << y << "  :   " << G[x][y] << "\n"; // Записываем выбранное ребро в файл
        total_weight += G[x][y]; // Увеличиваем общий вес на вес выбранного ребра
        selected[y] = true; // Помечаем вершину y как выбранную
        no_edge++; // Увеличиваем счетчик выбранных ребер
    }

    fout << "\nTotal weight of minimum spanning tree: " << total_weight;

    fin.close();
    fout.close();

    return 0;
}
