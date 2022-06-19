#ifndef I_OBSERVER
#define I_OBSERVER
    #include <string>
    #include <map>
    #include <set>
    #include "../../common/clases/header/Calificacion.hpp"
    
    class Observer{
        public:
            virtual ~Observer();
            virtual void agregarNotificacion(Calificacion* c) = 0;
        
    };
#endif