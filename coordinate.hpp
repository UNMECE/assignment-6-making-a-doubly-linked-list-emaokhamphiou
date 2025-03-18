#pragma once
struct Coordinate {
    float x, y;
    int coord_id;
    Coordinate* next;
    Coordinate* prev;
};

void add(Coordinate*& tail, float x, float y);
void display_forward(Coordinate* head);
void display_backward(Coordinate* tail);
void remove(Coordinate*& head, int id);
int length(Coordinate* head);
void closest(Coordinate* head, float x, float y);