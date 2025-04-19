#pragma once
#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "allegro5/allegro.h"
#include "engine.hpp"
namespace Fj
{
    class Game 
    {
    public:
      Game ();
      Game (unsigned int width , unsigned int height , int flags = ALLEGRO_FULLSCREEN_WINDOW);
      virtual ~Game();
      virtual bool Init ();
      virtual void Update (float dt); 
      unsigned int getWidth () {return _area_visible.Width;};
      unsigned int getHeigh () {return _area_visible.Height;};
      void setSizeScreen(unsigned int width , unsigned int height);
      /**
       * @brief Area visible del juego
       * @return Bitmap con la anchura y altura del dispositivo donde
       * se mostrara el juego
       */
      ALLEGRO_BITMAP* getVisibleBitmap(){return _bitmap_visible;};
      /**
       * @brief Retorna el tiempo que redibuja el juego
       * @return ALLEGRO_TIMER*
       */
      ALLEGRO_TIMER* getFPS(){return _timer;};
      double getElasepTime(){return _elasep_time;};
      ALLEGRO_EVENT_QUEUE* getQueue(){return _queue;};
    protected:
      bool InitAllegro();
    private:
      Fj::Size _area_visible;
      int _flags = ALLEGRO_FULLSCREEN_WINDOW ;
      ALLEGRO_DISPLAY* _disp = nullptr;
      ALLEGRO_TIMER* _timer = nullptr;
      ALLEGRO_BITMAP* _bitmap_visible = nullptr;
      ALLEGRO_EVENT_QUEUE* _queue =nullptr;
      double _elasep_time;
      

    };
}

#endif // __GAME__HPP__
