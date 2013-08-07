// Room: /d/gaochang/zoulangw.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;
string look_writing();

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǵ������ȡ�����һ��֧������ĸ�ǽ�ϣ���һ�����뱱�ߵ�
�õ��ݶ�����������������̧����ȥ��������Ҳ�ò�������˸��ַ���
��ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡��ϱ�ǽ������
һ����(writing)��
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"wroom3",
		"northeast" : __DIR__"zoulangc",
	]));
	set("item_desc",([
		"writing"		:	(: look_writing :),
	]));
	set("no_clean_up", 0);
	setup();
}

string look_writing()
{
	return
	"\n"
"              ����������������������������������\n"
"              ��������  ����������    ����������\n"
"              ��������  ����������  ������������\n"
"              ������    ����������  ������������\n"
"              ����    ������������  ������������\n"
"              ��    ��  ����������  ������������\n"
"              ��������  ����  ����  ������  ����\n"
"              ��������  ����  ����  ������  ����\n"
"              ��������  ����  ����  ������  ����\n"
"              ��������  ����  ����  ������  ����\n"
"              ��������  ����                ����\n"
"              ������    ����  ������������  ����\n"
"              ����������������������������������\n"
"              ����������������������������������\n";
}

void init()
{
	add_action("do_study", "yanxi");
}


int do_study(string arg)
{
	object me = this_player();
	int cost=10;	

	if ( !arg && ( arg != "qiang" ) && ( arg != "qiangbi" ) )
		return notify_fail("ʲô��\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	if((int)me->query("jing") < 30)
		return notify_fail("�����ھ����޷����У�\n");

	me->receive_damage("jing", 10);

	message_vision("$N��ר���ж�ǽ���ϵĹŹ�ͼ�Ρ�\n", me);

	if ( (int)me->query_skill("medicine", 1) < 100)
	{
	      if ((int)me->query("jing")>cost)
		{me->improve_skill("medicine", (int)(me->query("int")/4));
		 write("�����ǽ����ĥ��һ�ض����ƺ��Լ���֮���е��ĵá�\n");
		 me->set_temp("stone_learned",1);
		 return 1;
		}
		else
	     {
		cost=me->query("jing");
		write("�����ڹ���ƣ�룬�޷�ר�������ж�����֮����\n");
	     } 
		 
	}

	if ( !me->query_temp("stone_learned") )
	{
		write("�����ǽ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
	}
	return 1;
}

