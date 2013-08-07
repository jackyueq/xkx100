// /d/shenlong/xianfuju ���᷿(�ɸ���)
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
#include <room.h>
inherit ROOM;

void init()
{
	add_action("do_get", "get");
}

void create()
{
	set("short", "�ɸ���");
	set("long", @LONG
�����̵��ɸ��ӣ���˵���᷿��ȴҲʮ�ֿ��������Ž࣬���ϼ�
�ϰ����˽�����棬���������ֻ������ϱ��컪������Ȼ�е�ʹ��е�
��ͷ�����������ڴ���������˯����һ����
LONG
	);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_steal", 1);
	set("exits", ([
		"north" : __DIR__"shibanlu",
	]));
	set("no_clean_up", 0);

	setup();
}

int do_get(string arg)
{
	object obj;

	if( arg && objectp(obj = present(arg, environment(this_player()))) &&
		obj->is_character() )
	{
		write("�㲻�ܰᶯ��ҵ����塣\n");
		return 1;
	}
	else
		return 0;
}
/*
int valid_leave(object me, string dir)
{
	object room;

	if ( !::valid_leave(me, dir) )
		return 0;

	if(!(room = find_object(__FILE__)) )
		room = load_object(__FILE__);
	if(objectp(room))
	{
		room->add_temp("person_inside", -1);
		if ((int)room->add_temp("person_inside", -1) <= 0)
			room->delete_temp("person_inside");
	}

	return 1;
}
*/
