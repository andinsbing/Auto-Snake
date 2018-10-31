#pragma once

namespace Global
{
	enum class GameItem
	{
		None,
		SnakeBody,
		Wall,
		Food
	}; 
	namespace GameArea
	{
		constexpr const int WIDTH = 40;
		constexpr const int HEIGHT = 20;
	}
}