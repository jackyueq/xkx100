// Room: /d/lingxiao/walle1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "��ͷ");
	set("long", @LONG 
���������ǵĳ�ͷ�����⼫ĿԶ����ֻ������ѩɽ��һƬ��ã����
������֮�£����������ɽ���򶫱��ڶ�ȥ�����ŵ�ѩ��֮�䣬ֻż��
����һ������໡�
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"east"     : __DIR__"walle2",
		"westdown" : __DIR__"gate",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

