// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <math.h>

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <D2d1_1helper.h>

#pragma comment(lib, "d2d1.lib")


// TODO: reference additional headers your program requires here
template<class Interface>
inline void SafeRelease(Interface **ppInterfaceToRelease)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}

//#ifndef Assert
//
//#if defined(DEBUG) || defined(_DEBUG)
//	#define Assert(b)										\
//		do													\
//		{													\
//			if (!(b))										\
//			{												\
//				OutputDebugStringA("Assert: " #b "\n");		\
//			}												\
//		} while (0)											
//#else	
//	#define Assert(b)
//#endif // DEBUG || _DEBUG
//
//#endif

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif