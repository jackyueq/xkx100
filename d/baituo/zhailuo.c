// Room: /d/baituo/zhailuo.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","Сլ��");
	set("long", @LONG
������һ����Ӱ��涵ľ��׵�Сլ�䣬���з���һ���ںڷ����Ĵ�
ˮ�ס�����ɽ�ϳ����ѩ����������˼���һ����������������������
ѩˮ�������е�ˮ��������
LONG	);
	set("exits",([
		"east" : __DIR__"tangwu",
	]));
	set("objects",([
		__DIR__"npc/jiren": 1,
		__DIR__"npc/jiren1": 1,
	]));
	set("outdoors", "baituo");
	set("resource/water", 1); 
	set("coor/x", -50020);
	set("coor/y", 20052);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}



