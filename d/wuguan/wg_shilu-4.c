// wg_shilu-4.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ��·�ϣ������ȥ���Ǻ�Ժ�ˣ������Ǳ���������
���洫�����󷹲˵���������������ݵķ����������ȥ����ݴ�����
LONG);
	set("exits", ([
		"west"  : __DIR__"wg_lang3",
		"east"  : __DIR__"wg_shilu-3",
		"south" : __DIR__"wg_shilu-2",
		"north" : __DIR__"wg_fanting",
	]));
	set("objects", ([
		__DIR__"npc/wg_emxiaost" : 1,
		__DIR__"npc/wg_tiezhangdizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 41);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

