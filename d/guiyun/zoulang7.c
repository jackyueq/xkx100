// Room: /d/guiyun/zoulang7.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
�������������뻨�������ȡ������������������ۣ�������������
���οգ���Ŀ���⣬���������˻�����
LONG );
	set("exits",([
		"north" : __DIR__"huating",
		"west"  : __DIR__"zoulang1",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}
