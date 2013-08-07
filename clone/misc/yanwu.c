// Yanwu.c ����
#include <command.h>
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name(HIM"����"NOR, ({ "yanwu"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����Ƶ���������������(apply)��������\n");
		set("unit","Щ");
		set("base_unit", "��");
		set("value", 1000);
		set("no_drop", RED"�ѵ��������������\n"NOR);
	}
	set_amount(1);
}

void init()
{
	add_action("do_apply","apply");
}
int do_apply(string arg)
{
	object me,ob;
	object *inv;
	int i;

	if (!id(arg))
		return 0;

	me=this_player();
	if (!present(this_object(),this_player())) return 0;
	if (me->is_busy())
		return notify_fail("������æ���ء�\n");

	inv = all_inventory(environment(me));
	for(i=0; i<sizeof(inv); i++)
	{
		ob=inv[i];
		if (ob==me)
		continue;
		if( (ob->is_character()) && (!ob->is_corpse()) )
		{
			if (!ob->is_busy())
			ob->start_busy(1);
		}
	}
	me->set_temp("no_follow",1);
	tell_room(environment(me),HIM"����ͻȻ�ڳ�һ���Һ�ɫ���������ʲôҲ��
�������������֮�С�\n"NOR);

	GO_CMD->do_flee(me);
	this_object()->add_amount(-1);
	return 1;
}
void owner_is_killed()
{
	object me = this_player();
	write(HIM"ֻ��һ���Һ�ɫ����������...ʬ����ʲô������ʧ�ˡ�\n"NOR);
	destruct(this_object());
}
int query_autoload()
{
	return 1;
}
