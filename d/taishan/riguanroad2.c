// Room: /d/taishan/riguanroad2.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�չ�С·");
	set("long", @LONG
�������չ۷�С·���Է嶥���£����ᶫ���š��˴�ɽ�ƶ��ͣ���
��������ȣ�һ��С�Ķ��������ȥ��
LONG );
	set("exits", ([
		"east"  : __DIR__"dongtian",
		"west"  : __DIR__"dongling",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 770);
	set("coor/z", 190);
	setup();
	replace_program(ROOM);
}
