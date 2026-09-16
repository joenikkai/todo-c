/** Copyright (C) 2026  Joseph Wangai Mwaniki joenikkai@gmail.com
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 **/

#ifndef TODO_C

#define PROJECT_NAME "todo-c"

#define MIN_WINDOW_HEIGHT 5

#define MIN_ROOT_HEIGHT (MIN_WINDOW_HEIGHT * 2)
#define MAX_BUFFER_SIZE 256

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>


static const int PROJECT_NAME_LENGTH =  strlen(PROJECT_NAME);

#define PROMPT_EMPTY__ADD_A_TASK_TODO "Add a task to do."
static const int PROMPT_EMPTY__ADD_A_TASK_TODO_LENGTH = strlen(PROMPT_EMPTY__ADD_A_TASK_TODO);

#define MIN_WINDOW_WIDTH (PROMPT_EMPTY__ADD_A_TASK_TODO_LENGTH + 5)

#define REPL_CHARACTER_LABEL " <  "
#define REPL_CHARACTER_LABEL_ORIGIN_POSITION_Y 1
#define REPL_CHARACTER_LABEL_ORIGIN_POSITION_X 1
static const int DEFAULT_REPL_CURSOR_POSITION  = strlen(REPL_CHARACTER_LABEL) + REPL_CHARACTER_LABEL_ORIGIN_POSITION_X;

#define DEFAULT_BORDER_CHARACTER 0

#define INPUT_BUFFER_SIZE 256

#define INPUT_TASK_PROMPT "type task here..."

#define DEBUG

#ifdef DEBUG
#include <assert.h>
#endif // DEBUG

#define CAPACITY 10

typedef struct TaskToDo {
    char task_status[5];
    int task_number;
    char *task_description;
    time_t task_timestamp;
} TaskToDo_t;

typedef struct ToDoList {
    size_t capacity; // maximum number of tasks that can be hend in a day
    size_t n_tasks; // number of tasks hend in that specific day
    TaskToDo_t* tasks; // pointer to where the tasks are stored in memory
    WINDOW * lwin; // window where the tasks are displayed
    void (*Run)(struct ToDoList *); // mainloop
    void (*AppendTask)(struct ToDoList *, TaskToDo_t); // listen for new tasks
    void (*SwapTask)(struct ToDoList *,size_t); // replace task
    TaskToDo_t (*EraseTask)(struct ToDoList *,size_t); // mark a task as done, todo or quit
} ToDoList_t;

#ifdef DEBUG

#define EXAMPLE_DEBUG_TASKS_LENGTH 5

static const TaskToDo_t EXAMPLE_DEBUG_TASKS[EXAMPLE_DEBUG_TASKS_LENGTH] = {
    {.task_status="DONE",.task_description="Learn C Programming Language",.task_number=11,.task_timestamp=1789318332},
    {.task_status="DONE",.task_description="Cook Food",.task_number=11,.task_timestamp=1789318437},
    {.task_status="DONE",.task_description="Take a Walk",.task_number=11,.task_timestamp=1789318450},
    {.task_status="DONE",.task_description="Watch Youtube",.task_number=11,.task_timestamp=1789318492},
    {.task_status="TODO",.task_description="Sleep on time",.task_number=11,.task_timestamp=1789318502},
};

#endif // DEBUG

char* GenerateFileName(char **ptr_to_fn,char*username, char *objective);
char* getDialogInput(char * msg);
char* SanitizeInput(char*msg); // \brief illegal chars with space

ToDoList_t InitializeList(WINDOW **win);

#endif // !TODO_C
