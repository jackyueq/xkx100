//Room: /d/quanzhou/westbridge.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���ŵ���");
	set("long",@LONG
����Ȫ�������һ�����ţ��Ӱ��Ž��������ĳ�¥����������
������άϵ���ճ����µ���������𡣹������������߿ɴ����Ϲ�
����
LONG);
	set("outdoors", "quanzhou");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : "/d/foshan/road14",
	    "east"  : __DIR__"westroad2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6370);
	set("coor/z", 0);
	set("coor/x", 1820);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
