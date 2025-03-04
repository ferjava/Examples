#ifndef __aLOGO__HPP
#define __aLOGO__HPP
#include "./base/Actor.hpp"


/**
 * Esta actor solo contine la imagen logo.png
*/

class aLogo : public Fj::Actor
{
public:
    aLogo();
    void Init() final;
    void Update(float dt) final;
    void Draw(ALLEGRO_BITMAP * bitmap_padre)final;
    ~aLogo();
};


#endif //__aLOGO__HPP

