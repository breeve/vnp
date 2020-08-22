/* Copyright (C) 2011-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Chris Metcalf <cmetcalf@tilera.com>, 2011.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <https://www.gnu.org/licenses/>.  */

#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>
#include <kernel_stat.h>

#include <sysdep.h>
#include <sys/syscall.h>

#if !XSTAT_IS_XSTAT64
#include "overflow.h"
#include <statx_cp.h>

/* Get information about the file NAME in BUF.  */
int
__fxstatat (int vers, int fd, const char *file, struct stat *buf, int flag)
{
  if (vers == _STAT_VER_KERNEL)
    {
# ifdef __NR_fstatat64
      int rc = INLINE_SYSCALL (fstatat64, 4, fd, file, buf, flag);
# else
      struct statx tmp;
      int rc = INLINE_SYSCALL (statx, 5, fd, file,
                               AT_NO_AUTOMOUNT | flag,
                               STATX_BASIC_STATS, &tmp);
      if (rc == 0)
        __cp_stat64_statx ((struct stat64 *)buf, &tmp);
# endif
      return rc ?: stat_overflow (buf);
    }

  errno = EINVAL;
  return -1;
}
libc_hidden_def (__fxstatat)
#endif
