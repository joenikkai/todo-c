# Copyright (C) 2026  Joseph Wangai Mwaniki joenikkai@gmail.com
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
# 
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
cmake_minimum_required(VERSION 3.10)
project(todo-c C)

add_executable(
    ${PROJECT_NAME} 
    src/main.c
    src/todo-c.c
)


target_include_directories(
    ${PROJECT_NAME}
    PUBLIC 
    ${CMAKE_SOURCE_DIR}/libs
    ${CMAKE_SOURCE_DIR}/libs/include
)


# add ncursesw
find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSESW REQUIRED ncursesw)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE 
    ${NCURSESW_LIBRARIES}
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE 
    ${NCURSES_INCLUDE_DIRS}
)

target_link_options(
    ${PROJECT_NAME}
    PRIVATE 
    ${NCURSES_LDFLAGS_OTHER}
)