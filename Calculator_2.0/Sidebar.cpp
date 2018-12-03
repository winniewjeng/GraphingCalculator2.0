//
//  Sidebar.cpp
//  Calculator_2.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Sidebar.hpp"

Sidebar::Sidebar(float left, float width):_left(left), _width(width) {
    
    //set up the sidebar rectangle:
    bar.setFillColor(sf::Color(210,239,255));
    bar.setPosition(sf::Vector2f(left, 0));
    bar.setSize(sf::Vector2f(width, WINDOW_HEIGHT));
}

void Sidebar::draw(sf::RenderWindow& window) {
    window.draw(bar);
}

