#include "coordinate.hpp"
#include <cmath>
#include <iostream>

void add(Coordinate*& tail, float x, float y) {
    Coordinate* node = new Coordinate{x, y, 0, nullptr, tail};
    if(!tail) node->coord_id = 1;
    else {
        int count = 0;
        Coordinate* current = tail;
        while(current) { count++; current = current->prev; }
        node->coord_id = count + 1;
    }
    if(tail) tail->next = node;
    tail = node;
}

void display_forward(Coordinate* head) {
    while(head) {
        std::cout << "ID " << head->coord_id << ": (" << head->x << ", " << head->y << ")\n";
        head = head->next;
    }
}

void display_backward(Coordinate* tail) {
    while(tail) {
        std::cout << "ID " << tail->coord_id << ": (" << tail->x << ", " << tail->y << ")\n";
        tail = tail->prev;
    }
}

void remove(Coordinate*& head, int id) {
    Coordinate* current = head;
    while(current && current->coord_id != id) current = current->next;
    if(!current) return;
    if(current->prev) current->prev->next = current->next;
    else head = current->next;
    if(current->next) current->next->prev = current->prev;
    delete current;
}

int length(Coordinate* head) {
    int count = 0;
    while(head) { count++; head = head->next; }
    return count;
}

void closest(Coordinate* head, float x, float y) {
    Coordinate* closest = nullptr;
    float min = INFINITY;
    while(head) {
        float dist = sqrt(pow(head->x - x, 2) + pow(head->y - y, 2));
        if(dist < min) { min = dist; closest = head; }
        head = head->next;
    }
    if(closest) {
        std::cout << "Closest: ID " << closest->coord_id << " (" 
                  << closest->x << ", " << closest->y << ") Distance: " << min << "\n";
    }
}
