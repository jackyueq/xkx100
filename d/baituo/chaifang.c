// Room: /d/baituo/caifang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","��");
	set("long", @LONG
���Ǽ䲻��Ĳ񷿣�ľ���Ѿ����չ��ˣ�ǽ�Ƿ��ż��ѡ��񵶡���
LONG );
	set("exits",([
		"west" : __DIR__"chufang",
	]));
	set("objects",([
		__DIR__"npc/laocai" : 1,
	]));
	set("coor/x", -49990);
	set("coor/y", 20060);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
