#pragma once
#include "player.h"

class Archer : public Player {
public:
    Archer(string nickanme);
    void attack() override;
};