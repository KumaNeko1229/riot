#include "environment.h"

namespace Entity{

	Environment::Environment() {
		level += L"........#..##################......#.............";
		level += L"........#...................#......#.............";
		level += L"........#..#................#......############..";
		level += L"...@....#..#................#.................#..";
		level += L"...........#..#################..###..........#..";
		level += L"........#..#.......................#..........#..";
		level += L"........#..#=======..========..##..############..";
		level += L"#########..#................=..##................";
		level += L"...........#................=..##....############";
		level += L"..##########................=..##....#...........";
		level += L"..#........#=================..##.....#..........";
		level += L"..#............................##......#.....#...";
		level += L"..#........#......##########...##.......#....#...";
		level += L"..#....#####......#........#...##........#####...";
		level += L"..#....#..........#........#...##................";
		level += L".......#...#..#####............##......##########";
		level += L"..#....#...#......#....#####...##.....#..........";
		level += L"..#....#...#......#....#.......##....#...........";
		level += L"..######...#......#....#.......##...##########...";
		level += L"...........#......#....#.........................";

		float offsetX = cameraX - (float)visibleX / 2.0f;
		float offsetY = cameraY - (float)visibleY / 2.0f;
	}

	Environment::~Environment() {

	}

	auto Environment::GetTile(float x, float y) {
		if (x >= 0 && x < levelWidth && y >= 0 && y < levelHeight) {
			return level[y * levelWidth + x];
		} 
		else {
			return(L' ');
		}
	}

	auto Environment::SetTile(float x, float y, wchar_t newTile) {
		if (x >= 0 && x < levelWidth && y >= 0 && y < levelHeight) {
			level[y * levelWidth + x] = newTile;
		}
	}


}