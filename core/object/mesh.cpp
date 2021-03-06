#include "mesh.h"

Mesh::Mesh()
{

}

bool Mesh::isContain(double x, double y)
{


}

void Mesh::rotate(double xAngle, double yAngle, double zAngle)
{
//    m_buffer.clear();
//    m_buffer.insert(m_buffer.begin(), m_data.begin(), m_data.end());
    for(size_t i = 0; i < m_data.size(); ++i){
        m_data[i].rotate(xAngle, yAngle, zAngle);
    }
}

#include<QDebug>
void Mesh::project(const Vec3 &eye, double d)
{
    m_buffer.clear();
    //遍历三角形  投影三角形到平面
    for(size_t i = 0; i < m_data.size(); ++i){
        m_buffer.push_back(m_data[i].projectTo2D(eye,d));
    }
}

Color Mesh::sample(double x, double y)
{
    //背景色
    Color c(64,64,64);

    //目前离摄像机最近的面：无穷远
    double index = 10e9;
    //遍历三角形
    for(size_t i = 0; i < m_buffer.size(); ++i){
        //如果这个面包含了这个像素
        if(m_buffer[i].isContain(x,y)){
            //找出在此像素上，离摄像机最近的面
            if(m_buffer[i].z_index < index){
                c = m_buffer[i].color_fill;
                index = m_buffer[i].z_index;

            }
        }
    }
    return c;

    /*
    //遍历三角形，记下哪些三角形包含这个像素点
    m_buffer.clear();
    for(int i = 0; i < m_data.size(); ++i){
        Triangle tr = m_data[i].projectTo2D(eye,d);
        if(tr.isContain(x,y)){
            m_buffer.push_back(tr);
        }
    }
    //计算这些三角形中谁离摄像机最近
    for(int i = 0; i < m_buffer.size(); ++i){

    }
    //返回这个三角形的颜色值
    */

}

void Mesh::makeCube()
{
    Vec3 vt1(-30, -30, 30);
    Vec3 vt2(30, -30, 30);
    Vec3 vt3(30, -30, -30);
    Vec3 vt4(-30, -30, -30);
    Vec3 vt5(-30, 30, 30);
    Vec3 vt6(30, 30, 30);
    Vec3 vt7(30, 30, -30);
    Vec3 vt8(-30, 30, -30);

    Triangle triangle1(vt1,vt2,vt3,Color(255,125,0));
    Triangle triangle2(vt1,vt3,vt4,Color(125,125,0));

    Triangle triangle3(vt2,vt3,vt6,Color(0,255,0));
    Triangle triangle4(vt3,vt6,vt7,Color(255,0,255));

    Triangle triangle5(vt1,vt2,vt5,Color(0,0,255));
    Triangle triangle6(vt2,vt5,vt6,Color(255,0,0));

    Triangle triangle7(vt5,vt6,vt7,Color(255,125,255));
    Triangle triangle8(vt5,vt7,vt8,Color(125,0,0));

    Triangle triangle9(vt3,vt4,vt8,Color(255,125,0));
    Triangle triangle10(vt3,vt7,vt8,Color(125,0,255));

    Triangle triangle11(vt1,vt4,vt8,Color(255,255,125));
    Triangle triangle12(vt1,vt5,vt8,Color(125,125,255));

    m_data.push_back(triangle12);
    m_data.push_back(triangle3);
    m_data.push_back(triangle4);
    m_data.push_back(triangle5);
    m_data.push_back(triangle7);
    m_data.push_back(triangle8);
    m_data.push_back(triangle9);
    m_data.push_back(triangle1);
    m_data.push_back(triangle2);
    m_data.push_back(triangle6);
    m_data.push_back(triangle10);
    m_data.push_back(triangle11);
}

void Mesh::clear()
{
    m_data.clear();
}

void Mesh::reset()
{

}
