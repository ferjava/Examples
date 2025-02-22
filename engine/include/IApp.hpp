#ifndef __IAPP_HPP__
#define __IAPP_HPP__
#include <string>

namespace engine
{
    struct Version
    {
        int MAJOR =0;
        int MINOR =0;
    };
    class IApp
    {
    public:
        virtual ~IApp() = default ;
        virtual void Init() = 0;
        virtual void Update(float dt )= 0;
        virtual void Render() = 0;
    protected:
        //Get Set del nombre de la Aplicacion
        void setApp_Name(std::string appname_value){ _app_name = appname_value;}
        std::string getApp_Name(){ return _app_name;}
        //Get Set de version
        void setVersion(int vMajor , int vMinor) {_version.MAJOR =               vMajor;_version.MINOR=vMinor;  }
        Version getVersion(){ return _version;}

    private:
        std::string _app_name;
        Version _version ;
    };
}


#endif
