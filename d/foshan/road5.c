//Room: /d/foshan/road5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ
��ï�ܣ�������棬��λ��·Ҫʮ��С�ġ�
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "east"      : __DIR__"road6",
	    "northwest" : __DIR__"road4",
	]));
        set("objects", ([
                "/clone/medicine/vegetable/chuanshanjia" : random(2),
        ]));
	set("coor/x", -20000);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
