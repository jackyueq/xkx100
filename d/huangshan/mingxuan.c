// Room: /d/huangshan/mingxuan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����Ȫ");
	set("long", @LONG
Ȫˮ�Ը�ɽʯ����Ȼ���£����һ�����ɽ´������ұ��пգ�״
����ٵ���ʯ�������ö����н������������������Թ�ʫ�޵���ȴ��
������ϸ������ʮ���Ҿ㲻�ڡ���
LONG
	);
	set("exits", ([ 
		"south"	: __DIR__"sandie",
	]));
	set("objects", ([
		__DIR__"obj/stone3" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
