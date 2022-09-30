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
    Graphics* tree;
    Sides side;
    float crashX;

    static random_device rd;
    static mt19937 gen;

    int curBranch;

public:
    Branche(string tex, Graphics* tree = nullptr);
    virtual void Init() override;
    void SetSide(Sides side);
    void UpdateBranches(vector<Branche*>& branches, int& current, vector<Vector2f>& posArr); // �������� ��, �� ���� ����, ��ȯ
    Sides GetSide() const;
    static int RandomRange(int min, int max);
    static float RandomRange(float min, float max);
    void BrancheOffset(vector<Branche*> branches); // �������� Y��ġ ����(��������)
};