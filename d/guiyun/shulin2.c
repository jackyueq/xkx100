// Room: /d/guiyun/shulin2.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",@LONG
����һƬС���֡��������̲�����ï�ܵ������š���Ҷ�ķ�϶��
ż������һֻС�񱻾�������ʮ�־��š�
LONG
);
	set("objects",([
		__DIR__"npc/bee" : 1,
	]));  
	set("exits",([
		"east"  : __DIR__"shulin1",
		"south" : __DIR__"caodi2",
	]) );
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}

