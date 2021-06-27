/*
 * Uses bool flag to indicate to differentiate between full and empty case
 * Buffer Implementation:
 *  ------------------------
 *  | 0 | 1 | 2 | 3 | 4 | 5 |
 *  ------------------------
 *        T       H
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
	bool empty;
} circbuf_t;

circbuf_t *circular_buffer_init(int size)
{
    circbuf_t *circbuf = (circbuf_t *)malloc(sizeof(circbuf_t));
    circbuf->buf = (char *)malloc(sizeof(char)*size);
	memset(circbuf->buf, 0, circbuf->size * sizeof(char));
    circbuf->head = 0;
    circbuf->tail = 0;
	circbuf->size = size;
	circbuf->empty = true;
    return circbuf;
}

static inline bool is_empty(const circbuf_t *circbuf)
{
	if ((circbuf->empty == true) && (circbuf->head == circbuf->tail)) {
		return true;
	}

	return false;
}

static inline bool is_full(const circbuf_t *circbuf)
{
	if ((circbuf->empty == false) && (circbuf->head == circbuf->tail)) {
		return true;
	}

	return false;
}

static int fill_spaces(const circbuf_t * circbuf)
{
	if (is_empty(circbuf) == true) {
		return 0;
	} else {
		if (circbuf->head > circbuf->tail) {
			return circbuf->head - circbuf->tail;
		} else{
			return circbuf->head + circbuf->size - circbuf->tail;
		}
	}

	return 0;
}

int circular_buffer_push(circbuf_t *const circbuf, char data)
{
	if (is_full(circbuf) == true) {
		printf("Is full\n");
		return -1;
	}

	circbuf->empty = false;
	circbuf->buf[circbuf->head] = data;
	if (circbuf->head + 1 >= circbuf->size)
		circbuf->head = 0;
	else
		circbuf->head += 1;

	return 0;
}

int circular_buffer_pop(circbuf_t *const circbuf, char *data)
{
	if (is_empty(circbuf) == true) {
		printf("Is empty\n");
		return -1;
	}

	*data = circbuf->buf[circbuf->tail];
	if (circbuf->tail + 1 > circbuf->size)
		circbuf->tail = 0;
	else
		circbuf->tail += 1;

	if (circbuf->tail == circbuf->head)
		circbuf->empty = true;

	return 0;
}

void print_arr(circbuf_t *circbuf)
{
	int i;
	printf("head:%d tail:%d curr_size:%d\tBuf:", circbuf->head, circbuf->tail,
			fill_spaces(circbuf));
	for (i = 0; i < circbuf->size; ++i) {
		printf("%d ", (int)circbuf->buf[i]);
	}
	printf("\n");
}

int main(void)
{
    int size = 5;
    char c;
	int ret;
    circbuf_t *circbuf = circular_buffer_init(size);
    srand(time(0));

    for (int i = 0; i < 40; ++i) {
        if (((uint32_t)rand() & 1) == 0) {
            ret = circular_buffer_push(circbuf, rand()%128);
			(void)ret;
        } else {
            ret = circular_buffer_pop(circbuf, &c);
			(void)ret;
        }
		print_arr(circbuf);
    }

    return 0;
}
