// Room: /d/taishan/kongziya.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������λ����ֶ���·��ɽ���ϡ������������ӵ�̩ɽ���ˣ�����
������������ ����������µ�һƥ�����˴����������»������塣
�����С�̩ɽ������������ɽ��ֹ����̡�
LONG );
	set("exits", ([
		"northdown" : __DIR__"kongzimiao",
		"southdown" : __DIR__"tianjie",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 780);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
