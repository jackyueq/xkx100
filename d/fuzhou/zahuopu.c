// Room: /d/quanzhou/zahuopu.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
������һ��ר��Ů���õĶ�����С���ӡ�
LONG );
	set("exits", ([
		"east" : __DIR__"xiangyang",
	]));
	set("objects", ([
		__DIR__"npc/chen" : 1,
	]) );
	set("coor/x", 1810);
	set("coor/y", -6320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}