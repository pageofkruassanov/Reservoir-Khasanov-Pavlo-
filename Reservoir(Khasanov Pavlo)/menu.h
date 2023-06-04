#pragma once

#include "includes.h"

enum menuList {
    ADD,
    DELETE,
    DISPLAY,
    SAVE,
    EXIT
};

void displayMenu(int button);
bool moveMenu(int& button);