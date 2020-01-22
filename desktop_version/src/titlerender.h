#ifndef TITLERENDERER_H
#define TITLERENDERER_H

#include "Graphics.h"
#include "UtilityClass.h"
#include "Maths.h"
#include "Entity.h"
#include "Map.h"
#include "Script.h"

class Stage
{
public:
    int frameRate;
};

extern Stage stage;
extern Stage swfStage;
extern int temp;

void titlerender(Graphics& dwgfx, mapclass& map, Game& game, entityclass& obj, UtilityClass& help, musicclass& music);

void towerrenderfixedpre(Game& game, mapclass& map, entityclass& obj);
void towerrenderfixedpost(Graphics& dwgfx, Game& game, entityclass& obj, UtilityClass& help);
void towerrender(Graphics& dwgfx, Game& game, mapclass& map, entityclass& obj, UtilityClass& help, const float alpha);

void gamerenderfixedpre(mapclass& map, Game& game, entityclass& obj);
void gamerenderfixedpost(Graphics& dwgfx, mapclass& map, Game& game, entityclass& obj, UtilityClass& help);
void gamerender(Graphics& dwgfx, mapclass& map, Game& game, entityclass& obj, UtilityClass& help, const float alpha, const float deltatime);

void maprender(Graphics& dwgfx, Game& game, mapclass& map, entityclass& obj, UtilityClass& help);

void teleporterrender(Graphics& dwgfx, Game& game, mapclass& map, entityclass& obj, UtilityClass& help);

void gamecompleterender(Graphics& dwgfx, Game& game, entityclass& obj, UtilityClass& help, mapclass& map);

void gamecompleterender2(Graphics& dwgfx, Game& game, entityclass& obj, UtilityClass& help);


#endif /* TITLERENDERER_H */
