#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Header.hpp>
#include <string>


sf::CircleShape circle2(30, 30);
sf::CircleShape circle3(90, 30);
sf::CircleShape circle1(30, 45);
int Direction = 0;


int main()
{
    sf::Music music;
    music.openFromFile("../assets/Music.wav");
    music.play();
    music.setLoop(true);
    Game::Player Protagonist("Protagonist.png", 0, 0, 233, 284);

    sf::View view(sf::FloatRect(0, 0, 1000, 1000));

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "COOL_BOY");
    window.setFramerateLimit(60); // ������ 60 ������ � �������


    // ����������� ���� 2
    circle2.setFillColor(sf::Color::Yellow);
    circle2.setPosition(700, 500);
    // ����������� ���� 3
    circle3.setFillColor(sf::Color::Yellow);
    circle3.setPosition(120, 600);
    // ����������� ���� 1
    circle1.setFillColor(sf::Color::Yellow);
    circle1.setPosition(500, 200);

    float current_frame = 0; // ������ ������� ����

    sf::Clock clock; // ������ ������ ������ ������� (�����), ����� ������� �������� ���� �� �������, � �� � �������� ����������.
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

 
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds(); // ��� ��������� ����� � �������������
        clock.restart(); // ������������� �����
        time = time / 800; // �������� ����. ��� ������, ��� �������, �� ������ �������� ��������.
 
     

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        sf::FloatRect SpriteBounds = Protagonist.sprite.getGlobalBounds(); // ��������� �������� ������� ��������� ��� ����, ����� ����������������� � ���������
        sf::FloatRect circle2Bounds = circle2.getGlobalBounds();// ��������� ������ ����� 2
        sf::FloatRect circle3Bounds = circle3.getGlobalBounds();// ��������� ������ ����� 3
        sf::FloatRect circle1Bounds = circle1.getGlobalBounds();

        if (SpriteBounds.intersects(circle2Bounds)) { // ���� ������ ����
            circle2.setFillColor(sf::Color::Green);
        }
        if (SpriteBounds.intersects(circle1Bounds)) { // ���� ������ ����
            circle1.setFillColor(sf::Color::Magenta);
        }

        if (SpriteBounds.intersects(circle3Bounds)) { // �������� ���������
            if (Direction == 0) {
                Protagonist.sprite.move(-0.1 * time, 0);
            }
            if (Direction == 1) {
                Protagonist.sprite.move(0.1 * time, 0);
            }
            if (Direction == 2) {
                Protagonist.sprite.move(0, -0.1 * time);
            }
            if (Direction == 3) {
                Protagonist.sprite.move(0, 0.1 * time);
            }
        }


        // �� ����� ��������, ��� ����������� ��������� � SFML ������������ (���� � ������)
        // �� �������� �����, ��� ��������� �� �������� = ���������� ����.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            Direction = 0;
            current_frame += 0.005 * time; // ������ ��� ����������� �� ������ ��������.
            // ���������� ������� �� 4, �������� ������������ ������� � ��������. ������� ��������, ����� �������� ���� �������.
            if (current_frame > 4) { current_frame -= 4; } // ���� ������ � 4 �����, �� ������������ �����.
            Protagonist.sprite.setTextureRect(sf::IntRect(234 * int(current_frame), 569, 233, 283)); // ���������� �����, current_frame ���������� �������������
            // �� 0 �� 4. ���� ��� ������������� �� 0 �� 1, �� ����� 0, ������ ����������� ���������, �����, ����� ��� ������� 1, �� �������� � ���������� �����.
            Protagonist.sprite.move(-0.1*time, 0);} // ������ ���������� x ������������ - ��� �����
        
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            Direction = 1;
            current_frame += 0.005 * time;
            if (current_frame > 4) { current_frame -= 4; }
            Protagonist.sprite.setTextureRect(sf::IntRect(234 * int(current_frame), 855, 233, 283));
            Protagonist.sprite.move(0.1 * time, 0); }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            Direction = 2;
            current_frame += 0.005 * time;
            if (current_frame > 4) { current_frame -= 4; }
            Protagonist.sprite.setTextureRect(sf::IntRect(234 * int(current_frame), 295, 233, 277));
            Protagonist.sprite.move(0, -0.1*time);
        }
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            Direction = 3;
            current_frame += 0.005 * time;
            if (current_frame > 4) { current_frame -= 4; }
            Protagonist.sprite.setTextureRect(sf::IntRect(245 * int(current_frame), 8, 220, 275));
            Protagonist.sprite.move(0, 0.1*time);
        }
        // ���� ������ �������, �� ��������� �����-�� ��������. Move - ����� � �������, ������� ��������� ��� �������. � ��� ��� ��� ���������� (x, y)

  



        window.clear(sf::Color::Magenta);
        window.draw(circle2);
        window.draw(circle3);
        window.draw(circle1);
        window.draw(Protagonist.sprite);
        window.display();
    }

    return 0;
}