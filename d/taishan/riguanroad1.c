// Room: /d/taishan/riguanroad1.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�չ�ɽ·");
	set("long", @LONG
�������չ۷�С·���Է嶥���£����ᶫ���š��˴�ɽ�ƶ��ͣ���
��������ȣ�һ��С�Ķ��������ȥ��
LONG );
	set("exits", ([
		"eastdown" : __DIR__"dongling",
		"westup"   : __DIR__"riguan",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 380);
	set("coor/y", 770);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}
