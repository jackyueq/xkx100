// Room: /d/taishan/shixin.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
�������������ķ嶥���������ʯ������һ�𣬾�˵�������Ĵ�
���⣬��������ʯʱʯ��㲻�ᶯҡ����֮��ҡ����ֹ��
LONG );
	set("exits", ([
		"southdown" : __DIR__"lianhua",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 430);
	set("coor/y", 630);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}
