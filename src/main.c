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
    cbreak();

    printw(" --- " PROJECT_NAME " implementation ---");
    printw("%s,%s,%s\n",argv[0],argv[1],argv[2]);
    char *username = NULL;
    char *objective = NULL;
    if (!argv[1] || !argv[2]) {
        if (!argv[1]) {
            username =  SanitizeInput(getDialogInput("What is your name? "));
        }
        objective = SanitizeInput(getDialogInput("What is your main objective for today? "));
    } else {
        username = argv[1];
        objective = argv[2];
    }

    int x,y;
    getmaxyx(stdscr,y,x);

    ToDoList_t task_list;
    {
        WINDOW *task_l_win = newwin(y,x,0,0);
        assert(task_l_win);
        task_list = InitializeList(&task_l_win);
    }
    task_list.Run(&task_list);
    getch();
    endwin();

    printf("-- "PROJECT_NAME" --\n\tuser: %s\n\tobjective: %s\n",username,objective);
    char *filename = SanitizeInput(GenerateFileName(NULL,username,objective));
    printf("generated file: %s\n",filename);
    free(filename);
    return EXIT_SUCCESS;
}
