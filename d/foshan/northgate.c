//Room: /d/foshan/northgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ����");
	set("long",@LONG
�����Ƿ�ɽ��ı��š��������򱱣���������ɴ���ԭ������
һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG);
	set("objects", ([
//	   __DIR__"npc/puren": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"street3",
	    "north"  : __DIR__"nanling",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -6000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
