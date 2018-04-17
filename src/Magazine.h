#ifndef MAGAZINE_H_INCLUDED
#define MAGAZINE_H_INCLUDED

class Magazine
{
    private:
        uint32_t charges;
        std::vector<uint16_t> flags;

    public:
        inline uint32_t getCharges(){return charges;}
        inline std::vector<uint16_t> getFlags(){return flags;}
};


#endif // MAGAZINE_H_INCLUDED
