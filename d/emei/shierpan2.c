//Room: shierpan2.c ʮ����
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","ʮ����");
	set("long",@LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡����ɴ����Ͽɴﻪ�϶�����������
���֡�
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"northeast" : __DIR__"shierpan1",
		"westup"    : __DIR__"shierpan3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6150);
	set("coor/y", -1070);
	set("coor/z", 70);
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
			tell_object(me,"��������ʮ���̣�������ɽ��·�ֶ����䣬�����ˡ�\n");
		}
	}
	return 1;
}

