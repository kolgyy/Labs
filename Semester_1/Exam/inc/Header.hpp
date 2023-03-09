#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace Game {
    class Player { // ������ ����� ��� ���������
    public:
        float x, y, h, w; // ���������� ������ (x, y), ������, ������
        int direction = 0; // ����������� �������� ������
        std::string File; // �������� ����� � ��� ����������
        sf::Image image; // SMFL �����������
        sf::Texture texture; //SFML ��������
        sf::Sprite sprite; // SFML ������
        Player(std::string F, int X, int Y, float W, float H);
    };


    void movement();

}