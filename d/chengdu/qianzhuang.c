// Room: /d/chengdu/qianzhuang.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����Ǯׯ");
	set("long", @LONG
�����ǳ�����������Ǯׯ������Ǯׯ����Ϣ��͵�������Ƿ����˵
����������׼ҵ��ӣ������ڴ��к�����������å����һ�㶼��������
�鷳����������һ��������ܺá�
LONG	);
	set("exits", ([ 
		"east" : __DIR__"chunxilu2",
	]) );
	set("objects", ([
		__DIR__"npc/boss3" : 1,
	]));
	set("coor/x", -8070);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	tell_object(this_player(),WHT "�������Ŀڴ���̾�˿������߳���Ǯׯ��\n"NOR,this_player());
	return 1;
}
