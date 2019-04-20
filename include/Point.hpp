#pragma once

namespace Minesweeper
{

	struct Point 
	{
		int x;
		int y;

		bool operator ==(const Point& other) const;
		bool operator !=(const Point& other) const;
	};

	struct BSize 
	{
		int width;
		int height;
	};

}