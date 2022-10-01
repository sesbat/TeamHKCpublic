#pragma once
#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include <random>
#include "Player.h"

class Branche : public Graphics
{
private:
    vector<Vector2f> branchPosArr;
    Graphics* tree=nullptr;
    Sides side;
    float crashX;

    static random_device rd;
    static mt19937 gen;

    int curBranch;

public:
    Branche(string tex);
    virtual void Init() override;
    void SetSide(Sides side);
    void UpdateBranches(vector<Branche*>& branches, int& current, vector<Vector2f>& posArr); // �������� ��, �� ���� ����, ��ȯ
    Sides GetSide() const;
    static int RandomRange(int min, int max);
    static float RandomRange(float min, float max);
    void BrancheOffset(vector<Branche*> branches); // �������� Y��ġ ����(��������)
    vector<Vector2f> GetBranchePos() const;
};