#include "base/Actor.hpp"
/*
Fj::Actor::Actor()
{
    _pos.x= 0;
    _pos.y= 0;


}*/

void Fj::Actor::Init()
{

}
void Fj::Actor::Update(float dt)
{
}
void Fj::Actor::Draw(ALLEGRO_BITMAP* bitmap_padre)
{
    al_draw_bitmap(_image ,_pos.x,_pos.y,0);
}

Fj::Actor::~Actor() noexcept
{
  //Destruimos el bitmap si este no es nullptr
  if(_image != nullptr)
   {
     al_destroy_bitmap(_image);
    }

    _image = nullptr;
}
