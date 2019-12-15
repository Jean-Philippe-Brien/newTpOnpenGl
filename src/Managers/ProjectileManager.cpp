//
// Created by ssohy on 12/9/2019.
//

#include "ProjectileManager.h"


ProjectileManager::ProjectileManager() {

}

void ProjectileManager::init() {

}
void ProjectileManager::update(CollisionManager* cm,Player* player,Enemy* enemy) {

    checkBulletAlive();
    for(Projectile *p : projectile){

        p->isProjectileAlive();
        if(cm->detectWallCollision(p->getPosition(), 0.1)){
            p->setIsAlive(false);
        }
        p->draw();
        if(cm->detectBulletCollision(p->getPosition(),enemy->getPosition())){
            p->setIsAlive(false);
            enemy->setHp(enemy->getHp()-20);
            if(enemy->getHp()==0){
                enemy->setIsAlive(false);
                delete enemy;
            }
        }
    }
}

ProjectileManager::~ProjectileManager() {

}

void ProjectileManager::checkBulletAlive() {
    std::vector<int> temp;
    for(int i = 0; i < projectile.size(); i++){
        if(!projectile[i]->getIsAlive()){
            temp.push_back(i);
        }
    }
    for(int i = 0; i < temp.size(); i++){
        projectile.erase(projectile.begin() + temp[i]);
    }

}
void ProjectileManager::createProjectile(Player *player) {
    float p = SDL_GetTicks();
    if(player->getLastFire() + player->getFireRate1() < p ) {
        player->setLastFire(SDL_GetTicks()) ;
        projectile.push_back(new Projectile(player->getRotation() + player->getCanonRotation() , player->getPos()));
    }
}