/* See COPYRIGHT for copyright information. */

#ifndef JOS_INC_ASSERT_H
#define JOS_INC_ASSERT_H

#include <inc/stdio.h>

void _warn(const char*, int, const char*, ...);
void _panic(const char*, int, const char*, ...) __attribute__((noreturn));

#define warn(...) _warn(__FILE__, __LINE__, __VA_ARGS__)
#define panic(...) _panic(__FILE__, __LINE__, __VA_ARGS__)

#define assert(x)		\
	do { if (!(x)) panic("assertion failed: %s", #x); } while (0)

// static_assert(x) will generate a compile-time error if 'x' is false.
#define static_assert(x)	switch (x) case 0: case (x):

#define DEBUG_1(on, pause, val)                                                  \
do                                                                               \
{                                                                                \
        if(on)                                                                   \
        {                                                                        \
                cprintf("[DEBUG Info]: val:%s = %08x\n", #val, (uint32_t)(val)); \
                while(pause && (getchar() != 'c')) ;                             \
        }                                                                        \
}while(0)

#define DEBUG_2(on, pause, val)                                                  \
do                                                                               \
{                                                                                \
        if(on)                                                                   \
        {                                                                        \
                cprintf("[DEBUG Info]: val:%s = %08x %s:%s:%d\n",                \
                        #val, (uint32_t)(val), __FILE__, __func__, __LINE__);    \
                while(pause && (getchar() != 'c')) ;                             \
        }                                                                        \
}while(0)

#define DEBUG_X(on, pause, vals_fmt, ...)                                        \
do{                                                                              \
        if(on)                                                                   \
        {                                                                        \
                cprintf("[DEBUG Info]: %s:%s:%d\n[DEBUG Info]: ",                \
                                __FILE__, __func__, __LINE__);                   \
                cprintf(vals_fmt, __VA_ARGS__);                                  \
                cprintf("\n");                                                   \
                while(pause && (getchar() != 'c')) ;                             \
        }                                                                        \
}while(0)

#endif /* !JOS_INC_ASSERT_H */
