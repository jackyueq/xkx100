// Room: /d/huijiang/qiufang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "����");
	set("long",@LONG
�����Ǻ컨���Ѻ��ͽ���幷�ĵط����ſڴ��ţ�Ҳ����Ҫ����
�ܵ������䵹�Ǵ�ɨ�ĺܸɾ���������һ˿������Ҳ�����š�
LONG );
	set("exits", ([
		"north" : __DIR__"zoulang3" ,
	]));
	set("objects", ([
		CLASS_D("honghua")+"/jiang-sigen" : 1,
	]));	
	set("coor/x", -50050);
	set("coor/y", 9130);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( (dir == "north") &&
		((string)me->query("family/family_name") != "�컨��") &&
		objectp(present("jiang sigen", environment(me))) &&
		(!present("honghua ling", me)))
	{
		me->receive_damage("qi", 15);
		me->receive_damage("jing", 5);
		return notify_fail("���ĸ���ס��˵���Ǳ�����֣�˽��������һ�����幷��\n"HIR"���ĸ����������ף��Ⱥ�������һ�١�\n"NOR);
	}
	return ::valid_leave(me, dir);
}
