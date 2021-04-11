#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
	SUCCESS,
	FAILURE,
	NOMEM,
	EMPTY,
} ErrorCode;

typedef struct {
	uint8_t *Buf;
	int Size;
	int CurrSize;
	int RdPtr;
	int WrPtr;
} CircBuf;

ErrorCode CircBufInit(CircBuf **circBuf, int Size)
{
	ErrorCode Status = -FAILURE;

	*circBuf = (CircBuf *)malloc(sizeof(CircBuf));
	if (NULL == *circBuf) {
		Status = -NOMEM;
		goto done;
	}

	(*circBuf)->Buf = (uint8_t *)malloc(sizeof(uint8_t)*Size);
	if (NULL == (*circBuf)->Buf) {
		Status = -NOMEM;
		free(*circBuf);
		goto done;
	}

	memset((void *)(*circBuf)->Buf, 0, sizeof(uint8_t)*Size);
	(*circBuf)->Size = Size;
	(*circBuf)->CurrSize = 0;
	(*circBuf)->WrPtr = -1;
	(*circBuf)->RdPtr = 0;
	Status = SUCCESS;

done:
	return Status;
}

void PrintQueue(CircBuf *circBuf)
{
	int i;

	for (i = 0; i < circBuf->Size; ++i) {
		printf("%u\t", circBuf->Buf[i]);
	}

	printf("\n");

	for (i = 0; i < circBuf->Size; ++i) {
		printf("%u\t", i);
	}

	printf("\n");
}

uint8_t DeQueue(CircBuf *circBuf)
{
	ErrorCode Status = -FAILURE;

	if (NULL == circBuf) {
		Status = -NOMEM;
		goto done;
	}

	if (0 <= circBuf->Size) {
		Status = -EMPTY;
		goto done;
	}

	printf("%s: %u\n", __func__, circBuf->Buf[circBuf->RdPtr]);
	circBuf->RdPtr = (circBuf->RdPtr + 1)%circBuf->Size;
	--circBuf->CurrSize;
	Status = SUCCESS;

done:
	return Status;
}

int Queue(CircBuf *circBuf, uint8_t c)
{
	ErrorCode Status = -FAILURE;

	if (NULL == circBuf) {
		Status = -NOMEM;
		goto done;
	}

	circBuf->WrPtr = (circBuf->WrPtr + 1)%circBuf->Size;
	circBuf->Buf[circBuf->WrPtr] = c;
	++circBuf->CurrSize;

	if (circBuf->Size <= circBuf->CurrSize) {
		DeQueue(circBuf);
	}

	PrintQueue(circBuf);
	Status = SUCCESS;
done:
	return Status;
}


int main(int argc, char **argv)
{
	int i;
	int Size;
	int NumItrs = 25;
	bool RdWrt;
	ErrorCode Status = -FAILURE;

	srand(time(0));

	if (2 == argc) {
		Size = atoi(argv[1]);
		printf("Size:%d\n", Size);
	} else {
		printf("Usage: ./a.out <size>\n");
	}

	CircBuf *circBuf = NULL;
	Status = CircBufInit(&circBuf, Size);
	if (SUCCESS != Status) {
		printf("Initialization failure\n");
	}

	for (i = 0; i < NumItrs; ++i) {
		RdWrt = rand()&1;
		if (RdWrt)
			Status = Queue(circBuf, rand() % UCHAR_MAX);
		else
			printf("%u\n", DeQueue(circBuf));
	}

	return 0;
}
