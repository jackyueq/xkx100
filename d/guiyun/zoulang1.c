// Room: /d/guiyun/zoulang1.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����������������������ȡ������������������ۣ�������������
���οգ���Ŀ���⣬���������˻�����
LONG );
	set("exits",([
		"east"  : __DIR__"zoulang7",
		"west"  : __DIR__"zoulang2",
		"south" : __DIR__"zhongting",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}
