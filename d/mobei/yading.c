// Room: /d/mobei/yading.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "ɽ�¶�");
	set ("long", @LONG
�¶��Ǹ��޴��ƽ̨�������˰�����ѩ������޴��ʯͷ������һ
�ߣ���״ǧ��ٹ֣���������ප����С�ף���������������ߡ��ı�
��ɽ��ƽƽ���������ð�����б�����±ߡ�
LONG);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("coor/x", -250);
	set("coor/y", 5200);
	set("coor/z", 30);
	setup();
}
void init()
{
	add_action("do_jump","jump");
	add_action("do_jump","tiao");
}
int do_jump(string arg)
{
	object me = this_player();

	if (arg !="down") return notify_fail("��Ҫ������ȥ��\n");
	if( arg=="down")
	{
		write("������������ɽ�¡�\n");
		message("vision", me->name() + "һ����������ɽ�¡�\n", environment(me), ({me}) );
		me->move(__DIR__"downxuanya");
		message("vision", me->name() + "��ɽ����������������\n", environment(me), ({me}) );
	}
	return 1;
}
