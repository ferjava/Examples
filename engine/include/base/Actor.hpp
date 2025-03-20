#pragma once
#ifndef __ACTOR__HPP
#define __ACTOR__HPP

#include "../utils/Vec2.h"
#include "allegro5/allegro.h"
/**
  * @brief Esta es la superclase para todos los actores que iteractuan en
  * una  Scene (escena del  juego )
  * **/
namespace Fj
{
    struct Size
    {
        unsigned int Width;
        unsigned int Height;
    };


 class Actor
 {
 public:
     Actor(){};
    virtual~Actor();
     virtual void  Init() = 0;
     virtual void  Update(float dt) = 0;
     virtual void  Draw(ALLEGRO_BITMAP* bitmap_padre)=0;
     float getPositionX() { return _pos.x;};
     float getPositionY() { return _pos.y;};
     void  setPosition(float newx , float newy){_pos.x=newx;_pos.y=newy;};
     void  setSize(float width , float height){_size.Width=width;_size.Height=height;};

     ALLEGRO_BITMAP* getBitmap(){return _image;};
 protected:
     Vec2 _pos ;
     Size _size;
     ALLEGRO_BITMAP *_image = nullptr;  //representacion grafica del actor
};
}

#endif //__ACTOR__HPP
