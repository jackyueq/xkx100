// Room: /d/heimuya/xiaohuayuan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "С��԰");
	set("long", @LONG
�ӻ谵�ĵص��г������㷢���Լ�����������һ�������µ�С��԰
�У���÷�������ɴ�أ����õ��ľ߽��ģ�����ȥ����һ��ܾ��ŵ�
С�ᡣ
LONG  );
	set("outdoors", "heimuya");
	set("exits", ([
		"south" : __DIR__"didao6",
		"enter" :__DIR__"xiaoshe",   
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}