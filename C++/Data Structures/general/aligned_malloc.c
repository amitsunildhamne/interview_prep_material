#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint16_t offset_t;
#define PTR_OFFSET sizeof(offset_t)
#define align_up(size, align) (uintptr_t *)((size + (align-1)) & ~(align-1))
// we use size + (align -1). Reason is if we have 0x52 & 0x50, we'll  get 0x50,
//but we dont have access to 0x50. So add up the size + align -1

void *my_memalign(size_t alignment, size_t size)
{
	int req_size = size + (PTR_OFFSET + alignment - 1);
	// PTR_OFFSET + align - 1 because possible we get best alignment but we
	// dont have any memory left to store offset

	void *mem = malloc(req_size);
	void *ptr = align_up((uintptr_t)mem + PTR_OFFSET, alignment);
	*((offset_t *)ptr - 1) = (uintptr_t *)ptr - (uintptr_t *)mem;
	printf("Original Memory:%p New:%p Offset:%x\n", mem, ptr, *((offset_t *)ptr -1));
	return ptr;
}

void my_free(void *ptr)
{
	void *mem = (uintptr_t *)ptr - *((offset_t *)ptr - 1);
	free(mem);
}

int main(void)
{
	size_t size = 56;
	size_t alignment = 256;

	void *mem = my_memalign(alignment, size);
	my_free(mem);

	return 0;
}

