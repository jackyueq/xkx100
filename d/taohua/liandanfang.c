// Room: /d/taohua/liandanfang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����һ�������ҩʦ��������������������������İ��Ƶĵ�ҩ��
�һ�������ͼ�����������������ˡ��������Եı仯��ȫ�����ڡ�
LONG
	);
	set("exits", ([
	      "out" : __DIR__"jingshe.c",
	]) );
	set("objects", ([
		"/clone/medicine/nostrum/jiuhuawan": 1,
		__DIR__"obj/tupu": 1,
	]));
	set("no_clean_up",0);
	set("coor/x", 9010);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

