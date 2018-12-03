//
//  Sidebar.hpp
//  Calculator_2.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef Sidebar_hpp
#define Sidebar_hpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Constants.hpp"
using namespace std;
class Sidebar {
public:
    Sidebar() {}
    Sidebar(float left, float width);
    void draw(sf::RenderWindow& window);
    string& operator [](int index);
private:
    sf::RectangleShape bar;            //sidebar rectangle
    vector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text;                   //used to draw strings on the window object
    float _left;
    float _width;
};

#endif /* Sidebar_hpp */
