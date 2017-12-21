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

//���������ṹ���ڶ�̬������
//д��һ����ܣ����Ե���
//�ҵĵ�3��ս��������ֵ�ʱ�����ڿ�ܳ��ֵ�ʱ�䡣������
//��� ��ʹ�ú����� д�Ĵ��������������
//�������3�����
/*
��װ
ͻ����C���Ժ����ĸ����

�̳�
���븴�� ���������Ҹ���ԭ��д�õĴ��롣����

��̬
��̬����ʹ��δ������������80���д��һ����ܡ�����������90��д�Ĵ���
��̬�����������ҵ׷Ѱ��һ��Ŀ�ꡣ����
////
*/
//
void objPK(HeroFighter *hf, enemyFighter *enemyF)
{
	if (hf->ackPower() > enemyF->destoryPower())
	{
		printf("Ӣ�۴�ܵ��ˡ�����ʤ��\n");
	}
	else
	{
		printf("Ӣ�ۡ���������\n");
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
