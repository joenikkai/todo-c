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