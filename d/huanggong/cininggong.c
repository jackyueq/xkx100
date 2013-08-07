// Room: /d/huanggong/cininggong.c

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "������");
	set("long", @LONG
����̫����޹���. ����Ҳ��̫��������֮������������������
ʮ��ĳ�͢����ͳ��������ڵ�Ů����֮�֡�����������ů�󡣶�ů
������̫��ĵ񻨴� (bed)�������Ǹ�����ã�����һ����̫�����
����������������һ��������
LONG
	);
	set("opened", 1);
	set("item_desc", ([
		"bed" : "̫������ӵĴ�����ʲô����\n",
	]));
	set("exits", ([
		"south" : __DIR__"ciningmen",
		"north" : __DIR__"dafotang",
	]));
	set("objects", ([
		__DIR__"npc/leichu" : 1,
		__DIR__"npc/dengbingchun" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 5271);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "dakai");
	add_action("do_open", "xiangkai");
}

int do_open(string arg)
{
	object me, obj;

	me = this_player();
	if( !arg || arg!="bed" )
              return notify_fail("��Ҫ��ʲô��\n");
	message_vision(YEL
"$N�ƿ����죬���������и�Сͭ������ָһ����һ����Լһ�ߣ���Լ
���ߵ�ľ��Ӧ�ֶ��������Ǹ������εİ��񣬺�Ȼ......\n" NOR,me);
	if ( query("opened") != 1)
	{
		message_vision(HIR"ʲô��û�У�\n" NOR,me);
		return 1 ;
	}
	message_vision(HIY"�����������飡\n" NOR,me);
	obj = new("/d/beijing/obj/book14_3");
	obj -> move(this_object());
	obj = new("/d/beijing/obj/book14_4");
	obj -> move(this_object());
	obj = new("/d/beijing/obj/book14_6");
	obj -> move(this_object());
	add("opened", -1);
	return 1;
}
