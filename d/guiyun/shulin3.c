// Room: /d/guiyun/shulin3.c
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
		__DIR__"obj/stick" : 1,
	]));  
	set("exits",([
		"west"  : __DIR__"shulin1",
		"north" : __DIR__"shulin4",
		"south" : __DIR__"caodi3",
	]) );
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}

