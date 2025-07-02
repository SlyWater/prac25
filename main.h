#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#define REVERSE 1
#define NORMAL 0

int* read_numbers_from_file(const char* filename, int* count);
void fill_file_with_random_numbers(const char* filename, int count, int min, int max);
void handle_menu_choice(int choice);
void display_menu();
void write_file(const char* output_filename, int* numbers, int count);
void create_file_path(const char* filename, char* path);
void create_path(char* input_path, char* output_path);
void selection_sort_file(const char* input_filename, const char* output_filename, char order);
void sort_by_order(const char* input_path, const char* output_path);
void pause_linux();

#endif //MAIN_H
