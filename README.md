# todo-c

> This is a to-do list implemented in the terminal using ncurses wide and c programming language.

It stores a `TODO` file in the path of execution.

## design

[An average person can do 3 to 9 meaning full tasks and a maximum of 10 tasks per day](https://www.carlpullein.com/blog/how-to-avoid-overwhelm-by-only-allowing-10-tasks-per-day/6/2/2019)

This therefore limits the number of tasks that you can input in the app for any particular day to 10
The file generated will have the date time and name of user (if provided) for that specific day `[user]_[datetime]_[expected outcome from the number of tasks].txt`.
The 1 to 4 goals that have the most leverage will appear first.
The user should have atleast done the 3 out of the 4 high leverage goals
