// Room: /d/suzhou/wanjing.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����Ȫ");
	set("long", @LONG
��ɽ��������һ����Ȫ��ϵ�ϳ�������ɮ�������������䣬���һ
ǧ�İٶ��ꡣ��˵Ȫ��ͨ��������������ӿȪ����ˮ������Ϊ�����µ�
��Ȫ����ʯ�̡�����Ȫ�����֣�ϵ�������������⡣
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown"   : __DIR__"wanjing",
	]));
	set("coor/x", 780);
	set("coor/y", -1010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
