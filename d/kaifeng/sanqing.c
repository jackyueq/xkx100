// /kaifeng/sanqing.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����������������񣬲������⸮�ڵľ����ൽ�������ȥ
���㻹Ը�ˣ��������𲢲���������Ҳ��ͷ����������ᡣ����ȥ��
���߸ߵĸ�¥��������ʸ�
LONG
	);
	set("objects", ([
		__DIR__"npc/obj/sanqingxiang" : 1,
		__DIR__"npc/xianghuo" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"yanqing",
		"north" : __DIR__"yuhuang1",
	]));

	setup();
	replace_program(ROOM);
}
