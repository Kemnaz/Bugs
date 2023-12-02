#include "Resources.h"

Resources::Resources()
{
}

void Resources::initTextures()
{
	if (!bugtexture.loadFromFile("C:\\Users\\User\\Documents\\Unreal Projects\\Bugs\\robaczki\\textures\\ant.png")) {
		system("pause");
	}
}
