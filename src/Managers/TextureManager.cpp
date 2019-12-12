//
// Created by jean- on 2019-11-29.
//

#include "TextureManager.h"
TextureManager::TextureManager() {
    this->render = nullptr;
    surface = nullptr;
    texture = nullptr;
}

void TextureManager::loadTexture(const std::string path, SDL_Renderer* render) {
    this->render = render;
    surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);
}

void TextureManager::draw() {
    SDL_RenderCopy(render, texture, NULL, &screenRect);
}

TextureManager::~TextureManager() {
    SDL_DestroyTexture(texture);
}

void TextureManager::setScreenRect(int x, int y, int w, int h) {
    this->screenRect = {x,y,w,h};
}



void TextureManager::setScreenRectW(int w) {
    screenRect.w = w;
}

void TextureManager::setScreenRectH(int h) {
    screenRect.h = h;
}

const SDL_Rect &TextureManager::getScreenRect() const {
    return screenRect;
}
