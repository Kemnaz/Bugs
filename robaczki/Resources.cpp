#include "Resources.h"

Resources::Resources()
{
}

void Resources::initTextures()
{
	if (!bugtexture.loadFromFile("textures\\bee.png")) {
		system("pause");
	}
	if (!beehive.loadFromFile("textures\\beehive.png")) {
		system("pause");
	}
}
