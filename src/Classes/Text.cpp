//
// Created by jean- on 2019-11-29.
//
#include "Text.h"

#include <utility>

void Text::init( SDL_Renderer* render, std::string path, std::string text){
    this->text = text;
    color = {0,0,0,255};
    font = TTF_OpenFont(path.c_str(), 50);
    this->render = render;
    changeText(std::move(text));
    x = 0;
    y = 0;

}

void Text::draw() {
    SDL_RenderCopy(render, textTexture, NULL, &position);
}

Text::~Text() {
    SDL_DestroyTexture(textTexture);
}

void Text::changeText(std::string text) {
    this->text = text;
    textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    textTexture = SDL_CreateTextureFromSurface(render, textSurface);
    SDL_FreeSurface(textSurface);
}

void Text::changeColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    color = {r,g,b,a};
}

void Text::setPosition(int x, int y, int w, int h) {
    position = {x,y,w,h};
}

const std::string &Text::getText() const {
    return text;
}
