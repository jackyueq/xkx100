// Room: /d/nanshaolin/stoneroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long",@LONG
һ��������ͨ�˴��ʯ��·��������ȫ�µ������룬�������н�ͨ
�æ�ĵط����ɴ����Ͽɴ���۱�����Ǵ󱯵������շת
�ɴ�����Ժ������Ժ������Ҫ�ء�
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"west"  : __DIR__ "huaishu4",
		"east"  : __DIR__ "songshu2",
		"north" : __DIR__"dabeidian",
		"south" : __DIR__"daxiong",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x", 1810);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

