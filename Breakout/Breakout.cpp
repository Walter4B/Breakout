#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include "tinyxml2.h"

#include <string>
#include <iostream>
#include <iomanip>

class Breakout
{
    std::string level;
    int lvlWidth = 20;
    int lvlHeight = 30;
public:
    Breakout()
    {
        //name
        //score?
    }


    bool OnPlayerCreate()
    {
        level = +"H H H H H H H H H H H H H H H H H H H H";
        level = +"M M I I M M M M M M M M M M M M I I M M";
        level = +"S S S S S S S S S S S S S S S S S S S S";
        
        return true;
    }

    bool OnPlayerUpdate()
    {
        al_init();
        al_create_display((lvlWidth * 32) + 90, (lvlHeight * 16) + 60);

        for (int i = 0; i < lvlHeight; i++)
        {
            for (int j = 0; j < lvlWidth; j++)
            {
                al_draw_filled_rectangle(1.5, 1.5, 33.5, 33.5, al_map_rgb(1,2,3));
                switch (level[i * lvlWidth + j])
                {
                case 'S':
                    
                    break;
                case 'M':
                    break;
                case 'H':
                    break;
                case 'I':
                    break;
                }
            }
        }
        return true;
    }
};


class Player
{
    //shape and color
    //move <- ->
    //relese ball (space)
    //ball angle values 
};

class Brick
{
    int blockw = 16;
    int blockh = 8;
    //color and hardnes
    //colizion detect
    //call socre
};

class Ball
{
    //ball movement
    //on collision get new move vector

};




int main1()
{
    Breakout newGame;
    newGame.OnPlayerCreate();
  

    
   // lvlData.Bricks.Print()


    //tinyxml2::Document
    //TiXmlDocument doc("LvlData.xml");

    //al_clear_to_color(al_map_rgb(255, 0, 255));
    al_flip_display(); //update display
    al_rest(5.0);
    return 0;
}

