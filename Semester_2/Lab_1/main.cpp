#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

class AnimatedText {
public:
    AnimatedText(const std::string& text, float duration) :
        m_text(text),
        m_duration(duration)
    {
        m_elapsedTime = 0; // Time from a start
        m_currentLength = 0; // Amount of symbols that were printed from a start
    }

    void update(float deltaTime) { // DeltaTime - time that's passed since the last frame
        m_elapsedTime += deltaTime;

        float timePerChar = m_elapsedTime / m_duration; // We're finding out how many symbols should be printed on the screen at the moment.
        // Them we multiply this time to the amount of symbols and round it up to an integer.
        int charsToShow = static_cast<int>(timePerChar * static_cast<float>(m_text.size()));

        if (charsToShow > m_currentLength) { // If charsToShow > m_currentLength, it means we've already printed some symbols and we should add new.
            m_currentLength = charsToShow;
        }
    }
    // We define a draw method which gets a font, a font size, its position and color.
    void draw(sf::RenderWindow& window, const sf::Font& font, unsigned int fontSize, const sf::Vector2f& position, const sf::Color& color) {
        std::string visibleText = m_text.substr(0, m_currentLength); // We create a new string to show those elements we just want.

        sf::Text text(visibleText, font, fontSize);
        text.setPosition(position);
        text.setFillColor(color);

        window.draw(text);
    }

private:
    std::string m_text;
    float m_duration;
    float m_elapsedTime;
    int m_currentLength;
};

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Animated Text Example");

    sf::Font font; 
    if (!font.loadFromFile("assets/adobe.otf")) { 
        std::cerr << "Failed to load font file" << std::endl;
        return 1;
    }

    AnimatedText animatedText("Hello, world!", 13.0f);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();
        animatedText.update(deltaTime); // With sf::Clock we measure the passed time from the last frame and set it to UPDATE.

        window.clear(sf::Color::White);
        animatedText.draw(window, font, 32, sf::Vector2f(100, 100), sf::Color::Black);
        window.display();

        // 1 millisecond delay to reduce CPU load.
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    return 0;
}