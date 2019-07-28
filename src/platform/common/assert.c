#include "assert.h"
#include "log.h"

#ifdef USE_FULL_ASSERT

void assert_failed(const char *func, uint32_t line, const char *reason)
{
  /* Log the error */
  logs("\n[%s: %d] %s !", func, (int)line, reason);

  /* Infinite loop */
  while(true);
}

#endif