#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

/* Include --------------------------------------------*/
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define __IO    volatile
#define __O     volatile
#define __I     volatile const
#define NULL_PTR  ((void*)0)

#ifndef FALSE
  #define FALSE 0
#endif
#ifndef TRUE
  #define TRUE  1
#endif

#endif /* __STD_TYPES_H__ */