// Room: /d/heimuya/guang.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��ɽ�ȣ�������ֲ�Ų�ƺ�������ǡ�������̡��������á�
������һ����ɽ��ʯ����
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
		"east"    : __DIR__"linjxd1",
		"west"    : __DIR__"shidao1",
		"southup" : __DIR__"dating3",
	]));
	set("objects",([
		__DIR__"npc/kid" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}