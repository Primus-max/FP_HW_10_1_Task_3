// Создайте двухмерный массив. Заполните его 
// случайными числами и покажите на экран.Пользователь
// выбирает количество сдвигов и положение(влево, вправо, вверх, вниз).
// Выполнить сдвиг массива и показать на экран полученный результат.Сдвиг циклический.
//    Например, если мы имеем следующий массив
//    1 2 0 4 5 3
//    4 5 3 9 0 1
//    и пользователь выбрал сдвиг на 2 разряда вправо, то мы
//    получим
//    5 3 1 2 0 4
//    0 1 4 5 3 9

#include <iostream>
#include <conio.h>
#include <random>

using namespace std;

const int rows = 15;
const int cols = 15;
int Array[rows][cols];

void FillArray(int array[][cols], int size);
void OffsetToLeft(int array[][cols], int offset, int size);
void OffsetToRight(int array[][cols], int offset, int size);
void PrintArray(int array[][cols], int size);

int main() {
    char pressedButton;

    FillArray(Array, rows);

    cout << "Для управления программой используйте стрелочки (вперёд, назад, влево, вправо). Для выхода нажмите esc" << std::endl;

    while (true) {
        if (_kbhit()) {
            pressedButton = _getch();

            if (pressedButton == -32 || pressedButton == 0) {
                pressedButton = _getch();

                switch (pressedButton) {
                case 72:
                    OffsetToRight(Array, 1, rows);
                    break;
                case 80:
                    OffsetToLeft(Array, 1, rows);
                    break;
                case 75:
                    OffsetToLeft(Array, 2, rows);
                    break;
                case 77:
                    OffsetToRight(Array, 2, rows);
                    break;
                default:
                    break;
                }
            }

            if (pressedButton == 27) {
                break;
            }

            PrintArray(Array, rows);
        }
    }

    return 0;
}

void FillArray(int array[][cols], int size) {
    random_device Random;

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            array[x][y] = Random() % 100;

            cout << array[x][y] << "\t";
        }

        cout << endl;
    }
}

void PrintArray(int array[][cols], int size) {
    system("cls"); 

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

void OffsetToLeft(int array[][cols], int offset, int size) {
    for (int x = 0; x < size; x++) {
        for (int i = 0; i < offset; i++) {
            int temp = array[x][0];
            for (int y = 0; y < size - 1; y++) {
                array[x][y] = array[x][y + 1];
            }
            array[x][size - 1] = temp;
        }
    }
}

void OffsetToRight(int array[][cols], int offset, int size) {
    for (int x = 0; x < size; x++) {
        for (int i = 0; i < offset; i++) {
            int temp = array[x][size - 1];
            for (int y = size - 1; y > 0; y--) {
                array[x][y] = array[x][y - 1];
            }
            array[x][0] = temp;
        }
    }
}
