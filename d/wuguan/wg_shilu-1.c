// wg_shilu-1.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ��·�ϣ���������������Ʒ�����㿴���в���������
���Ÿ����Ĺ��ߣ����Ǳ߹�������������ݴ�����
LONG);
	set("exits", ([
		"south"   : __DIR__"wg_wupinfang",
		"east"    : __DIR__"wg_xuetang",
		"west"    : __DIR__"wg_zhangfang",
		"northup" : __DIR__"wg_dating",
	]));
	set("objects", ([
		__DIR__"npc/wg_xiaojh" : 1,
		__DIR__"npc/wg_xiaoyaodizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 41);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

