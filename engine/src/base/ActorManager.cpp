/**
 * @file ActorManager.cpp
 * @author your name (you@domain.com)
 * @brief  Implementacion de las lista de Actores
 * @version 0.1
 * @date 2025-03-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "base/ActorManager.hpp"
#include  <algorithm>
#include <stdexcept>
/**
 * @brief Añade un Actor a la lista
 * 
 */
 void Fj::ActorManager::addActor(Fj::Actor *new_actor)
{
    _lista_actores.push_back(new_actor);

}
/**
 * @brief Elimina el Actor de la lista
 */
void Fj::ActorManager::delActor(Fj::Actor* delactor)
{
    _lista_iter = std::find(_lista_actores.begin(),_lista_actores.end(),delactor);
    if(_lista_iter !=  _lista_actores.end())
    {
     _lista_actores.erase(_lista_iter);
    }

}
/**
 * @brief Inicializa todos los actores (actor->init)
 */
void Fj::ActorManager::initActors()
{
    for (Fj::Actor* actor : _lista_actores)
    {
        actor->Init();
    }
}
/**
 * @brief :Actualiza los actores de la lista (actor->update)
 */
void Fj::ActorManager::updateActors()
{
    for(Fj::Actor* actor :_lista_actores)
    {
        actor->Update(0);
    }
}
/**
 * @brief: Dibuja todos los actores en bitmap _padre
 * !!Si el  bitmap es nullptr lanza una excepcion
 * std::realtime_error
 */
void Fj::ActorManager::drawActors(ALLEGRO_BITMAP* bitmap_padre)
{
    if(bitmap_padre == nullptr)
    {
        throw std::runtime_error("Error has pasado un nullptr para dibujar los actores ");
    }
    for(Fj::Actor* actor : _lista_actores)
    {
        actor->Draw(bitmap_padre);
    }

}
/**
 * @brief : retorna un puntero al actor que acyalmente apunta la lista
 * @return :nullptr Se es el ultimo
 * @return : Fj::Actor*
 */
Fj::Actor * Fj::ActorManager::getCurrentActor()
{
    if(_lista_iter ==_lista_actores.end())
    {
        return nullptr;
    }
    else
    {
        return (*_lista_iter);
    }

}
/**
 * @brief : Retorna  el actor siguiente al que apuntamos
 * de la lista
 * @return :nullptr si no hay mas actores en la lista
 * @return Fj::Actor*  si ha alguno en la lista
 */
Fj::Actor * Fj::ActorManager::getNextActor()
{


        if(_lista_iter == _lista_actores.end())
        {
           return nullptr;
        }


        _lista_iter++;
        return *_lista_iter;
}
Fj::ActorManager::ActorManager()
{
}
/**
 * @brief Eliminamos todos  los acotres
 */
Fj::ActorManager::~ActorManager()
{
   for(Fj::Actor* a : _lista_actores)
   {
        delete(a);

   }
}





