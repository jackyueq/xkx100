// Room: /d/baituo/guangchang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
������һ�鲻С�Ĺ㳡���������ũ��ɹ�Ĺ�������ǡ�����ɽ
ׯ���������м�Сũ�ᣬ�����п�˵أ����Ϸ���һ��С�š�
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"east"      : __DIR__"nongshe",
		"northup"   : __DIR__"shijie",
		"northwest" : __DIR__"shanlu",
		"southeast" : __DIR__"bridge",
	]));
	set("objects",([
		__DIR__"npc/kid" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
