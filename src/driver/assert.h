
#ifndef __ASSERT_H__
#define __ASSERT_H__

#include <stdio.h>

/* Exported define ---------------------------------*/
#ifdef USE_FULL_ASSERT
static const char assert_param_text[] = "Assert Failed";
#define assert_param(ptr) ((ptr) ? (void)0 : \
            assert_failed(__FUNCTION__, __LINE__, assert_param_text))
#define assert(ptr) assert_param(ptr)
void assert_failed(const char *func, uint32_t line, const char *reason);
#else
#define assert(ptr)
#define assert_param(ptr)
#endif

#endif /* __ASSERT_H__ */