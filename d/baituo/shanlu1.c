// Room: /d/baituo/shanlu1.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","ɽ·");
	set("long", @LONG
������ɽ�ϵ���·��������һ���������Ĵ��֡�����ش�������
����ɽ�������һƬƬ����������ҡ�ڡ�
LONG);
	set("exits",([
		"north" : __DIR__"shulin",
		"southeast" : __DIR__"shanlu",
	]));
	set("outdoors", "baituo");
	set("objects" ,([
		__DIR__"npc/qiaofu" : 1 ,
	]) );
	set("coor/x", -50030);
	set("coor/y", 20010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
