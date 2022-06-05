#include"Mytank.h"
Mytank::Mytank()
{
    settankdir();
    ismove = false;
    face = up0;
    speed = 50;
}
void Mytank::settankdir()
{
    upimg.load((rootdir + "my-u.gif").c_str());
    upimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    leftimg.load((rootdir + "my-l.gif").c_str());
    leftimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    rightimg.load((rootdir + "my-r.gif").c_str());
    rightimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    downimg.load((rootdir + "my-d.gif").c_str());
    downimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
}
void Mytank::Faceto(Face face)
{
    this->face = face;
    ismove = true;
}