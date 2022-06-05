
#include"Tank.h"
void Tank::shot()
{
    //子弹已经射出就 return
    if (bullet.getstate())
        return;
    bullet.setstate(true);
    bullet.Faceto(face);
    bullet.bullrect.setRect(rect.x() , rect.y(), 50, 50);
}

void Tank::move()
{
    int x = rect.x(), y = rect.y();
    if (face == Face::up0)
    {
        y -= speed;
    }
    else if (face == Face::down0)
    {
        y += speed;
    }
    else if (face == Face::left0)
    {
        x -= speed;
    }
    else if (face == Face::right0)
    {
        x += speed;
    }
    if (ifreach(x, y, this->face))
    {
        rect.moveTo(x, y);
    }
}

void Tank::Faceto(Face dir)
{
    this->face = dir;
}

void Tank::paintTank(QPainter& paint)
{
   
    if (face == Face::up0)
    {
        paint.drawPixmap(rect.x(), rect.y(), 50, 50, upimg);
    }
    else if (face == Face::down0)
    {

        paint.drawPixmap(rect.x(), rect.y(), 50, 50, downimg);
    }
    else if (face == Face::left0)
    {
        paint.drawPixmap(rect.x(), rect.y(), 50, 50, leftimg);
    }
    else if (face == Face::right0)
    {
        paint.drawPixmap(rect.x(), rect.y(), 50, 50, rightimg);
    }

    
}

bool Tank::ifreach(int x, int y, Face dir)
{
    x /= 50;
    y /= 50;
   
    //判断是否越界
    if (x < 0 || x>11 || y < 0 || y>11)
    {
        return false;
    }
    //    判断是否有障碍物
    else if (map[y][x] == '3'||map[y][x]=='2'||map[y][x]=='4')
    {
        return false;
    }
    else
    {
        return true;
    }
}

