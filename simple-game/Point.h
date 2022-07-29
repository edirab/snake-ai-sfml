#pragma once
class Point
{
public:
	Point();
	explicit Point(int x, int y);

	int x{ 0 };
	int y{ 0 };

	void set(int x, int y);

	bool operator==(const Point& p);
};
