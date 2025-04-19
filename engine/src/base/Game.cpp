/**
 * @brief la clase Game es la encargada de incializar allegro asi como los aspectos gragicos ( pantalla , tiempo )
 * @version 0.0.
 * */
#include "base/Game.hpp"
#include "allegro5/allegro.h"
#include <stdexcept>
using namespace Fj ;

bool Game::InitAllegro()
{
    al_init();
    if(!al_is_system_installed())
    {
        return false ;
    }
    return true;
}
bool Game::Init()
{
   if(!InitAllegro())
   {
     throw std::runtime_error("Error al inicializar allegro");
     return false ;
    }
    //fps
    _timer =al_create_timer(1.0 / 30.0);
    //flags de allagro para la ventana por defecto (ALLEGRO_FULLSCREEN_WINDOW)
    al_set_new_display_flags(_flags);
    //Itentamos Poner la pantalla a resolucion
    _disp = al_create_display(_area_visible.Width ,_area_visible.Height);
    if(_disp==nullptr)
    {
        throw std::runtime_error("No se pude inicializar el modo grafico");
        return false ;
    }
    _queue = al_create_event_queue();
    //Registramos los eventos que utilizamos
    al_register_event_source(_queue, al_get_display_event_source(_disp));
    al_register_event_source(_queue, al_get_timer_event_source(_timer));
     //Mapa que se muestra en la pantalla
    _bitmap_visible=al_create_bitmap(al_get_display_width(_disp),al_get_display_height(_disp));
    //Inicia a correr
    al_start_timer(_timer);
    _elasep_time = al_get_time();//Numero de sgundos desde que se inicia allegro
    return true;
}
void Game::Update(float dt)
{
  ALLEGRO_EVENT event ;
  bool run = true ;
  while (run == true)
    {
      al_wait_for_event(_queue , &event);
      if(event.type == ALLEGRO_EVENT_TIMER)
      {
        //TODO:redibuja
      }
      else if (event.type == ALLEGRO_EVENT_KEY_DOWN ||
      event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      {
        run = false;
        break;
      }
    }
}
Game::Game()
{
    /// Ponemos 800 x600 por defecto
    _area_visible.Width = 800;
    _area_visible.Height = 600;


}
Game::Game(unsigned int width , unsigned int height ,
int flags)
{
    _area_visible.Width = width;
    _area_visible.Height = height;
    _flags = flags;
}
Game::~Game()
{
    al_destroy_display(_disp);
    al_destroy_timer(_timer);
    al_destroy_event_queue(_queue);
}
