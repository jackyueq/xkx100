//Room: /d/foshan/road3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ
��ï�ܣ�������棬��λ��·Ҫʮ��С�ġ�
LONG);
	set("objects", ([
	   __DIR__"npc/bee": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"road2",
	    "northeast" : __DIR__"road4",
	]));
	set("coor/x", -30000);
	set("coor/y", -45000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
