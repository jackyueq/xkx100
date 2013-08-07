// Room: /d/gumu/shishi0.c
// Last Modifyed by Winder on Jan. 14 2002
 
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIB"ʯ��"NOR);
	set("long", @LONG
ͷ����ʯ�� (shibi)�ָֻ���ԭ״���㷢���Լ�������һ��������
ʯ���У��յ����ĸо�ʹ������ֻ�п־壬�������ǹ¶����㲻֪��
�εأ�����������һƬ��ֻ�ܿ�����ǰ�С�
LONG	);
	set("item_desc", ([
		"shibi": "ʯ�ڻָ���ԭ״������Χ�Ǻϵ������޷죬�㲻�ɸ�̾��߳����衣\n"NOR,
	]));
	set("exits", ([
		"out" : __DIR__"shishi1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3220);
	set("coor/y", -40);
	set("coor/z", 80);
	setup();
}

void init()
{
	add_action("do_tui", "tui");
}

int do_tui(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if (arg =="shibi")
	{
		message_vision(YEL "$N˫�ְ�ʯ������������ȥ����֨֨һ����ʯ�ڻ����ƿ���\n"NOR,me);
		set("exits/up", __DIR__"woshi");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

void close(object room)
{
	message("vision",HIY"ʯ���������˻������ָ���ԭ״��\n"NOR, room);
	room->delete("exits/up");
}
