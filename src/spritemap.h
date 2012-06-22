#ifndef SPRITEMAP_H
#define SPRITEMAP_H

#include "sffv2loader.h"
#include "spritemanager.h"

#define USE_SPRMGR  1

class SpriteMap
{
    public:
        SpriteMap();
        ~SpriteMap();

		int open(const char *filename);
		int close();

		int parse(int group, int index);
		int x();
		int y();
		int width();
		int height();

		void drawAt(int dx, int dy, bool v, bool h);
    private:
        /**
		 * Fun��o chamada para receber qual surface desenhar, dependendo
		 * da invers�o (H,V,HV,), se n�o existir ela ir� criar as surfaces;
		 * @arg v	Invers�o vertical
		 * @arg h	Invers�o horizontal
		 */
		SDL_Surface *whatsSurface(bool v, bool h);

		bool isloaded;
#if USE_SPRMGR
		SFFV2LoaderPtr loader;
#else
		SFFV2Loader loader;
#endif
		SFFv2::SpriteDef *spr;
		SFFv2::PaletteDef *pal;
};

#endif // SPRITEMAP_H
