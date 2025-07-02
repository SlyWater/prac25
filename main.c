#include "main.h"


int main()
{
    system("mkdir -p files");
    setlocale(LC_ALL, "Russian");
    int choice;

    do
    {
        //Выводим меню и считываем выбор пользователя
        system("clear");
        display_menu();
        scanf("%d", &choice);
        handle_menu_choice(choice);
    }
    while (choice != 0);
    return 0;
}