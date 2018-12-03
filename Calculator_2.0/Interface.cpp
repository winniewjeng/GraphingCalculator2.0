//
//  Interface.cpp
//  Calculator_2.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Interface.hpp"

Interface::Interface(): sidebar(GRAPH_PANEL, SIDE_BAR), graph() {
    cout << "Enter Interface CTOR\n";
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
    window.setFramerateLimit(60);
    cout << "Enter Interface CTOR\n";
}

void Interface::Draw() {
    cout << "Enter Interfce draw\n";
    graph.Draw(window);
    sidebar.draw(window);
    cout << "Exit Interface draw\n";
}

void Interface::render() {
    cout << "Enter Interface render\n";
    window.clear();
    Draw();
    window.display();
    cout << "Exit Interface render\n";
}

void Interface::processEvents() {
    sf::Event event;
}

void Interface::run() {
    while (window.isOpen()) {
        render(); //clear/draw/display
    }
}
