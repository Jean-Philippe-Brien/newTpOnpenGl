//
// Created by jean- on 2019-11-29.
//

#ifndef MONPROJETSDL_TEXT_H
#define MONPROJETSDL_TEXT_H
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>


class Text {
private:
    int x, y;
    std::string text;
    TTF_Font* font;
    SDL_Renderer* render;
    SDL_Surface *textSurface;
    SDL_Texture *textTexture;
    SDL_Rect position;
    SDL_Color color;
public:
    void init(SDL_Renderer* render, std::string path, std::string text);
    ~Text();
    void draw();
    void changeText(std::string text);
    void changeColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void setPosition(int x, int y, int w, int h);

    const std::string &getText() const;
};


#endif //MONPROJETSDL_TEXT_H
