// Room: /d/baituo/zhuyuan.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","��԰");
	set("long", @LONG
������һ���ľ�����԰���߸ߵ͵͵Ĵ��������װ��ñ������¡�
�������Ǻ�Ժ���������и���Է���ϱ��ǻ�԰��
LONG	);
	set("exits",([
		"northeast" : __DIR__"tuyuan",
		"northwest" : __DIR__"houyuan",
		"south"     : __DIR__"huayuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "baituo");
	set("coor/x", -50010);
	set("coor/y", 20070);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
