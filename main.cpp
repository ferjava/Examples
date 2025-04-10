#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "aLogo.hpp"
#include "engine.hpp"
int main()
{
    al_init();
    al_install_keyboard();

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    ALLEGRO_DISPLAY* disp = al_create_display(800, 600);
    ALLEGRO_FONT* font = al_create_builtin_font();
   
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool redraw = true;
    ALLEGRO_EVENT event;
    ALLEGRO_BITMAP *mybmp = al_create_bitmap(al_get_display_width(disp),al_get_display_height(disp));
    aLogo *mylogo = new aLogo();
    //mylogo->Init();
    auto *director = new Fj::ActorManager();
    director->addActor(mylogo);
    director->initActors();

    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            /*al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");*/
           // mylogo->Draw(mybmp);
            director->drawActors(mybmp);
            al_flip_display();


            redraw = false;
        }
    }

    //delete mylogo;
    delete director;
    al_destroy_bitmap(mybmp);
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}
