//Room: /d/foshan/road8.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ����������������ɽ��
����ͨ�򸣽�Ȫ�ݡ�
LONG);
	set("objects", ([
	   __DIR__"npc/zhang": 1,
	   __DIR__"npc/zhangkang": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "west" : __DIR__"eastgate",
	    "east" : __DIR__"road9",
	]));
	set("coor/x", -1000);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
