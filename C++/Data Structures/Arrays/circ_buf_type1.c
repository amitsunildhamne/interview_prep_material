/*
 * Uses 1 space to differentiate between full and empty case
 * Buffer Implementation:
 *  ------------------------
 *  | 0 | 1 | 2 | 3 | 4 | 5 |
 *  ------------------------
 *                H   T
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct circ_buf {
    char *buf;
    int size;
    int head;
    int tail;
} circbuf_t;

circbuf_t *circular_buffer_init(int size)
{
    circbuf_t *circbuf = (circbuf_t *)malloc(sizeof(circbuf_t));
    circbuf->buf = (char *)malloc(sizeof(char)*size);
	memset(circbuf->buf, 0, circbuf->size * sizeof(char));
    circbuf->head = 0;
    circbuf->tail = 0;
	circbuf->size = size;
    return circbuf;
}

static inline bool is_empty(circbuf_t *circbuf)
{
    if (circbuf->head == circbuf->tail)
        return true;
	return false;
}

static inline bool is_full(circbuf_t *circbuf)
{
    if (((circbuf->head + 1) % circbuf->size) == circbuf->tail)
        return true;
	return false;
}

static int fill_spaces(circbuf_t * const circbuf)
{
    int size = circbuf->size - 1;

    if (true == is_empty(circbuf)) {
        size = 0;
    } else if (false == is_full(circbuf)) {
        if (circbuf->head >= circbuf->tail) {
            size = (circbuf->head - circbuf->tail);
        } else if (circbuf->head < circbuf->tail) {
            size = (size - circbuf->tail + 1) + circbuf->head;
        }
    }

    return size;
}

int circular_buffer_push(circbuf_t *const circbuf, char data)
{
    if (true == is_full(circbuf)) {
        printf("Is Full\n");
        return -1;
    }

    circbuf->buf[circbuf->head] = data;
    circbuf->head = (circbuf->head + 1) % circbuf->size;
    return 0;
}

int circular_buffer_pop(circbuf_t *const circbuf, char *data)
{
    int next;

    if (true == is_empty(circbuf)) {
        printf("Is empty\n");
        return -1;
    }

    next = circbuf->tail + 1;
    if (circbuf->size <= next) {
        next = 0;
    }

    *data = circbuf->buf[circbuf->tail];
    circbuf->tail = next;
    return 0;
}

void print_arr(const circbuf_t *circbuf)
{
	int i;
	printf("head:%d tail:%d\t Buf:", circbuf->head, circbuf->tail);
	for (i = 0; i < circbuf->size; ++i) {
		printf("%d ", (int)circbuf->buf[i]);
	}
	printf("\n");
}

int main(void)
{
    int size = 5;
	int ret;
    char c;
    circbuf_t *circbuf = circular_buffer_init(10);
    srand(time(0));

    for (int i = 0; i < 40; ++i) {
        if (((uint32_t)rand() & 1) == 0) {
            ret = circular_buffer_push(circbuf, rand()%128);
        } else {
            ret = circular_buffer_pop(circbuf, &c);
        }
		print_arr(circbuf);
    }

    return 0;
}
