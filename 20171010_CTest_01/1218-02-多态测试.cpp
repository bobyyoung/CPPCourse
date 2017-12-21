#include "iostream"
using namespace std;

class HeroFighter
{
public:
	virtual int ackPower()
	{
		return 10;
	}
};

class AdvHeroFighter : public HeroFighter
{
public:
	virtual int ackPower()
	{
		return HeroFighter::ackPower() * 2;
	}
};

class enemyFighter
{
public:
	int destoryPower()
	{
		return 15;
	}
};

//如果把这个结构放在动态库里面
//写了一个框架，可以调用
//我的第3代战机代码出现的时间晚于框架出现的时间。。。。
//框架 有使用后来人 写的代码的能力。。。
//面向对象3大概念
/*
封装
突破了C语言函数的概念。。

继承
代码复用 。。。。我复用原来写好的代码。。。

多态
多态可以使用未来。。。。。80年代写了一个框架。。。。。。90人写的代码
多态是我们软件行业追寻的一个目标。。。
////
*/
//
void objPK(HeroFighter *hf, enemyFighter *enemyF)
{
	if (hf->ackPower() > enemyF->destoryPower())
	{
		printf("英雄打败敌人。。。胜利\n");
	}
	else
	{
		printf("英雄。。。牺牲\n");
	}
}

void main()
{
	HeroFighter hf;
	enemyFighter ef;

	objPK(&hf, &ef);

	AdvHeroFighter advhf;

	objPK(&advhf, &ef);
	system("pause");
}
