// Room: /d/heimuya/hua1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ�������µ�С��԰��԰�У���÷�������ɴ�أ����õ���
�߽��ģ�����ȥ��һƬ��ݵء�
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "west" : __DIR__"grass2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3020);
	set("coor/y", 4020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}