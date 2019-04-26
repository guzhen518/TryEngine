//-------------------------------------------------------------------- 
// 文件名:		Debug.h 
// 内  容:		调试工具
// 说  明:		
// 创建日期:	2012年10月28日	
// 创建人:		
// 版权所有:	
//--------------------------------------------------------------------

#ifndef _DEBUG_H
#define _DEBUG_H

//#include "Trace.h"
#include <string>
//#include "Trace.h"

#define NEW new
//#ifndef NDEBUG
//	#define NEW ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#else
//	#define NEW ::new
//#endif // NDEBUG
#define ASSERT_XML_INVALID(node, opt) if (node == NULL){LOG_ERROR("xml node is invalid:%s", #node); opt;}
#define ASSERT_XML_VALUE_INVALID(node, opt) if (node == NULL || node->value() == NULL || node->value() == string("")) \
{ LOG_ERROR("xml value is invalid:%s", #node); opt; }


#ifndef NDEBUG
	void _AssertionFail(const char * strFile, int nLine);
	#define Assert(p)	((p) ? (void)0 : (void)_AssertionFail(__FILE__, __LINE__))
#else
	#define Assert(p)	(void(0))
#endif

#define ASSERT_RETURN(p)						\
		Assert(p);								\
		if (!(p))								\
		{										\
			LOG_ERROR("Assert failed: %s", #p);	\
			return;								\
		}

#define ASSERT_RETURN_VALUE(p, val)				\
		Assert(p);								\
		if (!(p))								\
		{										\
			LOG_ERROR("Assert failed: %s", #p);	\
			return val;							\
		}

#define ASSERT_RETURN_NOLOG(p)					\
		Assert(p);								\
		if (!(p))								\
		{										\
			return;								\
		}

#define ASSERT_RETURN_VALUE_NOLOG(p, val)		\
		Assert(p);								\
		if (!(p))								\
		{										\
			return val;							\
		}

#define CHECK_ITER(iter, container, operate)	\
		if (iter == container.end())			\
		{										\
			operate;							\
		}

#define CHECK_ITER_LOG(iter, container, operate)			\
		if (iter == container.end())						\
		{													\
			LOG_ERROR("iterator error. %s ", #container);	\
			operate;										\
		}

#endif // _DEBUG_H
