// Room: /d/lingzhou/huilang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ǰ��ͺ󹬵Ļ��ȣ������������������ȶ��Ƿ�������
�ߣ��������Ű���ʯ�塣����ͨ����ƫ�������˸���������󹬡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"xidian",
		"east"  : __DIR__"yushanfang",
		"south" : __DIR__"ysdian",
		"north" : __DIR__"huilang2",
	]));
	set("objects", ([
		__DIR__"npc/shiwei" : 4,
	]));
	set("outdoors", "xixiagong");
	set("coor/x", -17960);
	set("coor/y", 32106);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
