// Room: /heizhao/shanlu6.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
���������߰�ʮ���·������խ�����а˾����·����ɽ
��������м�һ����С��������һ����ǿ��ȥ��
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : "/d/henshan/hsroad6",
		"westup"    : __DIR__"shanlu7",
	]));
	set("coor/x", -5000);
	set("coor/y", -1300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}