//Room: /d/foshan/street1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ���");
	set("long",@LONG
��ɽ��ֵ�ƽ���������������ţ�������һ��������������
ΰ���ô�һ��������
LONG);
	set("objects", ([
	   __DIR__"npc/jiading": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "north" : __DIR__"beidimiao",
	    "west"  : __DIR__"westgate",
	    "east"  : __DIR__"street2",
	]));
	set("coor/x", -1600);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
