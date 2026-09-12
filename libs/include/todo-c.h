#ifndef TODO_C
#include <ctime>

typedef struct ItemToDo {
    char status[5];
    int item_number;
    char *item_description;
    time_t timestamp;
} ItemToDo_t;

#endif // !TODO_C