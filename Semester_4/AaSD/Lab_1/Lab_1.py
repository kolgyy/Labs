import matplotlib.pyplot as plt

def plot_points(points, hull):
    plt.figure()
    plt.scatter([point[0] for point in points], [point[1] for point in points], color='blue', label='Points')
    plt.plot([point[0] for point in hull + [hull[0]]], [point[1] for point in hull + [hull[0]]], color='red', label='Convex Hull')
    plt.legend()
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Convex Hull Visualization')
    plt.show()

# Замените points на список координат точек и hull на список координат точек выпуклой оболочки
points = [(1, 1), (2, 3), (4, 2), (5, 5), (6, 3), (7, 4), (8, 1)]
hull = [(1, 1), (8, 1), (7, 4), (5, 5), (2, 3)]

plot_points(points, hull)
