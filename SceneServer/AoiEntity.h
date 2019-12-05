#ifndef _AOI_ENTITY_H_
#define _AOI_ENTITY_H_

#include <list>
#include "SceneEntity.h"



//typedef std::std::map<key, value> map;

class AoiEntity
{
public:
	AoiEntity();
	~AoiEntity();
public:
	void AddAoiEntity();
	void DelAoiEntity();
	void ClearAoiMap();
	void UpdateAoiMap();


};

typedef std::list<AoiEntity*> AOI_LIST;

#endif