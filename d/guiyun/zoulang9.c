// Room: /d/guiyun/zoulang9.c
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
		"west"  : __DIR__"huayuan",
		"south" : __DIR__"zoulang8",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}
