// Room: /d/taishan/xiangshan.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
�����Ϊ��ɽ���׳���Ƿ壬ɽ������ʯ�´�����Ƕ���������Ϊ
���ƶ����嶫�����ƶ���
LONG );
	set("exits", ([
		"north"    : __DIR__"tianjie",
		"eastdown" : __DIR__"qingyun",
		"westdown" : __DIR__"baiyun",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 760);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
