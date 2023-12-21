#include "Resources.h"

Resources::Resources()
{
}

void Resources::initTextures()
{
	if (!bugtexture.loadFromFile("textures\\ant.png")) {
		system("pause");
	}
}
