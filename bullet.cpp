#include"bullet.h"
#include<Qdebug>
Bullet::Bullet()
{
    speed = 50 * 2;
    flying = false;
    bullrect.setRect(-1, -1, 0, 0);
    setbullet();
}
void Bullet::setbullet()
{
    leftimg.load((rootdir + "bullet-0.gif").c_str());
    leftimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    upimg.load((rootdir + "bullet-1.gif").c_str());
    upimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    rightimg.load((rootdir + "bullet-2.gif").c_str());
    rightimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    downimg.load((rootdir + "bullet-3.gif").c_str());
    downimg.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
}
void Bullet::setstate(bool a)
{
    flying = a;
    if (flying == false)
    {
        bullrect.setRect(-1, -1, 0, 0);
    }
}
bool Bullet::getstate()
{
    return flying;
}
void Bullet::move()
{
    if (getstate() == false)
        return;
    int x = bullrect.x();
    int y = bullrect.y();
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
    //需要一个子弹跟墙的碰撞检测！！！！！
    //更新坐标
    //qDebug() << "x=" << x << " ";
    if(ifreach(x, y, bullrect.x(), bullrect.y()))
    {
        bullrect.moveTo(x, y);
    }
    else
    {
        setstate(false);
    }
}
void Bullet::Faceto(Face face)
{
    this->face = face;
}

void Bullet::paintbullet(QPainter& paint)
{
    if (!getstate())//未发射 return
    {
        return;
    }
    if (face == Face::up0)
    {
        paint.drawPixmap(bullrect.x() + 20, bullrect.y(), 10,10,upimg);
    }
    else if (face == Face::down0)
    {
        paint.drawPixmap(bullrect.x() + 20, bullrect.y(), 10,10,downimg);
    }
    else if (face == Face::left0)
    {
        paint.drawPixmap(bullrect.x(), bullrect.y()+20,10,10, leftimg);
    }
    else if (face == Face::right0)
    {
        paint.drawPixmap(bullrect.x(), bullrect.y()+20,10,10, rightimg);
    }
}

bool Bullet::ifreach(int x, int y, int x0,int y0)
{
    //转换map坐标
    x /= 50;
    y /= 50;
    x0 /= 50;
    y0 /= 50;
    

    if (y == y0)
    {
        int dif = (x - x0) / abs(x - x0);
        //qDebug() <<"dif=" << dif << " ";

        for (int i = x0 +dif; i != x + dif; i += dif)
        {
            //qDebug() << "i=" << i << " map[y][i]=" << map[y][i] << " map[y][3]=" << map[y][3];
            if (i < 0 || i>11 || y < 0 || y>11)
            {
                return false;
            }
            else if (map[y][i] == '2')
            {
                map[y][i] = '1';
                return false;
            }
            //打到硬墙上
            else if (map[y][i] == '4')return false;
            
        }
    }
    else if (x == x0)
    {
        int dif = (y - y0) / 2;
        for (int i = y0 +dif; i != y + dif; i += dif)
        {
            if (x < 0 || x>11 || i < 0 || i>11)
            {
                return false;
            }
            else if (map[i][x] == '2')
            {
                map[i][x] = '1';
                return false;
            }
            //打到硬墙上
            else if (map[i][x] == '4')return false;
        }
    }
        
    return true;
}
