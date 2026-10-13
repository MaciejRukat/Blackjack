#pragma once
#include <vector>
#include "hand.h"

class Player
{
    public:
        Player(){};
        
    private:
        std::vector<Hand> hands;
};