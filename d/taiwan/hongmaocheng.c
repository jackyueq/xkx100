// Room: /d/taiwan/homgmaocheng.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��ë��");
	set("long", @LONG
��ë�ǣ�λ�ڡ��廢�ԡ��ڶ������ϣ����ٵ�ˮ�ӱ�������������
�����涼�Ƕ��£�������Ҫ������ĩ�����������Ȩǿ��������������
�Ǳ���
LONG );
	set("exits", ([
		"south" : __DIR__"danshui",
	]));
	set("objects", ([
		__DIR__"npc/hongmao": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2540);
	set("coor/y", -6960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

