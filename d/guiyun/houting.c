// Room: /d/guiyun/houting.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
���ǹ���ׯ�ĺ�����Ҳ��ׯ���������˽�µĵط���������һ����
������ڴ�����һ�ȴ����磻�����������˵��Է���
LONG
);
	set("exits",([
		"east"  : __DIR__"shufang",
		"west"  : __DIR__"wofang",
		"north" : __DIR__"zoulang3",
	]) );
	set("objects",([
		__DIR__"npc/yahuan" : 1,
	]));  
	setup();
	replace_program(ROOM);
}
