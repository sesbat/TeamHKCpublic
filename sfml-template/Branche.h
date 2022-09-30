#pragma once
#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include <random>

enum class Sides
{
    Left,
    Right,
    None,
};

class Branche : public Graphics
{
private:
    Graphics* tree=nullptr;
    Sides side;
    float crashX;

    static random_device rd;
    static mt19937 gen;

    int curBranch;

public:
    Branche(string tex, Graphics* tree);
    virtual void Init() override;
    void SetSide(Sides side);
    void UpdateBranches(vector<Branche*>& branches, int& current, vector<Vector2f>& posArr); // 나뭇가지 좌, 우 랜덤 생성, 순환
    Sides GetSide() const;
    int RandomRange(int min, int max);
    float RandomRange(float min, float max);
    void BrancheOffset(vector<Branche*> branches); // 나뭇가지 Y위치 지정(내려오게)
};