// Room: /d/tiezhang/shanlu5.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ���̳ɵ�С·�ϣ������Ǹߴ�Ĵ��������ڽ����ƻ�
�����գ�������ˬ���ˡ���ΪСָ�������������˽϶࣬��������
·Ҳ�����ĺܺá�
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westup"   : __DIR__"sblu1",
		"eastdown" : __DIR__"pingtai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2050);
	set("coor/y", -1910);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

