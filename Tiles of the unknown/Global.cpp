#include "Global.h"

//General
const char* WINDOWNAME = "Tiles of the unknown dev";
int SCREEN_RESOLUTION_W;
int SCREEN_RESOLUTION_H;

float RESOLUTION_SCALE_W = 1;
float RESOLUTION_SCALE_H = 1;

//Game
float MOVESPEED_W = 0.0003f;
float MOVESPEED_H = 0.0003f;

//Time one frame is showed in milliseconds. Therefore the lower the faster.
int ANIMATIONSPEED_PLAYERWALK = 160;
const uint8_t ANIMATIONLENGTH_PLAYERWALKDOWN = 4;

//Paths
const char* MAPSHEETPATH = "./data/png/mapSheet.png";
const char* PLAYERWALKDOWNSHEETPATH = "./data/png/playerWalkDown.png";
const char* PLAYERWALKUPSHEETPATH = "./data/png/playerWalkUp.png";
const char* PLAYERWALKLEFTSHEETPATH = "./data/png/playerWalkLeft.png";
const char* PLAYERWALKRIGHTSHEETPATH = "./data/png/playerWalkRight.png";

//Scales
float FLOOR_SCALE = 2.0f;
float PLAYER_SCALE = 4.0f;
