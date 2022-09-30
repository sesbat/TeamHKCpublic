#include "Scene.h"

Scene::Scene(list<Graphics> tempenv, list<MovingObj>movingObj, int sel)
{
    this->sel = sel;
    env = tempenv;
    this->movingObj = movingObj;
}

Scene::~Scene()
{
}

void Scene::Draw(RenderWindow& e)
{
    for (auto v : env)
        v.Draw(e);
    for (auto v : movingObj)
        v.Draw(e);
}

void Scene::Update(float dt)
{
    /// switch (sel) {
    //case 1:

    //    break;
    //case 2:
    //    sceneCollect[sel]->Draw(e);
    //    break;
    //case 3:
    //    sceneCollect[sel]->Draw(e);
    //    break;

    //case 4:
    //    sceneCollect[sel]->Draw(e);

    //    break;
    //case 5:
    //    sceneCollect[sel]->Draw(e);
    //    break;
    //} /
}