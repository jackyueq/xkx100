// Room: /d/taishan/fengyue.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�����ޱ�");
	set("long", @LONG
��ĸ���������С�εȻ���㡱�������츣�ء������������ơ�����
�������̣���ɽɫ��ӳ������������ռ������¡����ֲ�ȥ�߿���
Ϊ�����ޱߣ���ɫ������
LONG );
	set("exits", ([
		"northeast" : __DIR__"doumo",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 590);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
