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

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: \n\t%s \"username\" \"objective\"\n",*argv);
    }
    WINDOW* root = initscr();
#ifdef DEBUG
    assert(root);
#else 
    if (!root) {
        perror("initscr");
        return EXIT_FAILURE;
    }
#endif // DEBUG

    printw(" --- todo-c implementation ---");
    printw("%s,%s,%s\n",argv[0],argv[1],argv[2]);
    if (!argv[1] || !argv[2]) {
        if (!argv[1]) {
            argv[1] =  SanitizeInput(getDialogInput("What is your name? "));
        }
        argv[2] = SanitizeInput(getDialogInput("What is your main objective for today? "));
    }

    int x,y;
    getmaxyx(stdscr,y,x);

    WINDOW *task_l_win = newwin(y,x,0,0);
    ToDoList_t task_list = InitializeList(&task_l_win);
    getch();
    endwin();

    printf("-- todo-c --\n\tuser: %s\n\tobjective: %s\n",argv[1],argv[2]);
    return EXIT_SUCCESS;
}