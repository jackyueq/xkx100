// Room: /d/quanzhou/yaofang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
�����Ǽ�������ҩ��ҩ�ĵط����������з���һֻ��ҩ�õ�ҩ�ʣ�
һ��С������ͣ�ļ�ҩ���Ļ���ˮ��¯�в�ͣ��ð������ˮ����ɢ
����ŨŨ��ҩ����
LONG );
	set("exits", ([
		"west" : __DIR__"jishitang",
	]));
	set("objects", ([
		"/clone/misc/yaojiu" : 1,
		__DIR__"npc/xiaosi" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
