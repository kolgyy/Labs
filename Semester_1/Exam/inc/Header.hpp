#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace Game {
    class Player { // Создаём класс для персонажа
    public:
        float x, y, h, w; // Координаты игрока (x, y), Высота, Ширина
        int direction = 0; // Направление движения игрока
        std::string File; // Название файла и его расширение
        sf::Image image; // SMFL изображение
        sf::Texture texture; //SFML текстура
        sf::Sprite sprite; // SFML спрайт
        Player(std::string F, int X, int Y, float W, float H);
    };


    void movement();

}