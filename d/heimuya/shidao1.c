// Room: /d/heimuya/shidao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
һ·�����У��м����һ����Լ��ߵ�ʯ��������ʯ����ǽ��һ·
�϶������½�ͽģ�����������߶�����������·�˶����ܼ��ӡ�
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "east" : __DIR__"guang",
	    "north" : __DIR__"shidao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3050);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}