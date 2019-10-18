#ifndef	 _SCENE_DEFINE_ENTITY_H_	
#define  _SCENE_DEFINE_ENTITY_H_

typedef struct  
{
	int nPosX;
	int nPosY;
	int nPosZ;
} Position;

class TrySceneEntity
{
public:
	TrySceneEntity();
	~TrySceneEntity();

private:

	int m_nEntityID;
	Position m_stPos;


};
#endif
