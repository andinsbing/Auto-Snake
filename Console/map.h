#pragma once
#include<vector>
#include<functional>
#include<algorithm>
#include"position.h"
#include"global.h"

using ::Global::GameArea::WIDTH;
using ::Global::GameArea::HEIGHT;
using ::Global::GameItem;

class Map
{  
public:
	Map();
	~Map();
	Map(const Map&) = default;
	Map& operator =(const Map&) = default;
 
	//back to initial state
	void Map::renew()
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{ 
				_map[i][j] = GameItem::None;
			}
		}
	}


	void Map::setGameItem(const Position & pos, GameItem gameItem)
	{
		ASSERT_POS_LEGAL(pos.x, pos.y);
		_map[pos.y][pos.x] = gameItem;
	}


	void Map::setGameItem(const std::vector<Position>& poses, Global::GameItem gameItem)
	{
		for (auto& i : poses)
		{
			ASSERT_POS_LEGAL(i.x, i.y);
			_map[i.y][i.x] = gameItem;
		}
	}

	void Map::removeGameItem(const Position & pos)
	{
		ASSERT_POS_LEGAL(pos.x, pos.y);
		_map[pos.y][pos.x] = GameItem::None;
	}


	GameItem Map::getGameItem(const Position & pos) const
	{
		ASSERT_POS_LEGAL(pos.x, pos.y);
		return _map[pos.y][pos.x];
	}


	std::vector<Position> Map::getSet(const GameItem gameItem) const
	{
		std::vector<Position> set;
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (_map[i][j] == gameItem)
				{
					set.push_back({ j,i });
				}
			}
		}
		return std::move(set);
	}
	 
	void Map::forEach(const std::function<void(Global::GameItem)>& fun) const
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				fun(_map[i][j]);
			}
		}
	}

	Position const Map::firsOf(GameItem gameItem) const
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (_map[i][j] == gameItem)
				{
					return{ j,i };
				}
			}
		}
		//not found
		return{ WIDTH,HEIGHT };
	}

	static bool Map::isInLegalRange(const Position & pos)
	{
		return !(pos.x < 0 || pos.x >= Global::GameArea::WIDTH ||
			pos.y < 0 || pos.y >= Global::GameArea::HEIGHT);
	}


	int Map::count(Global::GameItem gameItem) const
	{
		int amout = 0;
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (_map[i][j] == gameItem)
				{
					amout++;
				}
			}
		}
		return amout;
	}


private:
	Global::GameItem _map[Global::GameArea::HEIGHT][Global::GameArea::WIDTH];
};