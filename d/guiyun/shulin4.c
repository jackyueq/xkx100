// Room: /d/guiyun/shulin4.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",@LONG
����һƬС���֡��������̲�����ï�ܵ������š���Ҷ�ķ�϶��
ż������һֻС�񱻾�������ʮ�־��š�
LONG
);
	set("exits",([
		"northwest" : __DIR__"shulin5",
		"east"      : __DIR__"shulin6",
		"south"     : __DIR__"shulin3",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}

