/*
 * Insert a string into a circular buffer
 * Circular buffer for string copy:
 * --------------------------------
 * | l | b | c | w | p | a | c | t | 
 * --------------------------------
 *  H:0->3
 *  T:0->1
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define min(a,b) ({ __typeof__ (a) _a = (a); \
					__typeof__ (b) _b = (b); \
					_a < _b ? _a : _b; })

typedef struct {
	char *buf;
	int head;
	int tail;
	int size;
	bool empty;
} circbuf_t;

static inline int buf_count(circbuf_t *circbuf)
{
	int size = circbuf->size;
	if (circbuf->empty == true) {
		return 0;
	} else {
		if (circbuf->head > circbuf->tail) {
			return (circbuf->head - circbuf->tail);
		} else {
			return (circbuf->head + (size - circbuf->tail));
		}
	}

	return -1;
}

static inline bool is_full(circbuf_t *circbuf)
{
	if ((circbuf->empty == false) && (circbuf->head == circbuf->tail)) {
		return true;;
	}

	return false;
}

static inline bool is_empty(circbuf_t *circbuf)
{
	if ((circbuf->empty == true) && (circbuf->head == circbuf->tail)) {
		return true;
	}

	return false;
}

static inline int empty_spaces(circbuf_t *circbuf)
{
	int size = circbuf->size;
	return (size - buf_count(circbuf));
}

static inline int empty_spaces_to_end(circbuf_t *circbuf)
{
	int size = circbuf->size;
	if (is_full(circbuf) || (circbuf->tail > circbuf->head)) {
		return 0;
	} else {
		return (size - circbuf->head);
	}
}

static inline int buf_count_to_end(circbuf_t *circbuf)
{
	int size = circbuf->size;
	if (is_empty(circbuf) || (circbuf->head > circbuf->tail)) {
		return 0;
	} else {
		return (size - circbuf->tail);
	}
}


int circbuf_create(circbuf_t **circbuf, int size)
{
    *circbuf = (circbuf_t *)malloc(sizeof(circbuf_t));
    (*circbuf)->buf = (char *)malloc(sizeof(char)*size);
	memset((*circbuf)->buf, 0, size * sizeof(char));
    (*circbuf)->head = 0;
    (*circbuf)->tail = 0;
	(*circbuf)->size = size;
	(*circbuf)->empty = true;
    return 0;
}

int circbuf_push(circbuf_t *circbuf, const char *str)
{
	int len = strlen(str);
	int buf_empty_avlbl = empty_spaces(circbuf);
	int final_size = min(len, buf_empty_avlbl);
	int copy_size = empty_spaces_to_end(circbuf);
	printf("\nempty_spaces=%d final_size=%d empty_spaces_to_end:%d ",
			buf_empty_avlbl, final_size, copy_size);
	copy_size = min(copy_size, final_size);
	printf("copy_size=%d\n",copy_size);

	if (buf_empty_avlbl < 0) {
		return -1;
	}

	if (buf_empty_avlbl == 0) {
		printf("Buffer full\n");
		return 0;
	}

	circbuf->empty = false;

	memcpy((void *)&circbuf->buf[circbuf->head], (void *)str, copy_size);
	circbuf->head += copy_size;

	if (circbuf->head >= (circbuf->size - 1)) {
		circbuf->head = 0;
	}

	if ((final_size - copy_size) >= 0) {
		memcpy((void *)&circbuf->buf[circbuf->head], (void *)(str + copy_size),
				final_size - copy_size);
	}

	circbuf->head = (circbuf->head + final_size - copy_size)%circbuf->size;

	return 0;
}

int circbuf_pop(circbuf_t *circbuf, char *str, int size)
{
	int buf_space_avlbl =  buf_count(circbuf);
	int final_size = min(size, buf_space_avlbl);
	int copy_size = buf_count_to_end(circbuf);
	printf("\nbuf_count=%d final_size=%d buf_count_to_end:%d ", buf_space_avlbl,
			final_size, copy_size);
	copy_size = min(copy_size, final_size);
	printf("copy_size=%d\n",copy_size);

	if (buf_space_avlbl < 0) {
		return -1;
	}

	if (buf_space_avlbl == 0) {
		printf("Nothing to read\n");
		return 0;
	}

	memcpy((void *)str, (void *)&circbuf->buf[circbuf->tail], copy_size);
	circbuf->tail += copy_size;

	if (circbuf->tail >= (circbuf->size - 1)) {
		circbuf->tail = 0;
	}

	if ((final_size - copy_size) > 0) {
		memcpy((void *)(str + copy_size), (void *)&circbuf->buf[circbuf->tail],
				final_size - copy_size);
	}

	circbuf->tail = (circbuf->tail + final_size - copy_size) % circbuf->size;

	if (circbuf->head == circbuf->tail) {
		circbuf->empty = true;
	}

	return 0;
}

static void print_arr(circbuf_t *circbuf, char *str, int size, bool push)
{
	int i;
	static char prefix[5];
	snprintf(prefix, 5, "Push");
	if (!push) {
		snprintf(prefix, 5, "Pop");
	}

	printf("%s Head=%d Tail=%d Empty=%d MaxSize=%d Size=%d\tArray: ", prefix,
			circbuf->head, circbuf->tail, circbuf->empty, circbuf->size,
			buf_count(circbuf));

	for (i = 0; i < circbuf->size; ++i) {
		printf("%d ", (int)circbuf->buf[i]);
	}

	printf("\nSize:%d Str: ", size);

	for (i = 0; i < size; ++i) {
		printf("%d ", (int)str[i]);
	}
	printf("\n");
}

void circbuf_destroy(circbuf_t *circbuf)
{
	if (circbuf == NULL) {
		return;
	}

	if (circbuf->buf != NULL) {
		free(circbuf->buf);
	}

	circbuf->size = 0;
	circbuf->head = 0;
	circbuf->tail = 0;
	free(circbuf);
}

static void generate_string(char *str, int size)
{
	int i;
	for (i = 0; i < size; ++i) {
		str[i] = rand() % 9;
	}
}

int main(void)
{
	const int size = 8;
	int ret;
	char *push_str = (char *)malloc(sizeof(char) * size);
	char *pop_str = (char *)malloc(sizeof(char) * size);
	int strsize;
	bool push;
	srand(time(0));
	circbuf_t *circbuf = NULL;

	ret = circbuf_create(&circbuf, size);
	if (ret < 0) {
		printf("Unable to create buffer\n");
	}

	for (int i = 0; i < 40; ++i) {
		strsize = rand()%size;
		memset(push_str, 0, size);
		memset(pop_str, 0, size);
		if ((push = (((uint32_t)rand() & 1) == 0))) {
			generate_string(push_str, strsize);
			ret = circbuf_push(circbuf, push_str);
			(void)ret;
			print_arr(circbuf, push_str, size, push);
		} else {
			ret = circbuf_pop(circbuf, pop_str, strsize);
			print_arr(circbuf, pop_str, size, push);
			(void)ret;
		}
	}

	free(pop_str);
	free(push_str);
	circbuf_destroy(circbuf);
	return 0;
}
