// Room: /d/nanshaolin/sblu-1.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��������ʯ��·�ϡ�������һ�׼����ľ޴�ʯ���������
�ģ����Բ���ʮ������Ҳ�������⡣�����ǲ���Űأ�ֱ�����죬�϶�
���������������ա�����ɮ���������������䡣·�ľ�ͷ��������
��ڻԻ͵Ĵ��۱��
LONG );
	set("exits", ([
		"southeast" : __DIR__"celang-4",
		"southwest" : __DIR__"celang-2",
                "south"     : __DIR__"twdian",
                "north"     : __DIR__"xianglu",
	]));
	set("objects",([
		__DIR__"npc/zjseng1" : 1,
		__DIR__"npc/slseng1" : 1
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

