// Room: /d/baituo/caomeide.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","��ݮ��");
	set("long", @LONG
������һ���ݮ�أ��ʺ�Ĳ�ݮɢ�����̲��У����˸е������
�⡣
LONG	);
	set("exits", ([
		"northeast" : __DIR__"shulin1",
	]));
	set("objects" , ([
		__DIR__"obj/caomei" : random(7),
	]));
	set("outdoors","baituo");
	set("coor/x", -50050);
	set("coor/y", 20010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
