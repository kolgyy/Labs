#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


using namespace std;
using namespace sf;

class AnimatedText {
private:
    string text;
    float duration;
    Font font;
public:
    Text txt;

    AnimatedText(string text_name, float duration) {
        font.loadFromFile("assets/adobe.otf"); // Loading a font
        txt.setFont(font); // Setting a font
        txt.setCharacterSize(20); // Setting the font size


        txt.setFillColor(Color(255, 255, 255)); //Setting a color
        text = text_name; // Setting the text name
        this->duration = duration;
        txt.setString(text);
        txt.setPosition(125, 75);
    }
    
    
    void draw(RenderWindow& window) {
        
        
        for (int i = 0; i < strlen((txt)); i++)
        {
            Sleep(300);
            cout << string(txt)[i];
        }
    }


};


int main()
{   
    sf::RenderWindow window(sf::VideoMode(300, 200), "AnimatedText");

    AnimatedText message("Hello", 2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        message.draw(window);
        window.display();
    }

    return 0;
    
    


}