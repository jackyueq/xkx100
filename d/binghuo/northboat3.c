// Room: /binghuo/northboat3.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "�Ʒ���");
	set("long", @LONG
������ʱֻʣ�󷫳Է磬�Ǵ���б��࣬�ں����Ͽ�����������
Φ�����б������������ˮ�档����ˮ��ȫ�����˾����ˣ���Χ���
һ�ţ��������������ͣ����ʱ�������ѡ�
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

