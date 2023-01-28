#pragma once
#include <string>

#include "tinyxml2.h"
using namespace tinyxml2;

struct ballPosition {
	int posX1;
	int posY1;
	int posX2;
	int posY2;
};

struct playerPosition {
	int posX1;
	int posX2;
};

struct lvlDataStruct {
	std::string rowCount;
	std::string columnCount;
	std::string rowSpacing;
	std::string columSpacing;
	std::string backTexturePath;
};

struct retBrickVals {
	std::string hardnessID;
	std::string texturePath;
	std::string hitPoints;
	std::string audioHit;
	std::string audioBreak;
	std::string breakScore;
};

lvlDataStruct getLevelData();
retBrickVals getBrickData(XMLElement* pPassedElement);
std::string removeSpaces(std::string str);
