/**
 * @file
 * @brief Shared Macro definitions for client API's
*/

#pragma once
#ifdef _WIN32
//    #define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#endif
#include <assert.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <memory>
#include <cmath>
#include <cstdint>
#include <streambuf>

#ifdef _DEBUG
#define ZERO_OUTPUT()    { memset(output, 0x00, outputSize); }
#define EXTENSION_RETURN() {output[outputSize-1] = 0x00; } return;
#else
#define ZERO_OUTPUT()
#define EXTENSION_RETURN() return;
#endif

#ifdef _WINDOWS
#define sleep(x) Sleep(x)
#endif



#ifdef _DEBUG
#define ACRE_ASSERT assert()
#else
#define ACRE_ASSERT intercept::runtime_assert()
#endif
