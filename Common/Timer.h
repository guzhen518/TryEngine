#ifndef _LIB_COMMON_TIMER_H_
#define  _LIB_COMMON_TIMER_H_

#include "Macros.h"

typedef int(__stdcall* LOGIC_TIMER_FUNC)(void* pContext, int64_t nId, unsigned int nTime);

class CTimer
{
public:

protected:

private:
	struct timer_data_t 
	{
		timer_data_t* pPrev;	//双向链表 -前指针
		timer_data_t* pNext;	//双向链表 -后指针
	
		LOGIC_TIMER_FUNC func;

	};

};


#endif //_LIB_COMMON_TIMER_H_
