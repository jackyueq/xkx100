// Room: /binghuo/ice11.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ǻ������������һմ����ͨһ����ˤ���˺��С�����
�ı�ˮ������ȫ��ֱ���������ǻ����Ѻܽ��ˡ��ǻ����˱�������
��һ�����ɽ���������䣬�յ�ɽ�Ժ�ˮů�ˡ�
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"northup" : __DIR__"haitan",
	]));
	set("objects", ([
		__DIR__"npc/shayu" : 2,
	]));
	setup();
	replace_program(ROOM);
}

