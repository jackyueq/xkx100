//Room: wannianan.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
�����ֽ���һ��ͻ���ɽ���ϣ���Χ��ľɭɭ����Ȫ���ȣ��в��޿�����
���޿�����ɫ�ǳ����ˡ��ɴ����Ϲ�ʮ���̿ɴﻪ�϶�����������������
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"southdown" : __DIR__"bailongdong",
		"westup"    : __DIR__"shierpan1",
		"enter"     : __DIR__"wnadian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6130);
	set("coor/y", -1060);
	set("coor/z", 60);
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

