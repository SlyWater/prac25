#include "main.h"

void pause_linux()
{
    printf("Нажмите Enter для продолжения...");
    getchar();
    getchar();
}

int* read_numbers_from_file(const char* filename, int* count)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Ошибка: не удалось открыть файл %s\n", filename);
        *count = 0;
        return NULL;
    }

    int capacity = 10;
    int* numbers = malloc(capacity * sizeof(int));
    if (!numbers)
    {
        fclose(file);
        fprintf(stderr, "Ошибка: не удалось выделить память\n");
        *count = 0;
        return NULL;
    }

    int num_count = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        char* cleaned_line = strtok(line, "\n\r ");
        if (cleaned_line != NULL)
        {
            int number;
            if (sscanf(cleaned_line, "%d", &number) == 1)
            {
                if (num_count >= capacity)
                {
                    capacity *= 2;
                    int* new_numbers = realloc(numbers, capacity * sizeof(int));
                    if (!new_numbers)
                    {
                        free(numbers);
                        fclose(file);
                        fprintf(stderr, "Ошибка: не удалось перевыделить память\n");
                        *count = 0;
                        return NULL;
                    }
                    numbers = new_numbers;
                }
                numbers[num_count++] = number;
            }
            else
            {
                fprintf(stderr, "Строка '%s' не является числом и будет пропущена.\n", cleaned_line);
            }
        }
    }
    fclose(file);
    *count = num_count;
    return numbers;
}

void fill_file_with_random_numbers(const char* filename, int count, int min, int max)
{
    FILE* file = fopen(filename, "w");
    srand(time(NULL));
    //Данный блок кода заполняет файл случайными числами
    for (int i = 0; i < count; i++)
    {
        int number = min + rand() % (max - min + 1);
        fprintf(file, "%d\n", number);
    }
    fclose(file);
}

void write_file(const char* output_filename, int* numbers, int count)
{
    FILE* output_file = fopen(output_filename, "w");
    //Данный блок кода записывает отсортированный массив в файл
    for (int i = 0; i < count; i++)
    {
        fprintf(output_file, "%d\n", numbers[i]);
    }
    fclose(output_file);
}

void create_file_path(const char* filename, char* path)
{
    //Создаем путь к файлам ввода или вывода
    snprintf(path, 50, "files/%s.txt", filename);
}

void create_path(char* input_path, char* output_path)
{
    char input_filename[40];
    char output_filename[40];
    //Данный блок кода запрашивает у пользователя имена файлов для ввода или вывода
    system("clear");
    printf("Введите имя файла с несортированными числами (без расширения): ");
    scanf("%255s", input_filename);
    create_file_path(input_filename, input_path);
    printf("Введите имя файла с сортированными числами (без расширения): ");
    scanf("%255s", output_filename);
    create_file_path(output_filename, output_path);
}

void selection_sort_file(const char* input_filename, const char* output_filename, char order)
{
    pause_linux();
    // TODO selection sort

}

void display_menu()
{
    //Отображаем меню действий, которые может выполнить пользователь
    printf("1. Сортировка определенного файла\n");
    printf("2. Сортировка файла с определенным количеством чисел\n");
    printf("0. Выход\n");
    printf("Выберите пункт меню: ");
}

void sort_by_order(const char* input_path, const char* output_path)
{
    pause_linux();
    // TODO choice order
}

void handle_menu_choice(int choice)
{
    int count, min, max;
    char pathi[50], patho[50];
    system("clear");
    //Считываем, какое действие выбрал пользователь и выполняем его
    switch (choice)
    {
    case 1:
        //Если пользователь выбрал сортировку массива числа к которому лежат в заданном файле
        create_path(pathi, patho);
        sort_by_order(pathi, patho);

        break;
    case 2:
        //Если пользователь выбрал сортировку массива со случайными числами
        printf("Введите количество чисел: ");
        scanf("%d", &count);
        printf("Введите минимальное значение: ");
        scanf("%d", &min);
        printf("Введите максимальное значение: ");
        scanf("%d", &max);
        create_path(pathi, patho);
        fill_file_with_random_numbers(pathi, count, min, max);
        sort_by_order(pathi, patho);
        break;
    case 0:
        //Выход из программы
        printf("Выход из программы.\n");
        break;
    default:
        printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
        getchar();
        break;
    }
}