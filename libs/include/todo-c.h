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

#define MIN_WINDOW_HEIGHT 5
#define MIN_WINDOW_WIDTH 12
#define MAX_BUFFER_SIZE 256

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>

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



char* GenerateFileName(char **ptr_to_fn,char*username, char *objective);
char* getDialogInput(char * msg);
char* SanitizeInput(char*msg); // \brief illegal chars with space

ToDoList_t InitializeList(WINDOW **win);
#endif // !TODO_C