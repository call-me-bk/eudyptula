// https://syzkaller.appspot.com/bug?id=0f447249960c780cab5f203c1537c825c74904ae
// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE

#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
	int bkret;
  bkret = syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
  printf("%d syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);\n", bkret);
  bkret = syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
  printf("%d second\n", bkret);
  bkret = syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
  printf("%d third\n", bkret);
  intptr_t res = 0;
  bkret = memcpy((void*)0x20000080, "/dev/nullb0\000", 12);
  printf("%d memcpy\n", bkret);
  res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000080ul,
                0x4000000004002ul, 0ul);
  printf("%d syscall __NR_openat\n", res);
  if (res != -1)
    r[0] = res;
  printf("%d r[0] = res\n", res);
  bkret = syscall(__NR_mmap, 0x20000000ul, 0xe7e000ul, 0x200000eul, 0x13ul, r[0], 0ul);
  printf("%d syscall mmap r[0]\n", bkret);
  *(uint64_t*)0x20000000 = 0x800;
  bkret = syscall(__NR_ioctl, r[0], 0x125d, 0x20000000ul);
  printf("%d syscall __NR_ioctl\n", bkret);
  return 0;
}
