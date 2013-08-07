// Room: /d/gaochang/mishi2.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>;
inherit ROOM;
int do_study(string arg);

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǹ�����µĵ������ҡ�������С��ȴҲ�������ȫ��ʯ��ʯ
�Σ�ʯ��ʯ���������ڷŵļ�������Ҳ����ʯ�Ƶġ������ƺ��ܾ���
ǰ����������ס�������е�ʯ��(table) ��ƽ����һ�鱡����ʯ�壬��
��������Щʲô��
LONG
	);
	set("had_sword", 1);
	set("exits", ([
		"south" : __DIR__"mishi",
	]) );
	set("item_desc", ([
		"table" : "����һ�����ʯ��ɵ�ʯ�����������Щ��ֵ�ͼ�Ρ�
���Ϸ���һ�ں�����������۵��ؽ�(zhongjian)��\n",
		"zhongjian": "����һ���������Ƶ����������������ʸ���ʯ���ϡ�\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36510);
	set("coor/y", 10110);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_study", "study");
	add_action("do_take", "take");
	add_action("do_take", "qu");
	add_action("do_take", "jian");
	add_action("do_take", "pick");
	add_action("do_zuan","zuan");
	add_action("do_zuan","enter");
}

int do_study(string arg)
{
	object me = this_player();

	if ( !arg || ( arg != "table" ) )
		return notify_fail("ʲô��\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	if((int)me->query("jing") < 30)
		return notify_fail("�����ھ����޷����У�\n");

	me->receive_damage("jing", 10);

	message_vision("$N��ר���ж�ʯ���ϵĹŹ�ͼ�Ρ�\n", me);
	if ( (int)me->query_skill("literate", 1) < 150)
	{
		me->improve_skill("literate", (int)(me->query("int")/3));
		write("�����ʯ����ĥ��һ�ض����ƺ��Զ���ʶ���е��ĵá�\n");
		me->set_temp("stone_learned",1);
	}
	if ( !me->query_temp("stone_learned") )
	{
		write("�����ʯ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
	}
	return 1;
}

int do_take(string arg)
{
	object sword, me=this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="zhongjian" )
	{
		if (!query("had_sword") || uptime() < 300)
			message_vision("$N����ȥȡ�����ŷ���ֻʣ�����ˣ���������ͱ�����ȡ����...��\n", me);
		else
		{
			if (me->query_str() < 30)
				return notify_fail("�������̫�أ�����˰��쾢�����ò�������\n");
			set("had_sword", 0);
			message_vision("$N����Ĵ�ʯ���ϼ���һ�ڽ�����\n", me);
			sword = new(WEAPON_DIR"treasure/xuantie-sword");
			if (sword->violate_unique())
			{
				destruct( sword );
				return notify_fail("������ȥȡ�����ŷ���ֻʣ�����ˣ���������ͱ�����ȡ����...��\n");
			} 
			sword->move(me);
message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"����һ������������\n"NOR, users());
			return 1;
		}
		return 1;
	}
	return 0;
}
int do_zuan(string arg)
{
	object me=this_player();
	
	if (!arg || arg!="table")
		return notify_fail("��Ҫ�굽����ȥ?\n");
	if (me->query_str()>30)
		return notify_fail("�������̫���겻�����ӵ��¡�\n");
	message_vision("$N����һ���굽����������ȥ��\n",me);
	me->move("d/gaochang/mishi3");
	message("vision",me->query("name")+"���������˽�����\n",environment(me),({me}));
	return 1;
}