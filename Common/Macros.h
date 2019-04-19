//-------------------------------------------------------------------- 
// 文件名:		Macros.h 
// 内  容:		公用的宏定义
// 说  明:		
// 创建日期:	2012年7月30日	
// 创建人:		
// 版权所有:	
//--------------------------------------------------------------------

#ifndef _MACROS_H
#define _MACROS_H


#ifdef _WIN32
#define FX_SYSTEM_WINDOWS
#ifdef _WIN64
#define FX_SYSTEM_64BIT
#else
#define FX_SYSTEM_32BIT
#endif // _WIN64
#endif // _WIN32

#ifdef __linux__
#define FX_SYSTEM_LINUX
#define FX_SYSTEM_64BIT
#endif // __linux__

#ifdef FX_SYSTEM_WINDOWS
#include <stddef.h>
#pragma warning(disable: 4786)
#pragma warning(disable: 4996)
#pragma warning(disable: 4819)
#pragma warning(disable: 4786)
#define FX_DLL_EXPORT __declspec(dllexport)
typedef   signed long long int64_t;
typedef unsigned long long uint64_t;
typedef   signed long long SI64;
typedef unsigned long long UI64;
typedef unsigned long long USERTYPE;
#endif // FX_SYSTEM_WINDOWS

typedef unsigned char			UI08;
typedef unsigned short			UI16;
typedef unsigned int			UI32;
// #ifdef _WIN32
// typedef unsigned __int64		UI64;
// #else
// typedef uint64_t				UI64;
// #endif//_WIN32

#ifdef FX_SYSTEM_LINUX
typedef unsigned short		   WCHAR;
#else
typedef wchar_t 			   WCHAR;
#endif//_WIN32
typedef char				   SI08;
typedef short				   SI16;
typedef int					   SI32;

#ifdef FX_SYSTEM_LINUX
#include <stddef.h>
#include <stdint.h>
#define stricmp strcasecmp
#define wcsicmp wcscasecmp
#define strnicmp strncasecmp
#define FX_DLL_EXPORT __attribute__((visibility("default")))
#define __cdecl	
typedef   signed long long SI64;
typedef unsigned long long UI64;
typedef unsigned long long USERTYPE;
#endif // FX_SYSTEM_LINUX

#ifdef FX_SYSTEM_LINUX
#include <hash_map>
#ifndef FX_GNU_HASH
#define FX_GNU_HASH
namespace __gnu_cxx
{
	template<>
	struct hash<long long int>
	{
		size_t
			operator()( const long long int x ) const
		{
			return x;
		}
	};
	template<>
	struct hash<unsigned long long int>
	{
		size_t
			operator()( const unsigned long long int x ) const
		{
			return x;
		}
	};
	template<> struct hash< std::string >
	{
		size_t operator()( const std::string& x ) const
		{
			return hash< const char* >()( x.c_str() );
		}
	};
	template<> struct hash< std::wstring >
	{
		size_t operator()( const std::wstring& x ) const
		{
			const wchar_t* name = x.c_str();

			size_t h = 0;

			for (; *name; name++)
			{
				h = h * 5 + *name;
			}

			return h;
		}
	};
#endif
}
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)	{ if (p) { (p)->Release(); (p) = NULL; } }
#endif // !SAFE_RELEASE


#define SAFE_DELETE(p)       { if(p) { ::delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { ::delete[] (p);   (p)=NULL; } }

#define WORD1(p)		(p & 0xFFFF)
#define WORD2(p)		((p >> 16) & 0xFFFF)
#define BYTE1(p)		(p & 0xFF)
#define BYTE2(p)		((p >> 8) & 0xFF)
#define BYTE3(p)		((p >> 16) & 0xFF)
#define BYTE4(p)		((p >> 24) & 0xFF)

typedef unsigned char		UI08,BYTE;
typedef unsigned short		UI16;
typedef unsigned int		UI32;
typedef char				SI08;
typedef short				SI16;
typedef int					SI32;

#ifdef FX_SYSTEM_LINUX	
typedef unsigned short		_WCHAR;
#else
typedef wchar_t 			_WCHAR;
#endif//_WIN32

// SOCKET句柄
typedef size_t			SOCK_HANDLE;	

#define	UI32_MAX		0xFFFFFFFF
#define UI16_MAX		0xFFFF
#define UI08_MAX		0xFF

#include "Debug.h"

#endif // _MACROS_H

