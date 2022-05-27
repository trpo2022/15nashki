#pragma once

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <libpyatnashki/Utility.h>

enum DIRECTION{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Field{
public:
    
    Field(int size);
    ~Field();
    bool CheckWin();
    void TryMove(DIRECTION dir);
    void GenerateField();
    void ShowField();

private:
    int size;
    int** field;
    int null_i;
    int null_j;
};