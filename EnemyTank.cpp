#include"EnemyTank.h"
EnemyTank::EnemyTank()
{
    settankdir();
    ismove = false;
    face = down0;
    speed = 50;
    rect.setRect(0 * 50, 0 * 50, 50, 50);

}
void EnemyTank::settankdir()
{
    upimg.load((rootdir + "ey-u.gif").c_str());
    upimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    leftimg.load((rootdir + "ey-l.gif").c_str());
    leftimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    rightimg.load((rootdir + "ey-r.gif").c_str());
    rightimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    downimg.load((rootdir + "ey-d.gif").c_str());
    downimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
}
void EnemyTank::Faceto(Face face)
{
    this->face = face;
    ismove = true;
}