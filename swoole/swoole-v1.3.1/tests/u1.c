#include "swoole.h"

void u1_test2()
{
	swPipe p;
	char buf[66535];
	bzero(&p, sizeof(p));
	//int ret = swPipeMsg_create(&p, 0, 0x21000000, 1);
	int ret = swPipeUnsock_create(&p, 1, SOCK_DGRAM);
	if (ret < 0)
	{
		printf("create msg fail.errno=%d\n", errno);
		return;
	}
	ret = p.write(&p, SW_STRL("hello world1"));
	if (ret < 0)
	{
		printf("write fail.errno=%d\n", errno);
		return;
	}
	ret = p.write(&p, SW_STRL("hello world2"));
	if (ret < 0)
	{
		printf("write fail.errno=%d\n", errno);
		return;
	}
	ret = p.write(&p, SW_STRL("hello world3"));
	if (ret < 0)
	{
		printf("write fail.errno=%d\n", errno);
		return;
	}

	ret = p.read(&p, buf, 65535);
	if (ret < 0)
	{
		printf("read fail.errno=%d\n", errno);
		return;
	}
	else
	{
		printf("read str=%s\n", buf);
	}
	ret = p.read(&p, buf, 65535);
	if (ret < 0)
	{
		printf("read fail.errno=%d\n", errno);
		return;
	}
	else
	{
		printf("read str=%s\n", buf);
	}
	ret = p.read(&p, buf, 65535);
	if (ret < 0)
	{
		printf("read fail.errno=%d\n", errno);
		return;
	}
	else
	{
		printf("read str=%s\n", buf);
	}
	ret = p.read(&p, buf, 65535);
	if (ret < 0)
	{
		printf("read fail.errno=%d\n", errno);
		return;
	}
}

void u1_test1()
{
	swPipe p;
	int ret;
	char data[256];

	ret = swPipeBase_create(&p, 1);
	if (ret < 0)
	{
		swTrace("create fail\n");
		return;
	}
	ret = p.write(&p, SW_STRL("hello world") - 1);
	if (ret < 0)
	{
		swTrace("write fail\n");
	}
	ret = p.write(&p, SW_STRL("你好中国。") - 1);
	if (ret < 0)
	{
		swTrace("write fail\n");
	}

	bzero(data, 256);
	ret = p.read(&p, data, 256);
	if (ret < 0)
	{
		swTrace("write fail\n");
	}
	else
	{
		printf("Data = %s\n", data);
	}
}
