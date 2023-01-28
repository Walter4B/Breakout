#include <iostream>
#include <list>
#include <algorithm>

#include "tinyxml2.h"
#include "XMLtoStringData.h"

using namespace tinyxml2;

lvlDataStruct getLevelData()
{
	XMLDocument lvlData;
	const char* ppath = "LvlData.xml";
	lvlData.LoadFile(ppath);
	XMLElement* pRootElement = lvlData.RootElement();
	std::string rowCountLocal = pRootElement->Attribute("RowCount");
	std::string columnCountLocal = pRootElement->Attribute("ColumnCount");
	std::string rowSpacingLocal = pRootElement->Attribute("RowSpacing");
	std::string columSpacingLocal = pRootElement->Attribute("ColumnSpacing");
	std::string backTexturePathLocal = pRootElement->Attribute("BackgroundTexture");
	return lvlDataStruct{rowCountLocal, columnCountLocal, rowSpacingLocal, columSpacingLocal, backTexturePathLocal};
	
}

retBrickVals getBrickData(XMLElement* pPassedElement)
{
	XMLElement* pElement = pPassedElement;
	std::string hardnessVal = pElement->Attribute("Id");
	std::string texturePathVal = pElement->Attribute("Texture");
	std::string hitPointsVal = pElement->Attribute("HitPoints");
	std::string audioHitVal = pElement->Attribute("HitSound");
	std::string audioBreakVal = pElement->Attribute("BreakSound");
	std::string breakScoreVal = pElement->Attribute("BreakScore");
	return retBrickVals{hardnessVal, texturePathVal, hitPointsVal, audioHitVal, audioBreakVal, breakScoreVal};
}


std::string removeSpaces(std::string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

int amain()
{
	
	return 0;
}
