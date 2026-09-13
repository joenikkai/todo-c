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
#include "todo-c.h"

#define FN_FMT(username,now,objective)  ("%s_%s_%s.txt",username,ctime(&now),objective)

char* GenerateFileName(char **ptr_to_fname,char*username, char *objective) {
    char *ret_v;
    size_t ret_len;

    time_t now = time(NULL);

    sprintf(ret_v,FN_FMT(username,now,objective));
    ret_len = strlen(ret_v);

    strncpy(*ptr_to_fname,ret_v,ret_len);
    return ret_v;
}

char* getDialogInput(char * msg) {
    int y, x, pos_y = 0, pos_x = 0, len = strlen(msg), padding = 3;
    getmaxyx(stdscr,y,x);
    
    WINDOW *dialog;
    if ( x > len && y > MIN_WINDOW_HEIGHT) {
        dialog = newwin(MIN_WINDOW_HEIGHT + padding, len + padding, ((y / 2) - (MIN_WINDOW_HEIGHT / 2)), ((x / 2) - ((len + padding ) / 2))); // size,size,origin,origin
        refresh();
        mvwvline(dialog,1,0,0,2);
        mvwhline(dialog,0,1,0,2);
        wrefresh(dialog);
        mvwprintw(dialog, ++pos_y, pos_x += 2,"%s",msg);

        char buffer[MAX_BUFFER_SIZE];
        mvwgetstr(dialog, ++pos_y, pos_x, buffer);
        size_t len = strlen(buffer);

        char* ret_v = calloc(len, sizeof(char));
        strncpy(ret_v,buffer,len);
        return ret_v;
    }
    return NULL;
}

char* SanitizeInput(char *msg) {
    if (NULL == msg) return NULL;

    const char *illchars = ",<>:?*\"/\\|";

    for (char *p = msg; *p;p++) {
        unsigned char c = (unsigned char)*p;
        if (strchr(illchars,c) || c < 32 || c == 127) {
            *p = ' ';
        }
    }
    
    return msg;
}


void __Run(ToDoList_t *tsk_l) {
    int y,x;
    getmaxyx(tsk_l->lwin,y,x);
    
    while (y < MIN_ROOT_HEIGHT || x < MIN_WINDOW_WIDTH) {
        printw("make your screen bigger to render the UI.");
        refresh();
        getch();
    }

    int ORIGIN = 0;
    int HEAD_HEIGHT = 1, HEAD_WIDTH = x;
    int TAIL_HEIGHT = 3, TAIL_WIDTH = x;
    int BODY_HEIGHT = y - (HEAD_HEIGHT + TAIL_HEIGHT), BODY_WIDTH = x;

    WINDOW *head = subwin(tsk_l->lwin,HEAD_HEIGHT,HEAD_WIDTH,ORIGIN,ORIGIN);
    WINDOW *tail = subwin(tsk_l->lwin,TAIL_HEIGHT,TAIL_WIDTH,HEAD_HEIGHT + BODY_HEIGHT,ORIGIN);
    WINDOW *body = subwin(tsk_l->lwin,BODY_HEIGHT,BODY_WIDTH,HEAD_HEIGHT,ORIGIN);
    touchwin(tsk_l->lwin); 
    whline(head,0,HEAD_WIDTH);
    box(tail, 0, 0);
    box(body, 0, 0);
    wrefresh(head);
    wrefresh(tail);
    wrefresh(body);
    getch();
    // static bool is_running = true;
    //
    // while(is_running) {
    //     if (tsk_l->n_tasks == 0) {
    //         //
    //     }
    // }
}

void __AppendTask (ToDoList_t *tsk_l, TaskToDo_t t) {}

void __SwapTask (ToDoList_t *tsk_l,size_t n) {}

TaskToDo_t __EraseTask (ToDoList_t *tsk_l,size_t n) {}

ToDoList_t InitializeList(WINDOW **win) {
    if (!win || !*win) {
        #ifdef DEBUG
        assert(*win);
        #else
        printf("could not initialize the todo list.");
        #endif // DEBUG
    }
    TaskToDo_t *__tasks = calloc(CAPACITY,sizeof(TaskToDo_t));
    if (!__tasks) {
        printw("could not allocate memory for tasks\n");
    }
    ToDoList_t ret_v = {
        .Run = __Run,
        .AppendTask = __AppendTask,
        .SwapTask = __SwapTask,
        .EraseTask = __EraseTask,
        .lwin = *win,
        .capacity = CAPACITY,
        .n_tasks = 0,
        .tasks  = __tasks
    };
    *win = NULL;
    return ret_v;
}