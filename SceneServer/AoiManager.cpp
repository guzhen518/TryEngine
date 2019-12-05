#include "AoiManager.h"


AoiManager::AoiManager()
{

}

AoiManager::~AoiManager()
{

}

int AoiManager::OnEnterAoi(AoiEntity* pAoiEntity)
{
	InsertEntity(pAoiEntity);
	UpdateAoiMap(pAoiEntity);

	return 1;
}

int AoiManager::OnLeaveAoi(AoiEntity* pAoiEntity)
{

	return 1;
}

int AoiManager::OnUpdateAoi(AoiEntity* pAoiEntity)
{
	return 1;
}

void AoiManager::InsertEntity(AoiEntity* pAoiEntity)
{
	
}

void AoiManager::UpdateAoiList(AoiEntity* pAoiEntity, bool dir, int xy)
{

}


void AoiManager::UpdateAoiMap(AoiEntity* pAoiEntity)
{

}


