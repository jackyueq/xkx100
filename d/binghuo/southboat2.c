// Room: /binghuo/southboat2.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
��ľ���ǵ��ϲ����ľ���ͣ�������Φ��Φ����Щľ�������ں�
��֮�أ�ľ�����ܣ�Ӳ����ʯ�������ͷ�������������Ƥ����֯����
�ᡣ����ˮ���⣬������ˮ��Ƥ�����Ѿ߱���
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

