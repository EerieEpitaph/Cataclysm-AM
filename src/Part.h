#ifndef PART_H_INCLUDED
#define PART_H_INCLUDED

#include <vector>

class Part
{
    private:
        uint32_t hp;
        uint8_t bashRes;
        uint8_t cutRes;
        uint8_t pierceRes;
        uint8_t acidRes;
        uint8_t enviroRes;
        uint8_t electRes;
        uint8_t fireRes;
        uint8_t freezRes;

        uint32_t UID;
        std::vector<uint16_t> flags;

    public:
        inline uint32_t getHp() {return hp;}
        inline uint8_t getBashRes() {return bashRes;}
        inline uint8_t getCutRes() {return cutRes;}
        inline uint8_t getPierceRes() {return pierceRes;}
        inline uint8_t getAcidRes() {return acidRes;}
        inline uint8_t getEnviroRes() {return enviroRes;}
        inline uint8_t getElectRes() {return electRes;}
        inline uint8_t getFireRes() {return fireRes;}
        inline uint8_t getFreezRes() {return freezRes;}

        inline uint32_t getUID() {return UID};
        inline std::vector<uint16_t> getFlags() {return flags;}
};

#endif // BODYPARTS_H_INCLUDED
