// Room: /d/heimuya/shandao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ����ɽ�����Ƽ�֮�վ���һ��խС���͵�ɽ����������ɽ
�ϣ�����ɽ����һƬ��̲��
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "eastdown" : __DIR__"changtan",
	    "westup"   : __DIR__"shandao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3210);
	set("coor/y", 4200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}