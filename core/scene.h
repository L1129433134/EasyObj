#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "object/object3d.h"
#include "object/mesh.h"


/**
 * @brief 场景类，包含各种几何数据
 */
class Scene
{
public:
    Scene();

    std::vector<Object3D*>  m_objs;/**< 场景包含的物体*/

    Mesh m_mesh;

    void update(double x, double y, double x0, double y0, double whl_delta);


    double m_projD;//投影面 坐标
};

#endif // SCENE_H
