#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "coordinate.h"

#define MAX_COORD 100.0

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;
    int num_coords = atoi(argv[1]);
    if (num_coords <= 0) return 1;

    srand(time(NULL));
    Coordinate *list_beginning = NULL, *list_end = NULL;

    for (int i = 0; i < num_coords; i++) {
        float x = ((float)rand() / RAND_MAX) * MAX_COORD;
        float y = ((float)rand() / RAND_MAX) * MAX_COORD;
        add_coordinate(&list_end, x, y);
        if (!list_beginning) list_beginning = list_end;
    }

    forward_display(list_beginning);
    backward_display(list_end);
    printf("List length: %d\n", list_length(list_beginning));

    delete_coordinate(&list_beginning, 3);
    forward_display(list_beginning);

    closest_to(list_beginning, 50.0, 50.0);

    while (list_beginning) {
        Coordinate *temp = list_beginning;
        list_beginning = list_beginning->next;
        free(temp);
    }

    return 0;
}
