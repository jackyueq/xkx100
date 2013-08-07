//Room: shierpan3.c ʮ����
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","ʮ����");
	set("long",@LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡������·���и������أ�����������
���л���(clap)���ɴ����Ͽɴﻪ�϶��������������֡�
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"eastdown"  : __DIR__"shierpan2",
		"southwest" : __DIR__"shierpan4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6160);
	set("coor/y", -1070);
	set("coor/z", 80);
	setup();
}
void init()
{
	add_action("do_clap", "clap");
}

int do_clap()
{
	object me = this_player();
	int c_exp,c_skill;
 
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("strike",1);
	write("���ں�Ȼ���ܴ���һ��������Ⱥ�ܴε���ϣ��������һ�ܴ�����Ⱥ�ܱ��Ȼ\n");
	write("��ֹ����������Ϊ�ˡ�\n");
	if ( me->query("qi") < 10 )
		 me->unconcious();
	else
	{
		if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill< 101)) 
		me->improve_skill("strike", (int)me->query_skill("strike", 1));
		me->receive_damage("qi", 10);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	int c_exp,c_skill;

	if (dir == "southwest" && userp(me))
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		if ( me->query("qi") < 10 ) me->unconcious();
		else
		{
			me->receive_damage("qi", 10);
			if (((c_skill*c_skill*c_skill/10)< c_exp) &&
				(c_skill < 101))
				me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
			tell_object(me,"��������ʮ���̣�������ɽ��·�ֶ����䣬�����ˡ�\n");
		}
	}
	return 1;
}
