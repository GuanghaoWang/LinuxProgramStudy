#ifndef __COMMON_HDR_H__
#define __COMMON_HDR_H__

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "get_num.h"
#include "error_func.h"

typedef enum {FALSE, TRUE} Boolean;

#define Min(m,n) ((m)<(n)?(m):(n))
#define Max(m,n) ((m)>(n)?(m):(n))

#endif
