//Room: /d/foshan/road10.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ������
�棬��λ��·Ҫʮ��С�ġ�
LONG);
	set("objects", ([
	   __DIR__"obj/hua3": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "northeast" : __DIR__"road11",
	    "southeast" : __DIR__"road12",
	    "west"      : __DIR__"road9",
	]));
	set("coor/x", 1400);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
