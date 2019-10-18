#ifndef		_SCENE_DEFINE_GAME_H_
#define		_SCENE_DEFINE_GAME_H_


class TryGameScene
{
public:
	TryGameScene();
	~TryGameScene();
public:
	int OnSceneEnter();
	int OnSceneLeave();
	int OnSceneUpdate();

private:
	int m_nSceneID;
	int m_nSceneType;

};



#endif
