// Room: /binghuo/northboat2.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����Φ��������֪������˭������ǰ����Φ���˰׷���׼
�����������в��б�����ˮ���㹻֧�ð��ꡣ����ˮ�ָ��������ư͡�
��Φ�ϰ׷�Ʈ�����������졣
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

