// Room: /d/lingxiao/sroad4.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","��紨");
	set("long",@LONG
����վ��һ�龧Ө��͸���������֮�ϣ�ֻ���Ų����ϴ���һ��͸
�ǵı�����ѩɽ�ϱ���ŭ�ţ�������Ƶ�������ѩ������һƬ��ã��
�Ѿ�������������������ˡ�ƬƬѩ���ӿ��ж�ë��������¡������
������·������춱��ϡ���ν��ѩ���ѣ����������족��
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"southdown" : __DIR__"shiya",
		"northup"   : __DIR__"sroad5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8970);
	set("coor/z", 100);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northup" || dir == "southdown")
	{
		me->recieve_damage("jing", 30);
		me->recieve_damage("qi", 30);
	}
	return 1;
}
