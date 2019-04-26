//-------------------------------------------------------------------- 
// �ļ���:		Debug.cpp 
// ��  ��:		���Թ���
// ˵  ��:		
// ��������:	2012��10��28��	
// ������:		
// ��Ȩ����:	
//--------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "Macros.h"

void _AssertionFail(const char * strFile, int nLine)
{
	::fflush(stdout);
	::fprintf(stderr, "Asssertion failed: file %s, line %d", strFile, nLine);
	::fflush(stderr);
	::abort();
}

#ifdef NDEBUG

#define CUSTOMALLOC

#ifdef CUSTOMALLOC

#define NO_NED_NAMESPACE

// extern "C"
// {
// 	// ע���ˣ����ͷ�ļ������޸��ˣ�����Ӧvc2005
// #include "../extern/nedmalloc/nedmalloc.h"
// };

void *operator new(std::size_t count) throw(std::bad_alloc)
{
	if (count == 0)
	{
		count = 1;
	}
	return malloc(count);
}

void *operator new(std::size_t count, const std::nothrow_t&) throw()
{
	if (count == 0)
	{
		count = 1;
	}
	return malloc(count);
}

void *operator new(std::size_t count, int blockUse, const char * szFileName, int nLine) throw(std::bad_alloc)
{
	if (count == 0)
	{
		count = 1;
	}
	return malloc(count);
}

void *operator new(std::size_t count, int blockUse, const char * szFileName, int nLine, const std::nothrow_t&) throw()
{
	if (count == 0)
	{
		count = 1;
	}
	return malloc(count);
}

void *operator new[](std::size_t count) throw(std::bad_alloc)
{
	if (count == 0)
	{
		count = 1;
	}
	return malloc(count);
}

void *operator new[](std::size_t count, const std::nothrow_t&) throw()
{
	if (count == 0)
	{
		count = 1;
	}
	return malloc(count);
}

void operator delete(void* mem) throw()
{
	if (mem == NULL)
	{
		return;
	}
	free(mem);
}

void operator delete(void* mem, size_t size)
{
	if (mem == NULL)
	{
		return;
	}
	free(mem);
}

void operator delete[](void* mem) throw()
{
	if (mem == NULL)
	{
		return;
	}
	free(mem);
}

void operator delete[](void* mem, size_t size)
{
	if (mem == NULL)
	{
		return;
	}
	free(mem);
}

#endif //CUSTOMALLOC
#endif //NDEBUG
