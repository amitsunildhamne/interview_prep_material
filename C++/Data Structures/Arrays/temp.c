#include <stdio.h>
#include <stdlib.h>

typedef struct Buf Buf;

struct Buf {
	int RdPtr;
	int WrPtr;
	char *CharBuf;
	int CurrSize;
	int MaxSize;
};

void BufInit(Buf **buf, int MaxSize)
{
	*buf = (Buf *)malloc(sizeof(Buf));
	(*buf)->RdPtr = -1;
	(*buf)->WrPtr = -1;
	(*buf)->MaxSize = MaxSize;
	(*buf)->CharBuf = (char *)malloc(sizeof(char)*MaxSize);
	(*buf)->CurrSize = 0;
}

int BufRead(Buf *buf)
{
	char c;

	if ((buf->RdPtr == -1) || (buf->CurrSize <= 0)) {
		return -1;
	}

	buf->RdPtr = (buf->RdPtr + 1) % buf->MaxSize;
	c = buf->CharBuf[buf->RdPtr];
	printf("%c\n", c);
	--buf->CurrSize;
	return c;
}

int BufWrite(Buf *buf, char c)
{
	if (buf->CurrSize + 1 >= buf->MaxSize) {
		printf("Read further to empty buffer\n");
		return -1;
	}

	buf->WrPtr = (buf->WrPtr + 1) % buf->MaxSize;
	buf->CharBuf[buf->WrPtr] = c;
	++buf->CurrSize;
	return c;
}

int main(void)
{

}
