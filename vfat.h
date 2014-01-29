#include <stdint.h>

/* TODO: try out if sector size of 4096 is acceptable to hosts.
 * It would be more efficient. */
#define SECTOR_SIZE 512
#define ALIGN(x, sz) (((x) + (sz) - 1) & ~((typeof(x))(sz) - 1))

void vfat_init(const char *target_dir, uint64_t free_space, const char *label);
int vfat_fill(void *buf, uint64_t from, uint32_t len);
uint32_t vfat_adjust_size(uint32_t blocks, uint32_t block_size);
