// /d/meizhuang/mishi2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ��СС��԰�ӣ����������˴��СС����������֦�еĳ���
���أ��еĻ�����֦��Ҷ�����м���һ���ľ(guanmu)�͵Ͱ����ģ���
������ǳ�����עĿ���㲻��������࿴�����ۡ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"xiaoyuan",
	]));
	set("objects", ([
		__DIR__"obj/guanmu" : 1,
	]) );
	set("outdoors", "meizhuang");
	set("coor/x", 3520);
	set("coor/y", -1430);
	set("coor/z", 20);
	setup();
}
void reset()
{
	object *inv, con, item, guanmu;

	::reset();

	guanmu= present("guanmu", this_object());
	inv = all_inventory(guanmu);

	if( !sizeof(inv))
	{
		con = new(__DIR__"obj/honghua");
		item = new(NOSTRUM_DIR"zhuguo");
		item->move(con);
		con->move(guanmu);
	}
}
