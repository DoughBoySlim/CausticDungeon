#pragma once

class Dungeon;
class Player;

class GameLoop
{
private:
	Dungeon& dungeonGrid;
	Player& player;
public:

	GameLoop(class Dungeon& dungeonRef, class Player& playerRef);
	void run();

	void attackPhase();

};

