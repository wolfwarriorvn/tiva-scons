#ifndef __LOG_H__
#define __LOG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "std_type.h"

void log_print();

void logs(const char *format,...) __attribute__((format(printf, 1, 2)));

void log_init();

#ifdef __cplusplus
}
#endif

#endif /* __LOG_H__ */