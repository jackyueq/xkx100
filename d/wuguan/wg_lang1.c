// Last Modified by Sir on 9/17/2001
// wg_lang1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�ͨ�����䳡�����Ǽ������߹�����ʱ���˱�̧��
���������������������赹�ġ�
LONG);
	set("exits", ([
		"north" : __DIR__"wg_wuchang1",
		"south" : __DIR__"wg_dayuan",
	]));
	set("outdoors", "wuguan");
	set("objects", ([
		__DIR__"npc/wg_mrdizi" : 1,
	]));
	set("coor/x", 11);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

