import math


# Определяет квадрант точки
def quad(p):
    if p[0] >= 0 and p[1] >= 0:
        return 1
    if p[0] <= 0 and p[1] >= 0:
        return 2
    if p[0] <= 0 and p[1] <= 0:
        return 3
    return 4


# Проверяет пересекает ли линия многоугольник
def orientation(a, b, c):
    res = (b[1] - a[1]) * (c[0] - b[0]) - (c[1] - b[1]) * (b[0] - a[0])
    if res == 0:
        return 0
    if res > 0:
        return 1
    return -1


# Сравнение для сортировки
def compare(p1, q1):
    global mid
    p = (p1[0] - mid[0], p1[1] - mid[1])
    q = (q1[0] - mid[0], q1[1] - mid[1])

    one = quad(p)
    two = quad(q)

    if one != two:
        return one < two
    return p[1] * q[0] < q[1] * p[0]


# Объединяет два многоугольника
def merger(a, b):
    n1, n2 = len(a), len(b)

    ia = max(range(n1), key=lambda i: a[i][0])
    ib = min(range(n2), key=lambda i: b[i][0])

    inda, indb = ia, ib
    done = False
    while not done:
        done = True
        while orientation(b[indb], a[inda], a[(inda + 1) % n1]) >= 0:
            inda = (inda + 1) % n1

        while orientation(a[inda], b[indb], b[(n2 + indb - 1) % n2]) <= 0:
            indb = (n2 + indb - 1) % n2
            done = False

    uppera, upperb = inda, indb
    inda, indb = ia, ib
    done = False
    g = 0

    while not done:
        done = True
        while orientation(a[inda], b[indb], b[(indb + 1) % n2]) >= 0:
            indb = (indb + 1) % n2

        while orientation(b[indb], a[inda], a[(n1 + inda - 1) % n1]) <= 0:
            inda = (n1 + inda - 1) % n1
            done = False

    lowera, lowerb = inda, indb
    ret = []

    ind = uppera
    ret.append(a[uppera])
    while ind != lowera:
        ind = (ind + 1) % n1
        ret.append(a[ind])

    ind = lowerb
    ret.append(b[lowerb])
    while ind != upperb:
        ind = (ind + 1) % n2
        ret.append(b[ind])

    return ret


# Алгоритм перебора для нахождения выпуклой оболочки для множества точек меньше чем 6
def bruteHull(a):
    s = set()

    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            x1, x2 = a[i][0], a[j][0]
            y1, y2 = a[i][1], a[j][1]

            a1 = y1 - y2
            b1 = x2 - x1
            c1 = x1 * y2 - y1 * x2

            pos, neg = 0, 0

            for k in range(len(a)):
                if a1 * a[k][0] + b1 * a[k][1] + c1 > 0:
                    pos += 1

                elif a1 * a[k][0] + b1 * a[k][1] + c1 < 0:
                    neg += 1

            if pos == 0 or neg == 0:
                s.add(a[i])
                s.add(a[j])

    return list(s)


# Ввод координат точек
n = int(input("Введите количество точек: "))
points = []
for i in range(n):
    x, y = map(int, input(f"Введите координаты точки {i + 1} (x y): ").split())
    points.append((x, y))

mid = (sum(x for x, _ in points) // n, sum(y for _, y in points) // n)
points.sort(key=lambda p: (p[0] - mid[0], p[1] - mid[1]))
convex_hull_points = bruteHull(points)

print("Точки выпуклой оболочки:")
for point in convex_hull_points:
    print(point)
