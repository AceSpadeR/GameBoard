#pragma once
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <string.h>
#include "peice.h"
using namespace std;

class board
{
protected:
    char boardT[17][10] =
        {

            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)}, // 10
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
            {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};

public:
    int score = 0, highscore = 0;
    const int ROW = 16, COL = 10;
    void Moving(peice p);
    void remove();
    board(/* args */);
    ~board();
    void display();
    void place(bool &);
    void check();
    void deleteRC();
    void Again();
    vector<int> C;
    vector<int> R;
};

board::board(/* args */)
{
}

board::~board()
{
}

void board::remove()
{
    for (int r = 0; r < ROW; r++)
    {

        for (int c = 0; c < COL; c++)
        {
            if (boardT[r][c] == ' ')
            {
                boardT[r][c] = char(219);
            }
            if (boardT[r][c] == char(176))
            {
                boardT[r][c] = char(178);
            }
        }
    }
}

void board::Moving(peice p)
{

    int r1, c1;
    for (int r = 0; r < p.shape.size(); r++)
    {
        for (int c = 0; c < p.shape[0].size(); c++)
        {
            if (c == 0)
            {
                r1 = p.shape[r][c];
            }
            else
            {
                c1 = p.shape[r][c];
                if (boardT[r1][c1] == char(178) || boardT[r1][c1] == char(176))
                {
                    boardT[r1][c1] = char(176);
                }
                else
                {
                    boardT[r1][c1] = ' ';
                }
            }
        }
    }
}

void board::place(bool &placev)
{
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            if (boardT[r][c] == char(176))
            {
                placev = false;
            }
        }
    }
    if (placev == true)
    {
        for (int r = 0; r < ROW; r++)
        {
            for (int c = 0; c < COL; c++)
            {

                if (boardT[r][c] == ' ')
                {
                    boardT[r][c] = char(178);
                }
            }
        }
    }
}
void board::check()
{
    int temp;
    int count = 0;
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < COL; c++)
        {

            if (boardT[r][c] == char(178))
            {
                count++;
            }
            else
            {
                count = 0;
                continue;
            }
        }
        if (count >= COL)
        {
            R.push_back(r);
            count = 0;
        }
    }
    count = 0;
    for (int c = 0; c < COL; c++)
    {
        for (int r = 0; r < 10; r++)
        {

            if (boardT[r][c] == char(178))
            {
                count++;
            }
            else
            {
                count = 0;
                continue;
            }
        }
        if (count > 9)
        {
            C.push_back(c);
            count = 0;
        }
        // end of Row
    }
    deleteRC();
}

void board::deleteRC()
{
    if (R.size() != 0)
    {
        for (int r = 0; r < R.size(); r++)
        {
            int rowToDelete = R[r];
            for (int c = 0; c < COL; c++)
            {
                boardT[rowToDelete][c] = char(219);
            }
            score += 1;
        }
    }
    if (C.size() != 0)
    {
        for (int c = 0; c < C.size(); c++)
        {
            for (int r = 0; r < ROW; r++)
            {
                boardT[r][C[c]] = char(219);
            }
        }
        score += 1;
    }

    R.clear();
    C.clear();
}

void board::Again()
{
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            if (boardT[r][c] != char(219))
            {
                boardT[r][c] = char(219);
            }
        }
    }
    if (highscore < score)
    {
        highscore = 0;
        highscore += score;
    }
    score = 0;
}

void board::display()
{
    cout << "|=======!1010!=======|" << endl;
    cout << "|W " << char(30) << "|S " << char(31) << "|D " << char(16) << "|A" << char(17) << "|R/"
         << "|F" << char(29) << "|" << endl;
    cout << "|Best: " << setw(3) << highscore
         << "|Score: " << setw(3) << score << "|" << endl;
    for (int r = 0; r < ROW + 1; r++)
    {
        cout << "|";
        for (int c = 0; c < COL; c++)
        {
            if (r == 10 && c == 0)
            {
                cout << "--------------------|" << endl;
                cout << "|" << boardT[r][c] << boardT[r][c];
            }
            else
            {
                cout << boardT[r][c] << boardT[r][c];
            }
        }
        cout << "|" << endl;
    }
}
