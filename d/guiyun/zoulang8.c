// Room: /d/guiyun/zoulang8.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
�������ӻ����뻨԰�����ȡ������������������ۣ�������������
���οգ���Ŀ���⣬���������˻�����
LONG );
	set("exits",([
		"east"  : __DIR__"huating",
		"north" : __DIR__"zoulang9",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}
