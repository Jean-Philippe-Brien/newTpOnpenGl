//
// Created by jean- on 2019-11-29.
//

#ifndef MONPROJETSDL_TEXTUREMANAGER_H
#define MONPROJETSDL_TEXTUREMANAGER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class TextureManager {
    protected:
        SDL_Texture *texture;

        SDL_Renderer* render;
        SDL_Surface* surface;
        std::string path;
    public:
    const std::string &getPath() const;

    SDL_Rect screenRect = {0,0,0,0};
        explicit TextureManager( );
        ~TextureManager();
        virtual void loadTexture(std::string path, SDL_Renderer* render);

        virtual void draw();

        void setScreenRectW(int w);
        void setScreenRectH(int h);

    const SDL_Rect &getScreenRect() const;

    virtual void setScreenRect(int x, int y, int w, int h);
};


#endif //MONPROJETSDL_TEXTUREMANAGER_H
