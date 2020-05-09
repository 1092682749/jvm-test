// ClassReader.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <Windows.h>






#define BUFFER_LEN 10240
byte readBuffer[BUFFER_LEN] = { 0 };
DWORD readNumber = 0;

// 大、小端序相互转换
void EndianSwap(byte *pData, int startIndex, int length)
{
	int i, cnt, end, start;
	cnt = length / 2;
	start = startIndex;
	end = startIndex + length - 1;
	byte tmp;
	for (i = 0; i < cnt; i++)
	{
		tmp = pData[start + i];
		pData[start + i] = pData[end - i];
		pData[end - i] = tmp;
	}
}
int main()
{
	HANDLE hFile = CreateFile(L"C:\\Users\\dyz\\Desktop\\ProjectCode\\jvm-test\\target\\classes\\com\\dyz\\jvm\\ClassFinal.class", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	int fileSize = 0;
	int count = 0;
	byte char4[4] = { 0 };
	USHORT minor_version = 0;
	USHORT major_version = 0;
	USHORT constant_counn =  0;
	
	do {
		
		bool f = ReadFile(hFile, readBuffer, BUFFER_LEN, &readNumber, NULL);
		if (!f)
		{
			std::cout << "readFile error: " << GetLastError() << "\n";
		}
		if (count == 0) {
			CopyMemory(char4, readBuffer, 4);
			CopyMemory(&minor_version, readBuffer + 4, 2);
			CopyMemory(&major_version, readBuffer + 6, 2);
			count++;
		}
		fileSize += readNumber;
		//printf("%s", readBuffer);
		WCHAR utf8Code[1024] = { 0 };

		//MultiByteToWideChar(CP_UTF8, MB_COMPOSITE, readBuffer, readNumber, utf8Code, 0);
		//printf("%s", utf8Code);
	} while (readNumber > 0);
	printf("\n该class文件的前四位字节的16进制表示为: %x", char4[0]);
	printf(" %x", char4[1]);
	printf(" %x", char4[2]);
	printf(" %x\n", char4[3]);
	EndianSwap((byte*)(&major_version), 0, 2);
	printf(" 主版本号：%x\n", major_version);
	EndianSwap((byte*)(&minor_version), 0, 2);
	printf(" 次版本号：%x\n", minor_version);
	std::cout << "fileSize is:" << fileSize << "\n";
	//printf("==========================%s\n", char4);
}









// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
