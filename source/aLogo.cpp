#include "aLogo.hpp"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <stdexcept>

void aLogo::Init()
{
         al_init_image_addon();
       _image=al_load_bitmap("Content/logo.png");
        if(!_image)
        {
          throw std::runtime_error("Error al cargar la imagen");
        }

        _size.Height = al_get_bitmap_height(_image);
        _size.Width   = al_get_bitmap_width(_image);
}

void aLogo::Draw(ALLEGRO_BITMAP* bitmap_padre)
{
     Fj::Size size_padre ;
     size_padre.Height = al_get_bitmap_height(bitmap_padre);
     size_padre.Width = al_get_bitmap_width(bitmap_padre);
     _pos.x = al_get_bitmap_width(bitmap_padre)*0.5 - _size.Width*0.5;
     _pos.y = al_get_bitmap_height(bitmap_padre)*0.5 - _size.Height*0.5;
    al_draw_bitmap(_image,_pos.x,_pos.y,0);

}
void aLogo::Update(float dt)
{

}

aLogo::~aLogo()
{
 // al_destroy_bitmap(_image);
  _image=nullptr;
}
aLogo::aLogo():Fj::Actor()
{
}

