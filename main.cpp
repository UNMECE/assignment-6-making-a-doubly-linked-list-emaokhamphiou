#include <cstdlib>
#include <ctime>
#include "coordinate.hpp"

int main(int argc, char* argv[]) {
    if(argc != 2) return 1;
    int count = std::atoi(argv[1]);
    if(count <= 0) return 1;

    std::srand(std::time(nullptr));
    Coordinate* head = nullptr;
    Coordinate* tail = nullptr;

    for(int i = 0; i < count; i++) {
        float x = static_cast<float>(std::rand())/RAND_MAX * 100;
        float y = static_cast<float>(std::rand())/RAND_MAX * 100;
        add(tail, x, y);
        if(!head) head = tail;
    }

    display_forward(head);
    display_backward(tail);
    remove(head, 3);
    closest(head, 50, 50);

    while(head) {
        Coordinate* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
