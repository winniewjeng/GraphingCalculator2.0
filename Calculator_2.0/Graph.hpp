//
//  Graph.hpp (System.hpp)
//  Calculator_2.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <vector>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "ResourcePath.hpp"

using namespace std;
class Graph {
public:
    Graph();
//    void Step(int command);
    void Draw(sf::RenderWindow& widnow);
private:
    sf::RectangleShape graph_window;
};

#endif /* Graph_hpp */
