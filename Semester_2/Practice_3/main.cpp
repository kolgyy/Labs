#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>

#define Pi 3.14159265358979323846
using std::endl;
using std::cout;
using std::cin;
using std::string;

class KinematicSolver {
public:
	KinematicSolver(double L1, double L2) : L1(L1), L2(L2) {}
	void setL1(double L1) {
		this->L1 = L1;
	}
	void setL2(double L2) {
		this->L2 = L2;
	}
	bool Solve(double x, double y, double& alpha, double& beta) {
		double b = sqrt(x * x + y * y);
		if (!((L1 + L2 > b) & (L1 + b > L2) & (b + L2 > L1))) {
			return false;
		}
		alpha = acos((b * b + L1 * L1 - L2 * L2) / (2.0 * b * L1)) + atan2(y,x);
		beta = -(Pi - acos((L2 * L2 + L1 * L1 - b * b) / (2.0 * L1 * L2)));
		return true;


	}

private:
	double L1;
	double L2;
};

int main() {
	double L1 = 100.0;
	double L2 = 100.0;
	KinematicSolver solver(L1, L2);

	double x = 120.0;
	double y = 120.0;

	double alpha, beta;
	if (solver.Solve(x, y, alpha, beta)) {
		cout << "alpha : " << alpha << ", beta = " << beta << endl;
	}
	else {
		std::cerr << "Impossible to reach the coordinates" << endl;
	}

	sf::RenderWindow window(sf::VideoMode(800, 600), "Robot");
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::White);

		sf::Vector2u windowSize = window.getSize();
		sf::Vector2f windowCenter = sf::Vector2f(windowSize.x / 2.0, windowSize.y / 2.0);

		// Draw X and Y axes 
		sf::RectangleShape xAxis(sf::Vector2f(windowSize.x, 1.0));
		xAxis.setFillColor(sf::Color::Black);
		xAxis.setOrigin(0.0, 0.5);
		xAxis.setPosition(0.0, windowSize.y / 2.0);

		sf::RectangleShape yAxis(sf::Vector2f(1.0, windowSize.y));
		yAxis.setFillColor(sf::Color::Black);
		yAxis.setOrigin(0.5, 0.0);
		yAxis.setPosition(windowSize.x / 2.0, 0.0);

		sf::RectangleShape link1(sf::Vector2f(L1, 10.0));
		link1.setFillColor(sf::Color::Green);
		link1.setOrigin(0.0, 5.0);
		link1.setPosition(windowCenter);
		link1.setRotation(alpha * 180.0 / Pi);

		sf::RectangleShape link2(sf::Vector2f(L2, 10.0));
		link2.setFillColor(sf::Color::Black);
		link2.setOrigin(0.0, 5.0);
		link2.setPosition(link1.getPosition() + sf::Vector2f(L1 * cos(alpha), L1 * sin(alpha)));
		link2.setRotation((alpha + beta) * 180 / Pi);

		sf::CircleShape endEffector(5.0);
		endEffector.setFillColor(sf::Color::Red);
		endEffector.setOrigin(5.0, 5.0);
		endEffector.setPosition(windowCenter + sf::Vector2f(x, y));

		window.draw(xAxis);
		window.draw(yAxis);
		window.draw(link1);
		window.draw(link2);
		window.draw(endEffector);

		window.display();
	}

	return 0;
}

