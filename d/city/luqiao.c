// Room: /city/luqiao.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "¶��");
	set("long", @LONG
�ŵı�ͷ�����Զ�ͤ������������ѩܼ����ͻ��ˮ��֮�ϡ��ŵ���
�棬��ʯɽ��ΡȻ���������Ʋ�ͬ���졣ɽ����һͤ��Իʫ�ˣ�������
�ʷ�֮�󣬸���������ɽ�Ĳ�θС���ɽ�嵹Ӱ��ˮ��ʱ������ʹ��
�о���ˮ֮���ɽ֮ΰ�ˡ����ϵ��ƣ���ͬ�ܺ���ˮ�ˮ����㣬��
����������롣
LONG );
	set("exits", ([
		"northwest" : __DIR__"qinshi",
		"south"     : __DIR__"hushishandong",
		"southup"   : __DIR__"shixingting",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 3);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}