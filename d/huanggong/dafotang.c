// Room: /d/huanggong/dafotang.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�������Ĵ���á����﹩��һ���������񣬷���ǰ��һ�Ź�
�������ϵ���յ�͵ơ�
LONG );
	set("exits", ([
  		"south" : __DIR__"cininggong",
	]));
	set("objects", ([
  		__DIR__"npc/maodongzhu": 1,
  		__DIR__"npc/liuyan": 1,
	]));
	set("coor/x", -220);
	set("coor/y", 5272);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}