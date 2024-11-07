#pragma once
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
enum
{
    Lshape,
    Sshape,
    Vshape,
    line,
    Tshape,
    Stshape,
    boxshape,
    cross,
    one,
    bigIshape
};

class peice
{
protected:
    int *pivotR, *pivotC;

public:
    vector<vector<int>> shape;
    vector<vector<int>> temp;
    peice(/* args */);
    ~peice();
    void reset();
    void move(char);
    void rotate();
    void mirror();
    int count = 0;
};

peice::peice(/* args */)
{
    srand(time(0));
    if (count == 0)
    {
        reset();
        count += 1;
    }
}

peice::~peice()
{
}

void peice::reset()
{
    int randPeice;
    shape.clear();
    randPeice = rand() % 12;
    switch (randPeice)
    {
    case Lshape:
        shape.push_back({13, 5}); // main
        shape.push_back({12, 5});
        shape.push_back({14, 5});
        shape.push_back({14, 6});
        break;
    case Sshape:
        shape.push_back({13, 5}); // main
        shape.push_back({12, 4});
        shape.push_back({12, 5});
        shape.push_back({13, 4});
        break;
    case Vshape:
        shape.push_back({13, 5}); // main
        shape.push_back({12, 5});
        shape.push_back({14, 5});
        break;
    case line:
        shape.push_back({13, 5}); // main
        shape.push_back({12, 5});
        shape.push_back({13, 6});
        break;
    case Tshape:
        shape.push_back({13, 5}); // main
        shape.push_back({12, 4});
        shape.push_back({12, 5});
        shape.push_back({12, 6});
        shape.push_back({14, 5});
        break;
    case Stshape:
        shape.push_back({13, 5}); // main
        shape.push_back({12, 5});
        shape.push_back({13, 4});
        shape.push_back({13, 6});
        break;
    case boxshape:
        shape.push_back({13, 5}); // main
        shape.push_back({12, 5});
        shape.push_back({14, 5});
        shape.push_back({14, 6});
        shape.push_back({13, 6});
        shape.push_back({12, 6});
        shape.push_back({13, 4});
        shape.push_back({14, 4});
        shape.push_back({12, 4});
        break;
    case cross:
        shape.push_back({13, 5}); // main
        shape.push_back({12, 5});
        shape.push_back({14, 5});
        shape.push_back({13, 6});
        shape.push_back({13, 4});
        break;
    case one:
        shape.push_back({13, 5}); // main
        break;
    case bigIshape:
        shape.push_back({13, 5}); // main
        shape.push_back({12, 4});
        shape.push_back({12, 5});
        shape.push_back({12, 6});
        shape.push_back({14, 4});
        shape.push_back({14, 5});
        shape.push_back({14, 6});
        break;
    default:
        shape.push_back({13, 5}); // main
        shape.push_back({12, 5});
        break;
    }
    pivotR = &shape[0][0];
    pivotC = &shape[0][1];
}

void peice::move(char command)
{
    bool high = false, low = false, side = false;

    if (command == 'w')
    {
        for (int r = 0; r < shape.size(); r++)
        {
            if (shape[r][0] <= 0)
            {
                high = true;
                break;
            }
        }
        for (int r = 0; r < shape.size(); r++)
        {
            if (high == false)
            {
                shape[r][0] -= 1;
            }
            else
            {
                shape[r][0] += 1;
            }
        }
    }

    else if (command == 'a')
    {
        for (int r = 0; r < shape.size(); r++)
        {
            if (((shape[r][1] <= 0) && shape[r][0] <= 1) || shape[r][1] <= 0)
            {
                side = true;
                break;
            }
        }
        for (int r = 0; r < shape.size(); r++)
        {
            if (side == false)
            {
                shape[r][1] -= 1;
            }
            else
            {
                shape[r][1] += 9;
            }
        }
    }
    else if (command == 's')
    {
        for (int r = 0; r < shape.size(); r++)
        {
            if (shape[r][0] == 15)
            {
                low = true;
                break;
            }
        }
        for (int r = 0; r < shape.size(); r++)
        {
            if (low == false)
            {
                shape[r][0] += 1;
            }
            else
            {
                shape[r][0] -= 1;
            }
        }
    }
    else if (command == 'd')
    {
        for (int r = 0; r < shape.size(); r++)
        {
            if (shape[r][1] >= 10)
            {
                side = true;
                break;
            }
        }
        for (int r = 0; r < shape.size(); r++)
        {
            if (side == false)
            {
                shape[r][1] += 1;
            }
            else
            {
                shape[r][1] -= 9;
            }
        }
    }
}

void peice::mirror()
{
    temp = shape;
    for (int r = 1; r < temp.size(); r++)
    {
        if (*pivotC != temp[r][1])
        {

            if (*pivotC < temp[r][1])
            {
                shape[r][1] -= 2;
            }
            if (*pivotC > temp[r][1])
            {
                shape[r][1] += 2;
            }
        }
    }
}

void peice::rotate()
{
    temp = shape;
    for (int r = 1; r < temp.size(); r++)
    {
        if (*pivotR != temp[r][0] || *pivotC != temp[r][1])
        {

            if (*pivotR < temp[r][0] && *pivotC == temp[r][1])
            {
                shape[r][0] -= 1;
                shape[r][1] -= 1;
            }
            if (*pivotR > temp[r][0] && *pivotC == temp[r][1])
            {
                shape[r][0] += 1;
                shape[r][1] += 1;
            }
            if (*pivotR == temp[r][0] && *pivotC < temp[r][1])
            {
                shape[r][0] += 1;
                shape[r][1] -= 1;
            }
            if (*pivotR == temp[r][0] && *pivotC > temp[r][1])
            {
                shape[r][0] -= 1;
                shape[r][1] += 1;
            }

            if (*pivotR < temp[r][0] && *pivotC < temp[r][1])
            {
                shape[r][1] -= 2;
            }
            if (*pivotR > temp[r][0] && *pivotC < temp[r][1])
            {
                shape[r][0] += 2;
            }
            if (*pivotR < temp[r][0] && *pivotC > temp[r][1])
            {
                shape[r][0] -= 2;
            }
            if (*pivotR > temp[r][0] && *pivotC > temp[r][1])
            {
                shape[r][1] += 2;
            }
        }
    }
}