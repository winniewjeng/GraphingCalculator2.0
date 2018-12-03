//
//  Interface.cpp
//  Calculator_2.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Interface.hpp"

Interface::Interface(): sidebar(GRAPH_PANEL, SIDE_BAR), graph() {
}

void Interface::Draw() {
    graph.Draw(window);
    sidebar.draw(window);
}

void Interface::render() {
    window.clear();
    Draw();
    window.display();
}

void Interface::processEvents() {
    sf::Event event;
}

void Interface::run() {
    while (window.isOpen()) {
        render(); //clear/draw/display
    }
}
