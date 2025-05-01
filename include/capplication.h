#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <stdexcept>

using String = std::string;

#define COUT std::cout
#define PRINT_BLANK std::cout << "\n"
#define CLEAR_CONSOLE system("cls")
#define DEBUG 1

#include "color.h"
#include "object.h"

#include "console.h"
#include "chainlist.h"
#include "application.h"
#include "menu.h"

#include "menu_items.h"

#include "input.h"
