#include "ResourceMgr.h"

//vector<Graphics*> resourceg

ResourceMgr::ResourceMgr()
{

}

void ResourceMgr::PutResourceGraphic(Graphics* graphic)
{
	resourceGraphic.push_back(graphic);
}
