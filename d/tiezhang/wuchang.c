// Room: /d/tiezhang/wuchang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>

inherit ROOM;
//void init();
//int do_chazhi();

void create()
{
        set("short",HIC"�䳡"NOR);
	set("long", @LONG
����һƬƽ�أ�����Щ�������ߡ����ư��������Ȼ����������
LONG
	);
        set("exits", ([ 
		"west" : __DIR__"zoulang4",
	]));
	set("objects",([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -2010);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_chazhi", "chazhi");
}


int do_chazhi(string arg)
{       
        mapping fam;
	object me;
        me = this_player();

	if (!living(me)) return 0;
	if ( !living(this_player()) || arg != "huo" )
	{
		write("�������Ķ���ѽ��\n");
		return 1;
	}
	if (!(fam = me->query("family")) || fam["family_name"] != "���ư�")
		return notify_fail("��Ǳ�����ӣ������ڴ�������\n");

	if ( (int)me->query_skill("strike", 1) > 100)
		return notify_fail("�㽫˫�ֲ������У�������ɳ���¶ȶ�����˵̫�ͣ��Ѻ��������ˡ�\n");
 
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write("�����һ������ֱ�������������ѵ���\n");
		me->unconcious();
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("strike", me->query("int"));
	message_vision("$N��˫�ֲ�����е���ɳ�\n", me);
	write("���ȵ���ɳ�����˫���̵�ͨ�죬�����˫�ֱ��ǿ׳������\n");
	return 1;
}
