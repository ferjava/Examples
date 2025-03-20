#pragma once
#ifndef __ACTORMANAGER_HPP
#define __ACTORMANAGER_HPP
#include <allegro5/allegro5.h>
#include "base/Actor.hpp"
#include <list>
namespace Fj
{
    class ActorManager 
    {
    public :
        ActorManager();
        //ActorManager(ALLEGRO_BITMAP* bitmap_padre);
        ~ActorManager();
        void addActor(Fj::Actor* newactor);
        void delActor(Fj::Actor* delactor);
        void initActors();
        void updateActors();
        void drawActors(ALLEGRO_BITMAP *bitmap_padre);
        Fj::Actor* getCurrentActor();
        Fj::Actor* getNextActor();

    private:
        std::list<Fj::Actor*> _lista_actores;
        std::list<Fj::Actor*>::iterator _lista_iter;


    };
}

#endif //__ACTORMANAGER_HPP
