//
// Created by Sigve Langva on 3/30/2022.
//

#include "Game.h"


Player *player;
int count = 1000;
std::vector<Laser*> lasers;
std::vector<Enemy*> enemies;

Game::Game() {};

Game::~Game() {};

SDL_Renderer *Game::renderer = nullptr;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "subsystem initialised" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window){
            std::cout << "window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            std::cout << "renderer created" << std::endl;
        }

        isRunning = true;
    }
    player = new Player("../Assets/xwing.png", 350,  400, renderer);
    addEnemy(1);

}

void Game::handleEvents() {

    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
// Sjekk om det var en key-event
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:

                    isShooting = true;
                    break;
                case SDLK_s:
                    player->yVel = 1;
                    break;
                case SDLK_w:
                    player->yVel = -1;
                    break;
                case SDLK_d:
                    player->xVel = 1;
                    break;
                case SDLK_a:
                    player->xVel = -1;
                    break;
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
            }
        }
        if (event.type == SDL_KEYUP)
        {
// Sjekk om brukeren trykket Escape

            switch (event.key.keysym.sym) {
                case SDLK_SPACE:

                    isShooting = false;
                    break;
                case SDLK_s:
                    if (player->yVel == 1) player->yVel = 0;
                    break;
                case SDLK_w:
                    if (player->yVel == -1) player->yVel = 0;
                    break;
                case SDLK_d:
                    if (player->xVel == 1)player->xVel = 0;
                    break;
                case SDLK_a:
                    if (player->xVel == -1) player->xVel = 0;
                    break;
            }
        }

// Sjekk om brukeren trykket krysset (X) i vindu
        else if (event.type == SDL_QUIT)
        {
            isRunning = false; // avslutt
        }
    }
    for(auto it = lasers.begin();it !=lasers.end();++it) {
        if(it.operator*()->getY() <= 0 || it.operator*()->getY() >= 600 || it.operator*()->collision()) {
            it.operator*()->outOfMap();
            delete(it.operator*());
            lasers.erase(it);
            break;
        }
    }
    for(auto it = enemies.begin();it !=enemies.end();++it){
        if (!it.operator*()->isAlive()){
            delete(it.operator*());
            enemies.erase(it);
            break;
        }
    }

}

void Game::update() {
    if (isShooting) shooting();
    if (player->isAlive()) player->Update();
    count++;

    for(auto it = lasers.begin();it !=lasers.end();++it){
        if (!it.operator*()->isEnemy()){
            for (auto it2 = enemies.begin();it2 !=enemies.end();++it2) {
                if(it2.operator*()->hit(it.operator*()->getX(), it.operator*()->getY())){
                    std::cout <<"in here\n";
                    it2.operator*()->destroyGameObject();
                    it.operator*()->canDelete();
                    it.operator*()->destroyGameObject();
                }
                std::cout <<"check\n";
            }
        }
        else {
            if (player->hit(it.operator*()->getX(), it.operator*()->getY())) {
                std::cout <<"in here\n";
                player->destroyGameObject();
                it.operator*()->canDelete();
                it.operator*()->destroyGameObject();
            }
        }

        std::cout <<"out\n";

        it.operator*()->Update();
    }
    for (auto it = enemies.begin();it !=enemies.end();++it) {
        it.operator*()->Update();
        eShooting(it.operator*());
    }

    //enemy->Update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    if (player->isAlive()) player->Render(renderer);
    for(auto it = lasers.begin();it !=lasers.end();it++){
        it.operator*()->Render(renderer);
    }
    for (auto it = enemies.begin();it !=enemies.end();++it) {
        it.operator*()->Render(renderer);
    }

    //add stuff too render
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    player->destroyGameObject();
    delete(player);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

void Game::shooting() {
    Laser *l;
    if (count > 50) {
        l = player->shoot(renderer);
        l->setWidthHeight(1, 10);
        lasers.emplace_back(l);
        count = 0;
    }
}
void Game::eShooting(Enemy *e) {
    Laser *l;
    if (e->gunReady()) {
        l = e->shoot(renderer);
        l->setWidthHeight(1, 10);
        lasers.emplace_back(l);
    }
}

void Game::addEnemy(int i) {

    Enemy *enemy;

    switch (i) {
        case 1:
            enemy = new Enemy("../Assets/spaceship1.png", 300, 50, 1, 0, 200, renderer);
            break;
        case 2:
            enemy = new Enemy("../Assets/spaceship1.png", 300, 50, -1, 1, 200, renderer);
            break;
        case 3:
            enemy = new Enemy("../Assets/spaceship1.png", 300, 50, 2, 1, 300, renderer);
            break;
        case 4:
            enemy = new Enemy("../Assets/spaceship1.png", 300, 150, -1, 0, 200, renderer);
            break;
    }
    enemy->getDirection();
    enemies.emplace_back(enemy);
}



