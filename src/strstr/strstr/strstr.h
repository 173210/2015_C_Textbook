﻿#if (defined(_MSC_VER) && _MSC_VER > 1000) || (defined(__clang__) && (__clang_major__ > 3 || (__clang_major__ == 3 && __clang_minor__ > 2))) ||(defined(__ICC) && __ICC > 1000) ||defined (__GNUC__) && !defined(__ICC) && !defined(__clang__) && (__GNUC__ >= 4 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#pragma once
#endif
#ifndef _INC_MY_STRSTR_H
#define _INC_MY_STRSTR_H
const char *my_strstr(const char *str, const char *strSearch);
#endif