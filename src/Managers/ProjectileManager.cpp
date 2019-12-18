//
// Created by ssohy on 12/9/2019.
//

#include "ProjectileManager.h"


ProjectileManager::ProjectileManager() {

}

void ProjectileManager::init() {

}
void ProjectileManager::update(CollisionManager* cm,Player* player, std::vector<Enemy*> enemy) {

    checkBulletAlive();
    for(Projectile *p : projectile){
        if(p->getIsAlive()) {
            p->isProjectileAlive();
            if (cm->detectWallCollision(p->getPosition(), 0.1)) {
                p->setIsAlive(false);
            } else if (cm->detectBulletCollision(p->getPosition(), player->getPos())) {
                p->setIsAlive(false);
                std::cout << "it" << std::endl;
                player->setHp(player->getHp() - 10);
            }
            for (Enemy *e : enemy) {
                if (cm->detectBulletCollision(p->getPosition(), e->getPosition())) {
                    p->setIsAlive(false);
                    e->setHp(e->getHp() - 20);
                    if (e->getHp() <= 0) {
                        e->setIsAlive(false);
                        player->setScore(player->getScore() + 100);
                        //delete e;
                    }
                }
            }
            p->draw();
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
        //delete projectile.at(temp[i]);
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
void ProjectileManager::createProjectile(float rotation, glm::vec3 pos) {
    float p = SDL_GetTicks();
    pos.y -= 0.2;
    projectile.push_back(new Projectile(rotation , pos));
}