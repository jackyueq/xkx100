//Room: /d/dali/zhulin2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����");
	set("long",@LONG
����һ��Ƭï�ܵ����֣�������ɽ���Ǹ�ï�ܵ���Ҷ�֣�������
�ࡣ�о����̨�������������������ס����£���׽�á�¹��С�ޣ�
�������������ɽ��׽��Щ�����ޡ�
LONG);
	set("objects", ([
	   __DIR__"npc/lieshou": 2,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"hexi",
	]));
	set("coor/x", -39100);
	set("coor/y", -89210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}