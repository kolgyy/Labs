#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

struct Line {
    double A;
    double B;
    double C;
};

double distanceBetweenPoints(Point p1, Point p2) { // Расстояние между точками
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

void findIntersectionPoints(Line line1, Line line2, Point& intersectionPoint) { // Пересечение прямых
    double determinant = line1.A * line2.B - line2.A * line1.B;

    if (determinant == 0) {
        std::cout << "Lines are parallel, no intersection points." << std::endl;
        return;
    }

    intersectionPoint.x = (line2.B * line1.C - line1.B * line2.C) / determinant;
    intersectionPoint.y = (line1.A * line2.C - line2.A * line1.C) / determinant;
}
// Отрезок и точка
void findIntersectionPoints(Line line, Point linePoint, Point point1, Point point2, Point& intersectionPoint) {
    double deltaX = point2.x - point1.x;
    double deltaY = point2.y - point1.y;

    Line segmentLine;
    segmentLine.A = -deltaY;
    segmentLine.B = deltaX;
    segmentLine.C = -segmentLine.A * point1.x - segmentLine.B * point1.y;

    findIntersectionPoints(line, segmentLine, intersectionPoint);
}
// Пересечение окружности и прямой
void findIntersectionPoints(Point center, double radius, Line line, Point& intersectionPoint1, Point& intersectionPoint2) {
    double A = line.A;
    double B = line.B;
    double C = line.C;
    double r = radius;

    double distance = A * center.x + B * center.y + C;

    if (std::abs(distance) > r) {
        std::cout << "No intersection points." << std::endl;
        return;
    }

    double sqrtPart = std::sqrt(std::pow(r, 2) - std::pow(distance, 2));
    double mult = 1 / std::sqrt(std::pow(A, 2) + std::pow(B, 2));

    intersectionPoint1.x = center.x - B * mult * distance + A * mult * sqrtPart;
    intersectionPoint1.y = center.y + A * mult * distance + B * mult * sqrtPart;

    intersectionPoint2.x = center.x - B * mult * distance - A * mult * sqrtPart;
    intersectionPoint2.y = center.y + A * mult * distance - B * mult * sqrtPart;
}
// Окружности и отрезка
void findIntersectionPoints(Point center, double radius, Point point1, Point point2, Point& intersectionPoint1, Point& intersectionPoint2) {
    Line line;
    line.A = point1.y - point2.y;
    line.B = point2.x - point1.x;
    line.C = point1.x * point2.y - point2.x * point1.y;

    findIntersectionPoints(center, radius, line, intersectionPoint1, intersectionPoint2);
}

Point* findIntersectionPoints(Point* points, int numPoints) {
    // Заданные точки
    Point A = points[0];  // Пример
    Point B = points[1];  // Пример
    Point C = points[2];  // Пример
    Point D = points[3];  // Пример
    Point E = points[4];  // Пример

    // Радиус окружности
    double Radius = distanceBetweenPoints(C, D);

    // Находим 10 точек пересечения
    Point* intersectionPoints = new Point[10];

    // Первая точка - центр окружности
    intersectionPoints[0] = C;

    // Четырехугольник - ABCD
    Line line1;
    line1.A = A.y - B.y;
    line1.B = B.x - A.x;
    line1.C = A.x * B.y - B.x * A.y;
    findIntersectionPoints(line1, C, A, B, intersectionPoints[1]);

    Line line2;
    line2.A = C.y - D.y;
    line2.B = D.x - C.x;
    line2.C = C.x * D.y - D.x * C.y;
    findIntersectionPoints(line2, B, C, D, intersectionPoints[2]);

    Line line3;
    line3.A = A.y - D.y;
    line3.B = D.x - A.x;
    line3.C = A.x * D.y - D.x * A.y;
    findIntersectionPoints(line3, C, A, D, intersectionPoints[3]);

    Line line4;
    line4.A = A.y - D.y;
    line4.B = D.x - A.x;
    line4.C = A.x * D.y - D.x * A.y;
    findIntersectionPoints(line4, A, C, D, intersectionPoints[4]);

    // Треугольник - BCE
    Line line5;
    line5.A = B.y - C.y;
    line5.B = C.x - B.x;
    line5.C = B.x * C.y - C.x * B.y;
    findIntersectionPoints(line5, B, C, E, intersectionPoints[2]);

    Line line6;
    line6.A = C.y - E.y;
    line6.B = E.x - C.x;
    line6.C = C.x * E.y - E.x * C.y;
    findIntersectionPoints(line6, C, E, D, intersectionPoints[3]);

    Line line7;
    line7.A = D.y - E.y;
    line7.B = E.x - D.x;
    line7.C = D.x * E.y - E.x * D.y;
    findIntersectionPoints(line7, D, E, A, intersectionPoints[4]);


    return intersectionPoints;
}

int main() {
    Point* points = new Point[5];
    points[0] = { 15.0, 8.0 };
    points[1] = { 11.0, 15.0 };
    points[2] = { 7.5, 8.0 };
    points[3] = { 11.25, 11.35 };
    points[4] = { 22.75, 25.0 };
    Point* intersectionPoints = findIntersectionPoints(points, 5);

    std::cout << "Intersection points:" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Point: " << i + 1 << ": (" << intersectionPoints[i].x << ", " << intersectionPoints[i].y << ")" << std::endl;
    }

    delete[] points;
    delete[] intersectionPoints;

    return 0;
}