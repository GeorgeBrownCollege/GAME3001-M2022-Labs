#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Obstacle.h"
#include "Scene.h"
#include "PathNode.h"
#include "Starship.h"
#include "Target.h"


class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene() override;

	// Scene LifeCycle Functions
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Clean() override;
	virtual void HandleEvents() override;
	virtual void Start() override;
private:
	// IMGUI Function
	void GUI_Function();
	std::string m_guiTitle;
	bool m_isGridEnabled;

	// Input Control
	int m_pCurrentInputType{};
	void GetPlayerInput();
	void GetKeyboardInput();

	// Game Objects
	Target* m_pTarget;
	Starship* m_pStarship;
	std::vector<Obstacle*> m_pObstacles;

	void BuildObstaclePool();

	// Create our Division Scheme (Grid of PathNodes)
	std::vector<PathNode*> m_pGrid;
	void m_buildGrid();
	void m_toggleGrid(bool state);
	void m_checkShipLOS(DisplayObject* target_object) const; // TODO: need to delete this one

	bool m_checkAgentLOS(Agent* agent, DisplayObject* target_object);
	bool m_checkPathNodeLOS(PathNode* path_node, DisplayObject* target_object);
	void m_checkAllNodesWithTarget(DisplayObject* target_object);
	void m_checkAllNodesWithBoth();
	void m_setPathNodeLOSDistance(int dist);
	int m_LOSMode; // 0 = nodes visible to target, 1 = nodes visible to the player, 2 = nodes visible to both

	void m_clearNodes();
	int m_pathNodeLOSDistance;
};

#endif /* defined (__PLAY_SCENE__) */