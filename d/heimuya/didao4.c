// Room: /d/heimuya/didao4.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","�ص���ͷ");
	set("long", @LONG
�����ǰ����һ���⣬���Ǳ��ж��죬ǰ��������еط���
LONG  );
	set("exits",([
		"east"   :__DIR__"didao1",
		"west"  :__DIR__"didao3",
		"south" : __DIR__"didao4",
		"southup" : __DIR__"didao6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}