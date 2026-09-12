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
    getch();
    endwin();
    return EXIT_SUCCESS;
}