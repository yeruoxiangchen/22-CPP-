#include "WarofTank.h"
#include<QDebug>

Widget::Widget(QWidget* parent) :QWidget(parent)
{
	//��
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(WT, HT);//���ô��ڴ�С������12*12---��ÿС��ռ50*50///////��ȡ���꼴������%50��С����*50����С����*50+49��
	setWindowTitle("̹�˴�ս");
	setStyleSheet("background-color:black;");//���ñ�����ɫ
	//��
    enemynum = 4;
    life = 1;
    build();
    timebuild();

    /*std::vector<int>Path = path(enemies[0].rect.x(), enemies[0].rect.y(), player.rect.x(), player.rect.y());
    for (int i = 0; i < Path.size(); i++)qDebug() << Path[i] / 12 << " " << Path[i] % 12 << " ";*/
}

void Widget::build()
{
    ini_map();
    wall.load((rootdir + "wall.gif").c_str());
    wall.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    river.load((rootdir + "river.gif").c_str());
    river.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    hardwall.load((rootdir + "hardwall.gif").c_str());
    hardwall.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    campRect.setRect(5 * 50, 11 * 50, 50, 50);
    camp.load((rootdir + "camp0.gif").c_str());
    camp.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
    buildMyTank();
    buildEnemyTank();
    
}
void Widget::timebuild()
{
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    timer3 = new QTimer(this);
    timer4 = new QTimer(this);
    timer5 = new QTimer(this);
    timer6 = new QTimer(this);
    timer1->start(120);
    timer2->start(600);
    timer3->start(600);
    timer4->start(500);
    timer5->start(120);
    timer6->start(30);
    connect(timer1, &QTimer::timeout, this, &Widget::operation);
    connect(timer2, &QTimer::timeout, this, &Widget::killer);
    connect(timer3, &QTimer::timeout, this, &Widget::assault);
    connect(timer4, &QTimer::timeout, this, &Widget::Enemyshot);
    connect(timer5, &QTimer::timeout, this, &Widget::Bulletmove);//��Ҳ������ӵ��ƶ����ӵ��Զ�����
    connect(timer6, &QTimer::timeout, this, &Widget::repaint);
    
}
void Widget:: paintEvent(QPaintEvent*)
{
    painter.begin(this);
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (map[i][j] == '2')
            {
                //0�յ�1·2ǽ3ˮ5���6�з�������
                painter.drawPixmap(j * 50/*�궨��20��������*/, i * 50, 50, 50, wall);
            }

            else if (map[i][j] == '3')
            {
                painter.drawPixmap(j * 50, i * 50,50,50 ,river);
            }
            else if (map[i][j] == '4')
            {
                painter.drawPixmap(j * 50, i * 50, 50, 50, hardwall);

            }
        }
    }
    player.paintTank(painter);
    player.bullet.paintbullet(painter);
    //��Ҽ����ӵ�
    for (auto& enemy : enemies)
    { 
        enemy.bullet.paintbullet(painter);
        enemy.paintTank(painter);
    }
    //���˼����ӵ�
    painter.drawPixmap(campRect.x(), campRect.y(), 50, 50,camp);
    //����

    painter.end();
}



void Widget:: buildMyTank()
{
    player.bullet.setstate(false);
    player.Faceto(Face::up0);
    player.ismove = false;
    player.rect.setRect(5 * 50, 9 * 50, 50, 50);
}

void Widget::buildEnemyTank()
{
    EnemyTank enemy1, enemy2, enemy3, enemy4;
    enemy1.rect.setRect(1 * 50, 1 * 50, 50, 50);
    enemy2.rect.setRect(5 * 50, 1 * 50, 50, 50);
    enemy3.rect.setRect(10 * 50, 1 * 50, 50, 50);
    enemy4.rect.setRect(5 * 50, 5 * 50, 50, 50);
    enemies.push_back(enemy1);
    enemies.push_back(enemy2);
    enemies.push_back(enemy3);
    enemies.push_back(enemy4);
    
}

void Widget::keyPressEvent(QKeyEvent* event)
{

    if (event->key() == Qt::Key::Key_W)
    {
        player.Faceto(Face::up0);
    }
    else if(event->key() == Qt::Key::Key_A)
    {
        player.Faceto(Face::left0);
    }
    else if (event->key() == Qt::Key::Key_S)
    {
        player.Faceto(Face::down0);
    }
    else if(event->key() == Qt::Key::Key_D)
    {
        player.Faceto(Face::right0);
    }
    else if (event->key() == Qt::Key::Key_J)
    {
        if (!player.bullet.getstate())
        {
            player.shot();
        }
    }
}

void Widget::keyReleaseEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key::Key_J)
    {
        return;
    }
    else
    {
        player.ismove = false;
    }
}
void Widget::ifcollision()
{
    //����ӵ��͵з��ӵ�
    for (auto& enemy : enemies)
    {
        if (player.bullet.bullrect.intersects(enemy.bullet.bullrect))
        {
            player.bullet.setstate(false);
            enemy.bullet.setstate(false);
            break;
        }
        else if (campRect.intersects(enemy.bullet.bullrect) || campRect.intersects(player.bullet.bullrect))
        {
           
            camp.load((rootdir + "camp1.gif").c_str());
            camp.scaled(50, 50, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);
            update();
            Gameover();
        }
    }
    //�ӵ���ǽ
    
    //����ӵ��͵з�̹��
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++)
    {
        if (player.bullet.bullrect.intersects(enemy->rect))
        {
            enemies.erase(enemy);
            enemynum--;
            if (enemynum == 0)
            {
                return;
            }
            player.bullet.setstate(false);
            break;
        }
    }
    //��Һ͵з��ӵ���ײ���
    for (auto& enemy : enemies)
    {
        if (player.rect.intersects(enemy.bullet.bullrect))
        {
            enemy.bullet.setstate(false);
         
             Gameover();
          
            break;
        }
    }
}


void Widget::Gameover()
{
    timer1->stop();
    timer2->stop();
    timer3->stop();
    timer4->stop();
    timer5->stop();
    QMessageBox MBox;
    MBox.setWindowTitle("Game Over");
    MBox.setText("Mission Lost");
    QPushButton* agreeBut = MBox.addButton("�˳�", QMessageBox::AcceptRole);
    MBox.exec();
    this->close();
    exit(0);
}

void Widget::operation()
{
    
    if (player.ismove)
    {
        player.move();
      
    }
}
void Widget:: killer()//�ĸ�̹���еĵ�һ��׷�����̹��
{
    EnemyTank&killer = enemies[0];
    std::vector<int>Path = path(killer.rect.x() / 50, killer.rect.y() / 50, player.rect.x() / 50, player.rect.y() / 50);
    if (Path.size() > 0)
    {
        int x = Path[0] % 12; int y = Path[0] / 12;
        if (x == killer.rect.x() / 50)
        {
            if (y > killer.rect.y() / 50)killer.Faceto(Face::down0);
            else killer.Faceto(Face::up0);
        }
        else
        {
            if (x > killer.rect.x() / 50)killer.Faceto(Face::right0);
            else killer.Faceto(Face::left0);
        }
        killer.move();
    }
    else//����������˻�û���������������Ǿ����������һ����
    {
        static int d;
        srand((unsigned)time(NULL));
        //��������ƶ�
        d = rand() % 4;
        if (d == 0)
        {
            killer.Faceto(Face::left0);
        }
        else if (d == 1)
        {
            killer.Faceto(Face::up0);
        }
        else if (d == 2)
        {
            killer.Faceto(Face::right0);
        }
        else if (d == 3)
        {
            killer.Faceto(Face::down0);
        }
        killer.move();

       
    }
}

void Widget::assault()
{
    for (int i = 1;i<enemies.size();i++)//���ֻʣһ���Է�̹�ˣ��Է�̹����ȥ���ҵ�
    {
        std::vector<int>Path = path(enemies[i].rect.x() / 50, enemies[i].rect.y() / 50, campRect.x() / 50, campRect.y() / 50);

        if (Path.size() > 0)
        {
            //qDebug() << Path[i] / 12 << " " << Path[i] % 12;
            int x = Path[0] % 12; int y = Path[0] / 12;
            if (x == enemies[i].rect.x() / 50)
            {
                if (y > enemies[i].rect.y() / 50)enemies[i].Faceto(Face::down0);
                else enemies[i].Faceto(Face::up0);
            }
            else
            {
                if (x > enemies[i].rect.x() / 50)enemies[i].Faceto(Face::right0);
                else enemies[i].Faceto(Face::left0);
            }
            enemies[i].move();
        }
        else//����������˻�û���䣬�������Ǿ����������һ����
        {
            static int d;
            srand((unsigned)time(NULL));
            //��������ƶ�
            d = rand() % 4;
            if (d == 0)
            {
                enemies[i].Faceto(Face::left0);
            }
            else if (d == 1)
            {
                enemies[i].Faceto(Face::up0);
            }
            else if (d == 2)
            {
                enemies[i].Faceto(Face::right0);
            }
            else if (d == 3)
            {
                enemies[i].Faceto(Face::down0);
            }
            enemies[i].move();


        }
    }
}

void Widget::Enemyshot()
{
    for (auto& enemy : enemies)
    {
        if (!enemy.bullet.getstate())
        {
            enemy.shot();
        }
    }
}

void Widget::Bulletmove()
{
    //����ӵ��ƶ�
    if (player.bullet.getstate())
    {
        player.bullet.move();
    }
    //�����ӵ��ƶ�
    for (auto& enemy : enemies)
    {
        if (enemy.bullet.getstate())
        {
            enemy.bullet.move();
        }
    }
}

void Widget::repaint()
{
    ifcollision();
    if (enemynum == 0)
    {
        timer1->stop();
        timer2->stop();
        timer3->stop();
        timer4->stop();
        timer5->stop();
        QMessageBox MBox;
        MBox.setWindowTitle("YOU WIN!!");
        MBox.setText("Mission finished");
        QPushButton* agreeBut = MBox.addButton("�˳�", QMessageBox::AcceptRole);
        MBox.exec();
        this->close();
        exit(0);
    }
    update();
 
}

Widget::~Widget()
{
    delete timer1;
    delete timer2;
    delete timer3;
    delete timer4;
    delete timer5;
    delete timer6;
}