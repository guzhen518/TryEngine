#ifndef	_AOI_MANAGER_H_
#define _AOI_MANAGER_H_

#include "AoiEntity.h"


class AoiManager
{
public:
	AoiManager();
	~AoiManager();

public:
	AoiEntity* CreateAoiEntity();
	int OnEnterAoi(AoiEntity* pAoiEntity);
	int OnLeaveAoi(AoiEntity* pAoiEntity);
	int OnUpdateAoi(AoiEntity* pAoiEntity);
private:
	void InsertEntity(AoiEntity* pAoiEntity);
	void UpdateAoiList(AoiEntity* pAoiEntity, bool dir, int xy);
	void UpdateAoiMap(AoiEntity* pAoiEntity);
private:
	AOI_LIST m_x_list;
	AOI_LIST m_y_list;	
};


#endif