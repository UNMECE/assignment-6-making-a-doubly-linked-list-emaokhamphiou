#include "coordinate.h"

void add_coordinate(Coordinate **list_end, float x, float y) {
    Coordinate *new_coord = malloc(sizeof(Coordinate));
    new_coord->x = x;
    new_coord->y = y;
    new_coord->next = NULL;
    if (*list_end == NULL) {
        new_coord->previous = NULL;
        new_coord->coord_id = 1;
        *list_end = new_coord;
    } else {
        new_coord->previous = *list_end;
        new_coord->coord_id = (*list_end)->coord_id + 1;
        (*list_end)->next = new_coord;
        *list_end = new_coord;
    }
}

void forward_display(Coordinate *list_beginning) {
    for (Coordinate *current = list_beginning; current != NULL; current = current->next) {
        printf("ID: %d, (%.2f, %.2f)\n", current->coord_id, current->x, current->y);
    }
}

void backward_display(Coordinate *list_end) {
    for (Coordinate *current = list_end; current != NULL; current = current->previous) {
        printf("ID: %d, (%.2f, %.2f)\n", current->coord_id, current->x, current->y);
    }
}

void delete_coordinate(Coordinate **list_beginning, int coord_id_to_delete) {
    Coordinate *current = *list_beginning;
    while (current != NULL && current->coord_id != coord_id_to_delete) {
        current = current->next;
    }
    if (current == NULL) return;
    if (current->previous) current->previous->next = current->next;
    else *list_beginning = current->next;
    if (current->next) current->next->previous = current->previous;
    free(current);
}

int list_length(Coordinate *list_beginning) {
    int length = 0;
    for (Coordinate *current = list_beginning; current != NULL; current = current->next) {
        length++;
    }
    return length;
}

void closest_to(Coordinate *list_beginning, float x, float y) {
    Coordinate *closest = NULL;
    float min_distance = INFINITY;
    for (Coordinate *current = list_beginning; current != NULL; current = current->next) {
        float distance = sqrt(pow(current->x - x, 2) + pow(current->y - y, 2));
        if (distance < min_distance) {
            min_distance = distance;
            closest = current;
        }
    }
    if (closest) {
        printf("Closest to (%.2f, %.2f): ID %d, (%.2f, %.2f), Distance: %.2f\n",
               x, y, closest->coord_id, closest->x, closest->y, min_distance);
    }
}
