// Room: /d/nanshaolin/stoneroad2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long",@LONG
һ��ƽ��������ʯ·��·����������ɮ��ɹ������Ϣ֮�á���
������ִ���㣬����ͨ����һЩæµ��ɮ�£����Ҵҵı��۶�ȥ���ƺ�
��ʲôҪ������һ�ӻ���ɮ����ִ�䵶����������Ѳ�ӡ�
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"east"  : __DIR__ "stoneroad3",
		"west"  : __DIR__ "stoneroad4",
		"south" : __DIR__ "xianglu",
		"north" : __DIR__ "miaofadian",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x", 1820);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

