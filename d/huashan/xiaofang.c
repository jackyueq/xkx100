// /d/huashan/xiaofang.c Сľ��
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "Сľ��");
	set("long", @LONG
һ������򵥵�Сľ�ݡ�������һ����¯��ǽ�Ϲ���һ����������
������һλ���ߣ�������Ȼ���أ�ȴ���˲��ɵ�����������
LONG
	);
	set("exits", ([
		"out" : __DIR__"luoyan",
	]));
	set("objects", ([
		CLASS_D("huashan") + "/feng" : 1,
	]));
	set("coor/x", -860);
	set("coor/y", 120);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}
