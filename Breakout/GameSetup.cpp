#include<iostream>
#include <numeric> 
#include <algorithm>

#include <conio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include"XMLtoStringData.h"

#define KEY_LEFT 75
#define KEY_RIGHT 77


retBrickVals brickData[]; //brickData - Data for brick types
lvlDataStruct lvlDataVars; //lvlDataVars - Data for lvl construction
std::string bricksLayoutText; //bricksLayoutText - Layout of bricks
ballPosition currentBallPosition;
playerPosition currentPlayerPosition;

int movePlayer()
{
	float x1 = 270;
	float y1 = 370;
	float speed = 10;
	if (ALLEGRO_KEY_LEFT)
	{
		if (x1 > 0)
		{
			x1 -= speed;
			y1 -= speed;
		}
		else
		{
			x1 = 0;
		}
	}
	if (ALLEGRO_KEY_LEFT)
	{
		if (x1 < 640)
		{
			x1 += speed;
			y1 += speed;
		}
		else
		{
			x1 = 640;
		}
	}
	int playerWidth = 100;
	al_draw_line(x1, 542, y1, 542, al_map_rgb(255, 0, 255), 10);
	return x1;
}

int moveBall()
{
	int ballRadius = 8;
	al_draw_filled_circle(320, 512, ballRadius, al_map_rgb(255, 0, 255));
	return 1;
}



bool OnPlayerUpdate(std::string bricksInLvl)
{
	std::string level = bricksInLvl;
	int lvlWidth = 20;
	int lvlHeight = 30;

	ALLEGRO_DISPLAY* display;
	al_init();
	
	display = al_create_display((lvlWidth * 32), (lvlHeight * 16)+64);
	al_init_primitives_addon();
	bool running = true;

	int numberOfChars = level.length();

	bool exists[30][20];
	int lvlCounter = 0;

	for (int i = 0; i < numberOfChars / 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			exists[i][j] = true;
		}
	}
		while(true){
		for (int i = 0; i < numberOfChars / 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (exists[i][j])
				{
					switch (level[lvlCounter])
					{
					case 'S':
						al_draw_filled_rectangle(1.5 + (32 * j), 1.5 + (16 * i), 32 + (32 * j), 16 + (16 * i), al_map_rgb(0, 0, 255));
						break;
					case 'M':
						al_draw_filled_rectangle(1.5 + (32 * j), 1.5 + (16 * i), 32 + (32 * j), 16 + (16 * i), al_map_rgb(255, 0, 255));
						break;
					case 'H':
						al_draw_filled_rectangle(1.5 + (32 * j), 1.5 + (16 * i), 32 + (32 * j), 16 + (16 * i), al_map_rgb(255, 0, 0));
						break;
					case 'I':
						al_draw_filled_rectangle(1.5 + (32 * j), 1.5 + (16 * i), 32 + (32 * j), 16 + (16 * i), al_map_rgb(0, 255, 0));
						break;
					default:
						break;
					}
					lvlCounter++;
				}
			}
		}
		lvlCounter = 0;
		al_draw_line(270, 542, 370, 542, al_map_rgb(255, 0, 255), 10);

		al_flip_display();
		}
		movePlayer();
		float x1 = 100;
		int c = 0;
			switch ((c = _getch())) {
			case 75:
					x1 += 20;
				break;
			case 77:
					x1 += 20;
				break;
			default:
				break;
			}
			al_draw_line(x1, 542, x1+100, 542, al_map_rgb(255, 0, 255), 10);
		moveBall();
	al_rest(5.0);
	al_destroy_display(display);
	return true;
}
//#include "stdafx.h"


int main() {
	lvlDataStruct lvlDataVars;
	lvlDataVars = getLevelData();

	XMLDocument lvlDataXML;
	const char* ppath = "LvlData.xml";
	lvlDataXML.LoadFile(ppath);
	XMLElement* pRootElement = lvlDataXML.RootElement();

	XMLElement* parent = pRootElement->FirstChildElement("BrickTypes");
	int numberOfStruct = 0;
	retBrickVals brickData[4];
	for (XMLElement* child = parent->FirstChildElement("BrickType"); child != NULL; child = child->NextSiblingElement("BrickType"))
	{
		brickData[numberOfStruct] = getBrickData(child);
		numberOfStruct++;
	}

	std::cout << brickData[0].hardnessID << std::endl;
	std::cout << brickData[0].hitPoints << std::endl;
	std::cout << brickData[0].breakScore << std::endl;
	std::cout << brickData[0].texturePath << std::endl;
	std::cout << brickData[0].audioHit << std::endl;
	std::cout << brickData[0].audioBreak << std::endl;

	std::cout << lvlDataVars.columnCount << std::endl;
	std::cout << lvlDataVars.rowCount << std::endl;

	XMLElement* bricksLayout = pRootElement->FirstChildElement("Bricks");
	std::string bricksLayoutText;
	bricksLayoutText = bricksLayout->GetText();
	bricksLayoutText = removeSpaces(bricksLayoutText);
	bricksLayoutText.erase(std::remove(bricksLayoutText.begin(), bricksLayoutText.end(), '\n'), bricksLayoutText.end());
	std::cout << bricksLayoutText << std::endl;

	OnPlayerUpdate(bricksLayoutText);

	return 0;
}