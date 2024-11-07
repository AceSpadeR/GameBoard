#include <iostream>
#include <time.h>
#include "peice.h"
#include "board.h"

int main()
{
    bool game = true;
    char command;
    char again;
    bool commandC = true, placev = true;
    while (game == true)
    {
        board b;
        peice p;

        system("cls");
        b.display();
        while (commandC == true)
        {
            cout << "Enter Command: ";
            cin >> command;
            if (command == 'q')
            {

                cout << "Would you like to play again y/n: ";
                cin >> again;
                if (again == 'y')
                {
                    b.Again();
                }
                else
                { 
                    commandC = false;
                    game = false;
                    break;
                }
            }
            system("cls");
            if ((command == 'a' || command == 'w' || command == 'd' || command == 's'))
            {
                p.move(command);
                b.remove();
                b.Moving(p);
                b.display();
            }
            else if (command == 'r')
            {
                p.rotate();
                b.remove();
                b.Moving(p);
                b.display();
            }
            else if (command == 'f')
            {
                p.mirror();
                b.remove();
                b.Moving(p);
                b.display();
            }
            else if (command == 'e')
            {
                b.place(placev);
                if (placev != false)
                {
                    p.reset();
                    b.check();
                }
                b.display();
                placev = true;
            }
            else
            {
                b.display();
            }
        }
    }

    return 0;
}