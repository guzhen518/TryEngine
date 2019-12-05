#ifndef	 _SCENE_DEFINE_ENTITY_H_	
#define  _SCENE_DEFINE_ENTITY_H_

#include "GameScene.h"
typedef struct  
{
	int nPosX;
	int nPosY;
	int nPosZ;
} Position;

typedef int32_t ENTITY_ID;

class TrySceneEntity
{
public:
	TrySceneEntity();
	~TrySceneEntity();

private:

	ENTITY_ID m_nEntityID;
	Position m_stPos;
	TryGameScene* m_pGameScene;

};
#endif
