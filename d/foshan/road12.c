//Room: /d/foshan/road12.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ������
�棬��λ��·Ҫʮ��С�ġ�
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "northwest" : __DIR__"road10",
	]));
	set("objects", ([
	        __DIR__"npc/snake": 1,
                "/clone/medicine/vegetable/chantui" : random(2),
	]));
	set("coor/x", 1500);
	set("coor/y", -6700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
