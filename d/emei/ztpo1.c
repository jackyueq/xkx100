//Room: ztpo1.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
����ʯ��ϴ���֮�䣬��·������ʯջ���ݣ�ֱ�����죬ʯ�Ŵ�һǧ����
�༶�����ڶ���ɽ���Ͽ���������µ����������ϣ�ǰ������ӣ�һ����졣
���·�С������졹����ζ���Ҳ��˶��С������¡������������¶��㵽
ϴ��أ����¿ɴ�����ʯ��
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"eastdown" : __DIR__"lianhuashi",
		"westup"   : __DIR__"ztpo2",  
	]));
	set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1080);
	set("coor/z", 110);
	setup();
}

int valid_leave(object me, string dir)
{
	int c_exp,c_skill;

	if (dir == "westup" && userp(me))
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
			tell_object(me,"������������������һ�󣬺����ˡ�\n");
		}
	}
	return 1;
}

