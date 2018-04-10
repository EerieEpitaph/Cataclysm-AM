#ifndef WEARABLE_H_INCLUDED
#define WEARABLE_H_INCLUDED

#include "Bodyparts.h"

class Wearable : public Container
{
    private:
        std::vector<uint32_t> bodypartUID;
        uint16_t coverage;

        uint8_t bashRes;
        uint8_t cutRes;
        uint8_t pierceRes;
        uint8_t acidRes;
        uint8_t enviroRes;
        uint8_t electRes;
        uint8_t fireRes;
        uint8_t freezRes;

    public:
        inline uint8_t getBashRes() {return bashRes;}
        inline uint8_t getCutRes() {return cutRes;}
        inline uint8_t getPierceRes() {return pierceRes;}
        inline uint8_t getAcidRes() {return acidRes;}
        inline uint8_t getEnviroRes() {return enviroRes;}
        inline uint8_t getElectRes() {return electRes;}
        inline uint8_t getFireRes() {return fireRes;}
        inline uint8_t getFreezRes() {return freezRes;}
};

#endif // WEARABLE_H_INCLUDED
