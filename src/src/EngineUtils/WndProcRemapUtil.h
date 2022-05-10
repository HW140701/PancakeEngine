#ifndef WNDPROC_REMAP_UTIL_H_
#define WNDPROC_REMAP_UTIL_H_

#include <windows.h>

const SIZE_T PageSize = 4096;

//产生一个代理函数
template <typename T>
static WNDPROC MakeObjectInstance(LPVOID AObject, T AMethod)
{
	union
	{
		T        MethodAddr;//成员函数指针
		LPVOID   NomralAddr;//正常指针
	}ut;//因为VC不允许成员函数指针转换到普通指针。只能变通的通过union来实现
	const unsigned char BlockCode[] = {
#ifdef _WIN64
	0x55,//{ push rbp }
	0x48, 0x83, 0xEC, 0x40,//{ sub rsp,0x40 }
	0x48, 0x8B, 0xEC,//{ mov rbp,rsp }
	0x48, 0x89, 0x4D, 0x50,//{ mov[rbp + 0x50],rcx }
	0x89, 0x55, 0x58,//{ mov[rbp + 0x58],edx }
	0x4C, 0x89, 0x45, 0x60,//{ mov[rbp + 0x60],r8 }
	0x4C, 0x89, 0x4D, 0x68,//{ mov[rbp + 0x68],r9 }
	0x48, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//{ mov rcx,AObject }
	0x48, 0x8B, 0x55, 0x50,//{ mov rdx,[rbp + 0x50] }
	0x44, 0x8B, 0x45, 0x58,//{ mov r8,[rbp + 0x58] }
	0x4C, 0x8B, 0x4D, 0x60,//{ mov r9,[rbp + 0x60] }
	0x48, 0x8B, 0x45, 0x68,//{ mov rax,[rbp + 0x68] }
	0x48, 0x89, 0x44, 0x24, 0x20,//{ mov[rsp + 0x20],rax }
	0x49, 0xBB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//{ mov r11, AMethod }
	0x49, 0xFF, 0xD3,//{ call r11 }
	0x48, 0x8D, 0x65, 0x40,//{ lea rsp,[rbp + 0x40] }
	0x5D,//{ pop rbp }
	0xC3//{ ret }

#else
	0x58,//{ pop eax }
	0x68, 0x00, 0x00, 0x00, 0x00,//{ push AObject }
	0x50,//{ push eax }
	0xB8, 0x00, 0x00, 0x00, 0x00,//{ mov eax, AMethod }
	0xFF, 0xE0//{ jmp eax }

#endif // endif
	};

	size_t CodeBytes = sizeof(BlockCode);
	LPVOID  Block = VirtualAlloc(nullptr, PageSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(Block, BlockCode, CodeBytes);
	unsigned char* bBlock = (unsigned char*)Block;
	ut.MethodAddr = AMethod;
#ifdef _WIN64
	*PLONG64(&bBlock[25]) = LONG64(AObject);
	*PLONG64(&bBlock[0x38]) = LONG64(ut.NomralAddr);
#else
	*PLONG32(&bBlock[2]) = LONG32(AObject);
	*PLONG32(&bBlock[8]) = LONG32(ut.NomralAddr);
#endif
	return (WNDPROC)Block;
}

// 释放代理函数
static void FreeObjectInstance(WNDPROC wndProc)
{
	VirtualFree(wndProc, PageSize, MEM_RELEASE);
}

#endif // !WNDPROC_REMAP_UTIL_H_
