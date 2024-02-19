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
#include <windows.h>
#include <conio.h>
#include <random>
using namespace std;

void FillArray(int array[][15], int size);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char pressedButton;

    const int sizeArr = 15;    
    int Array[sizeArr][sizeArr];

    FillArray(Array, sizeArr);

    cout << "Для управления программой используйте стрелочки (вперёд, назад, влево, вправо). Для выхода нажать esc" << std::endl;

    while (true) {
        if (_kbhit()) {
            pressedButton = _getch();
            
            if (pressedButton == -32 || pressedButton == 0) { 
                pressedButton = _getch();  

                switch (pressedButton) {
                case 72:
                    cout << "Up arrow pressed" << std::endl;
                    break;
                case 80:
                    cout << "Down arrow pressed" << std::endl;
                    break;
                case 75:
                    cout << "Left arrow pressed" << std::endl;
                    break;
                case 77:
                    cout << "Right arrow pressed" << std::endl;
                    break;
                default:
                    break;
                }
            }
                        
            if (pressedButton == 27) {
                break;
            }
        }       
    }   
}

void FillArray(int array[][15], int size) 
{
    random_device Random;

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            array[x][y] = Random() % 100;

            cout << array[x][y] << "\t";
        }

        cout << endl;
    }

}
