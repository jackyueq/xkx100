// Room: /d/heimuya/grass2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM; 
void create()
{
	set("short", "�ݵ�");
	set("long",@LONG
������һƬ�ݵء��ݵ������ƺ��������ݣ��������������������
һ��С��԰��
LONG );
	set("outdoors", "heimuya");
	set("exits", ([
		"west"  : __DIR__"chufang1",
		"east"  : __DIR__"hua1",
		"north" :__DIR__"dating1",
		"south" :__DIR__"grass1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}