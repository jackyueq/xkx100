// flower.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;
mapping *flowers;
mapping flower;

#define flower_path "/clone/flower/"
void create()
{
	seteuid(getuid());
}
string query_save_file()
{
	string id;
	if( !stringp(id = query("owner_id")) ) return 0;
	return DATA_DIR + "flower/" + id[0..0] + "/" + id;
}
int set_owner(string id)
{
	set("owner_id", id);
	return restore();
}
void send_flower(mapping flower)
{
	if( !pointerp(flowers) )
	{
		flowers = ({ flower });
	}
	else flowers += ({ flower });
}
void modify_flower(mapping flower)
{
	if( !pointerp(flowers) )
	{
		flowers = ({ flower });
	}
	else flowers -= ({ flower });
}
int check(object me,object obj)
{
	object ob;
	int i,k;
	string str_time;
	string name_id;

	name_id=me->query("id");
	i=sizeof(flowers);
	if(!i) return 0;
	if(i>0)
	{
		//���˲�
		if(flowers[0]["flower_id"]=="qingren cao")
		{
			ob=new(flower_path+"qingren_cao");
			ob->set_amount(flowers[0]["amount"]);
		}
		//��õ��
		if(flowers[0]["flower_id"]=="hong meigui")
		{
			ob=new(flower_path+"red_rose");
			ob->set_amount(flowers[0]["amount"]);
		}
		//��õ��
		if(flowers[0]["flower_id"]=="bai meigui")
		{
			ob=new(flower_path+"white_rose");
			ob->set_amount(flowers[0]["amount"]);
		}
		//����
		if(flowers[0]["flower_id"]=="ding xiang")
		{
			ob=new(flower_path+"ding_xiang");
			ob->set_amount(flowers[0]["amount"]);
		}
		//ĵ��
		if(flowers[0]["flower_id"]=="mu dan")
		{
			ob=new(flower_path+"mu_dan");
			ob->set_amount(flowers[0]["amount"]);
		}
		//������
		if(flowers[0]["flower_id"]=="yu jinxiang")
		{
			ob=new(flower_path+"yu_jinxiang");
			ob->set_amount(flowers[0]["amount"]);
		}
		//�ٺ�
		if(flowers[0]["flower_id"]=="bai he")
		{
			ob=new(flower_path+"bai_he");
			ob->set_amount(flowers[0]["amount"]);
		}
		//����ܰ
		if(flowers[0]["flower_id"]=="kangnaixin")
		{
			ob=new(flower_path+"kang_naixin");
			ob->set_amount(flowers[0]["amount"]);
		}
		//�����
		if(flowers[0]["flower_id"]=="jinyu cao")
		{
			ob=new(flower_path+"jin_yucao");
			ob->set_amount(flowers[0]["amount"]);
		}
		//���
		if(flowers[0]["flower_id"]=="huo he")
		{
			ob=new(flower_path+"huo_he");
			ob->set_amount(flowers[0]["amount"]);
		}
		//������
		if(flowers[0]["flower_id"]=="hudie lan")
		{
			ob=new(flower_path+"hu_dielan");
			ob->set_amount(flowers[0]["amount"]);
		}
		//�ﺣ��
		if(flowers[0]["flower_id"]=="qiu haitang")
		{
			ob=new(flower_path+"qiu_haitang");
			ob->set_amount(flowers[0]["amount"]);
		}
		//ʯ����
		if(flowers[0]["flower_id"]=="shihu lan")
		{
			ob=new(flower_path+"shi_hulan");
			ob->set_amount(flowers[0]["amount"]);
		}
		//������
		if(flowers[0]["flower_id"]=="mati lian")
		{
			ob=new(flower_path+"ma_tilian");
			ob->set_amount(flowers[0]["amount"]);
		}

		tell_object(me,"\nһ��������С����Ų����ǵ����˹�����\n");
		tell_object(me,"���������ߵ����ǰǷ��˵���������������Ļ�����"+flowers[0]["from"]+"�͸����ġ���\n");
		tell_object(me,"��������ӻ������ó�һ��"+flowers[0]["flowername"]+"���������\n");
		tell_object(me,"�����������΢΢һЦ���������Ѿ��͵���СŮ�Ӹ��ˡ���\n");
		tell_object(me,"�����������˳�ȥ��\n");
		if(!ob) ob=new(flower_path+"qingren_cao");
		ob->move(me);
		modify_flower(flowers[0]);
		delete("flowername");
		delete("flower_id");
		delete("to");
		delete("from");
		delete("amount");
		save();
	}
	return 1;
}

