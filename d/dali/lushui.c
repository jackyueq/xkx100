//Room: /d/dali/lushui.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ˮ�ذ�");
	set("long",@LONG
һ����·������ˮ�ݹ�ȵ��ϱ���������ˮ������ȥ����������
��ˢ�Ź��д�أ��������ѩɽ������ĸ���ɽ�Ը��ʱ��ա���·��
ͨ�˹����Ĵ���͵ĵ飬������������С���䡣
LONG);
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"badidian",
	    "south"      : __DIR__"atoubu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -90000);
	set("coor/y", -70010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}