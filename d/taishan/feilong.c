// Room: /d/taishan/feilong.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ĸ��������Ȫɽ������Ȫͤ��������С��;���ͤ�½��ڡ���̶
���١��������裬������������������̶�䣬��ˮ����˿��������
LONG );
	set("exits", ([
		"northwest" : __DIR__"doumo",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 410);
	set("coor/y", 590);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
