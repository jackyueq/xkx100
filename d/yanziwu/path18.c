// Room: /d/yanziwu/path18.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ˮ��С·");
	set("long", @LONG
�����ں��ߵ�С·�ϡ����漸����Ĺ�ľ���⣬����̫��ˮ�ˡ���
ˮ������û��ľ�ԣ����㡢ˮ��������ʳ������ˮ������
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"ouxiang1",
		"southeast" : __DIR__"qingfeng",
	]));
	set("coor/x", 1190);
	set("coor/y", -1240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}