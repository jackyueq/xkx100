//ROOM men1.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "�鷿����");
	set("long",@LONG
�����鷿�ſڣ�ֻ����������������һ������ (duilian)��̧ͷ��
���������һ�����(bian)��д�ż������֡�
LONG );
	set("exits", ([
		"east" : __DIR__"shufang",
		"west" : __DIR__"changl12",
	]));
	set("objects",([
		__DIR__"npc/zhujian" : 1,
	]));
	set("item_desc", ([
		"duilian" : "�е�ˮ�����������ʱ.\n",
		"bian" : HIC "������ң\n" NOR,
	]));
	set("coor/x", -51000);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( (dir == "east") &&
		((string)me->query("family/family_name") != "��ң��") &&
		((string)me->query("family/family_name") != "���չ�") &&
		objectp(present("zhu jian", environment(me))) )
		return notify_fail("��������ס�㣬˵�������Բ��𣬱����صأ���أ���\n");
	return ::valid_leave(me, dir);
}