// Room: /d/mobei/downxuanya.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���͵�ɽ�±�����Į���ຮ�ķ�ɳ��ʴ��ɽ�¸��ǹ⻬�վ�������
����ƽƽ��ɽʯ�����������ɫ��ɽʯ�������ߣ�ֱ������еİ�����
�ӡ���ͷ��ɫ�Ĵ��Χ����ɽ�±ߵ�һ���������С�
LONG);
	set("outdoors","mobei");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/baidiao" : 2,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaolu",
	]));
	set("coor/x", -250);
	set("coor/y", 5210);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}
int do_climb(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="ya")
	{
		message("vision", me->name() + "�ԳԿԳ�����������ȥ��\n", environment(me), ({me}) );
		me->move(__DIR__"yading");
		message("vision", me->name() + "������������������ճ��һ���ࡣ\n", environment(me), me );
		return 1;
	}
}

