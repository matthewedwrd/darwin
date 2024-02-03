#pragma once

#ifdef _WIN32
#define ENDL "\r\n"
#elif __unix__
#define ENDL "\n"
#else
#define ENDL "\n"
#endif