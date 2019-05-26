#pragma once
#include <vector>
#include <functional>
#include <algorithm>

class SceneObject;

typedef std::vector<std::reference_wrapper<SceneObject>> SceneObjectList;
typedef std::reference_wrapper<SceneObject> SceneObjectList_item;
