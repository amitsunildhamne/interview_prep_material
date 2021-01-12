#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define BUFF_SIZE		5

typedef struct {
	int Size;
	int Ptr;
	int Count;
	uint8_t *Buffer;
} CircBuffer;

void BufferPush_ISR(CircBuffer *buf, uint8_t val);

static inline void PrintArr(int *Arr, int ArrSize)
{
	int i;

	for (i = 0; i < ArrSize; ++i) {
		printf("%d\t", Arr[i]);
	}
	printf("\n");
}

void Test1(CircBuffer *buf)
{
	int i;
	int expected[3];
	int val;

	printf("\nTest1\n");
	for (i = 0; i < 3; ++i) {
		val = (uint8_t)(rand());
		BufferPush_ISR(buf, val);
		expected[i] = val;
	}

	PrintArr(expected, sizeof(expected)/sizeof(expected[0]));
}

void Test2(CircBuffer *buf)
{
	int i;
	int expected[7];
	int val;
	printf("\nTest2\n");

	for (i = 0; i < 7; ++i) {
		val = (uint8_t)(rand());
		BufferPush_ISR(buf, val);
		expected[i] = val;
	}

	PrintArr(expected, sizeof(expected)/sizeof(expected[0]));
}

void Test3(CircBuffer *buf)
{
	int i;
	int expected[6];
	int val;
	printf("\nTest3\n");

	for (i = 0; i < 6; ++i) {
		val = (uint8_t)(rand());
		BufferPush_ISR(buf, val);
		expected[i] = val;
	}

	PrintArr(expected, sizeof(expected)/sizeof(expected[0]));
}

void BufferPush_ISR(CircBuffer *buf, uint8_t val)
{
	const int Size = buf->Size;
	int *Count = &buf->Count;
	uint8_t *Buffer = buf->Buffer;

	if (Size == *Count)
		--(*Count);

	Buffer[buf->Ptr] = val;
	buf->Ptr = (buf->Ptr+1)%Size;
	++(*Count);
}

void PrintClean(CircBuffer *buf)
{
	const int Size = buf->Size;
	int i;
	int Count = buf->Count;
	int Ptr = buf->Ptr;
	uint8_t *Buffer = buf->Buffer;

	printf("%s:\n", __func__);

	for (i = Count>=Size?Ptr:0; Count > 0; i = (i+1)%Size) {
		printf("%u\t", Buffer[i]);
		--Count;
	}

	printf("\n");
	buf->Count = 0;
}

void RemoveBuffer(CircBuffer *buf)
{
	free(buf->Buffer);
	free(buf);
}

int main(void)
{
	int i;
	srand(time(0));

	CircBuffer *circBuffer = (CircBuffer *)malloc(sizeof(CircBuffer));
	circBuffer->Size = BUFF_SIZE;
	circBuffer->Ptr = 0;
	circBuffer->Count = 0;
	circBuffer->Buffer = (uint8_t *)malloc(sizeof(uint8_t)*BUFF_SIZE);

	Test1(circBuffer);
	PrintClean(circBuffer);
	Test2(circBuffer);
	PrintClean(circBuffer);
	Test3(circBuffer);
	PrintClean(circBuffer);

	RemoveBuffer(circBuffer);
	return 0;
}
