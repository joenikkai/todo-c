#ifndef TODO_C

#include <stdlib.h>
#include <time.h>


#define CAPACITY 10

typedef struct TasksToDo {
    char task_status[5];
    int tasks_number;
    char *tasks_description;
    time_t timestamp;
} TasksToDo_t;

typedef struct ToDoList {
    size_t capacity;
    size_t n_tasks;
    TasksToDo_t* tasks;
} ToDoList_t;
#endif // !TODO_C