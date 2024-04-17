#include <iostream>
#include <vector>
#include <algorithm>

// Алгоритм Грэхема имеет сложность O(n) без учета сортировки и O(nlogn) с сортировкой


using namespace std;

struct Point {
    int x, y;
};

struct Vector {
    int x, y;
    Vector(Point p1, Point p2) { // Конструктор для построения вектора из 2-х точек
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }
};

long cross(Vector v1, Vector v2) { // Векторное произведение
    return v1.x * v2.y - v2.x * v1.y; // Векторное произведение как определитель матрицы
}


vector<Point> get_convex_hull(vector<Point> points) {
    // 1 ШАГ - Поиск опорной точки и сортировка
    for (int i = 1; i < points.size(); ++i) { // Ищем опорную точку, которая будет самой левой и самой нижней из всех
        if ((points[i].x < points[0].x) || (points[i].x == points[0].x && points[i].y < points[0].y)) {
            swap(points[0], points[i]); // Опорную точку помещаем в самое начало вектора
        }
    }
    // Сортировка заключается в том, что первая точка лежит левее, чем вторая. Здесь поможет векторное произведение.
    sort(points.begin() + 1, points.end(), [&points](Point p1, Point p2)
        {
            return cross(Vector(points[0], p1), Vector(points[0], p2)) > 0; // Для этого векторное произведение должно быть больше нуля.
        });
    // 2 ШАГ - Пробежаться по точкам и собрать их в вектор.
    vector<Point> ch = { points[0]};
    for (int i = 1; i < points.size(); ++i) {
        // Срезаем ненужные точки
        while (ch.size() >= 2 && cross(Vector(ch[ch.size() - 2], ch[ch.size() - 1]), Vector(ch[ch.size() - 1], points[i])) < 0) {
            ch.pop_back();

        }
        ch.push_back(points[i]);
    }
    return ch;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество точек: ";
    cin >> n;
    vector<Point> points(n);
    cout << "Введите координаты точек (x y):" << endl;
    for (auto &pt : points) {
        cin >> pt.x >> pt.y;
    }
    auto convexHull = get_convex_hull(points);
    cout << convexHull.size() << endl;
    for (auto pt : convexHull) {
        cout << pt.x << ' ' << pt.y << endl;
    }

    // Пример 7 точек: (1,1), (2,3), (4, 2), (5, 5), (6, 3), (7, 4), (8, 1)
    // Вывод 5 точек: (1,1), (8, 1), (7, 4), (5, 5), (2, 3)

    return 0;
}
