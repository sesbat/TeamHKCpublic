#include "Branche.h"

random_device Branche::rd;
mt19937 Branche::gen(Branche::rd());

Branche::Branche(string tex, Graphics* tree) 
    : Graphics(tex), tree(tree), curBranch(-1)
{
}

void Branche::Init()
{
    Vector2f treeSize = tree->GetSize();
    Vector2f branchSize = GetSize();
    sprite.setOrigin(-treeSize.x * 0.5f, branchSize.y * 0.5f);
    SetPos(tree->GetPos());
}

void Branche::SetSide(Sides side)
{
    switch (side)
    {
    case Sides::Left:
        sprite.setScale(-1, 1);
        break;
    case Sides::Right:
        sprite.setScale(1, 1);
        break;
    }
    this->side = side;
}

void Branche::UpdateBranches(vector<Branche*>& branches, int& current, vector<Vector2f>& posArr)
{
    current = (current + 1) % branches.size();

    for (int i = 0; i < branches.size(); ++i)
    {
        int index = (current + i) % branches.size();
        branches[index]->SetPos(posArr[i]);
        if (i == branches.size() - 1)
        {
            branches[index]->SetSide((Sides)RandomRange(0, 2));
        }
    }
}

Sides Branche::GetSide() const
{
	return side;
}

int Branche::RandomRange(int min, int max)
{
    return (gen() % (max - min)) + min;
}

void Branche::BrancheOffset(vector<Branche*> branches)
{
    vector<Vector2f> branchPosArr(branches.size());
    float x = branches[0]->GetPos().x;
    float y = 800;
    float offset = branches[0]->GetSize().y;
    offset += 100;
    for (int i = 0; i < branches.size(); ++i)
    {
        branchPosArr[i] = Vector2f(x, y);
        y -= offset;
    }
    UpdateBranches(branches, curBranch, branchPosArr);
}

float Branche::RandomRange(float min, float max)
{
    uniform_real_distribution<> dist(min, max);
    return dist(gen);
}