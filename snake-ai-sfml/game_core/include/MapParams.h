#pragma once

// TODO: Implement singleton?
class MapParams
{
public:

	/*!
	* \brief Default c-tor
	*/
	MapParams() {}

	const int cell_size{ 40 }; // cell size in pixels
	const int width{ 20 }; // map size in cells
	const int height{ 20 };
};
