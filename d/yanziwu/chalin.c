// Room: /d/yanziwu/chalin.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "�軨��");
	set("long", @LONG
һ��������ȥ�����Ǻ���ͷ׵Ĳ軨���������ݡ�����ˮ�ߣ�С��
��Ȼ��֪��ʲôʱ���Ѿ������ˡ�������ֻ���������֣�һѰ��·�ˡ�
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"north" : __DIR__"chalin1",
	]));
	set("objects", ([
		"/d/dali/obj/shanchahua" : 1,
	]));
	set("coor/x", 1210);
	set("coor/y", -1300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

