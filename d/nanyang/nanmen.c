// Room: /d/nanyang/nanmen.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short","�ϳ���");
	set("long",@LONG
�������������š���������������ڣ�ˮ�����֣�������ġ�����
�Ͼ��Ǻ�ˮ�ˣ�ż��������ں����������㡣
LONG);
	set("exits",([
		"north"   : __DIR__"dajie1",
		"south"   : __DIR__"hanshui2",
	]));
	set("objects",([
		"/d/city/npc/bing" : 1,
	]));
	set("outdoors","nanyang");
	set("coor/x", 10);
	set("coor/y", 480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
