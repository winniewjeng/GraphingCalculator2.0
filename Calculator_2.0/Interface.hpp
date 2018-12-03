//
//  Interface.hpp
//  Calculator_2.0
//
//  Created by Winnie Jeng on 12/1/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef Interface_hpp
#define Interface_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.hpp"
#include "Graph.hpp"
#include "Sidebar.hpp"
#include "ResourcePath.hpp" // don't need it i think

class Interface {
public:
    Interface();
    void run();
    void processEvents();
//    void update();
    void render();
    void Draw();
private:
    sf::RenderWindow window;
    Graph graph;
    Sidebar sidebar;
};


//void run() {
//    // Create the main window
//    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML window");
//
//    // Set the Icon
//    sf::Image icon;
//    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
//        return EXIT_FAILURE;
//    }
//    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//
//    // Start the game loop
//    while (window.isOpen())
//    {
//        // Process events
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // Close window: exit
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//
//            // Escape pressed: exit
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
//                window.close();
//            }
//        }
//
//        // Clear screen
//        window.clear();
//
//        window.display();
//    }
//
//    return EXIT_SUCCESS;
//}

#endif /* Interface_hpp */
