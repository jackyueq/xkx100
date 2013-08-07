// pilidan.c ������
#include <ansi.h>;
#include <command.h>;
inherit ITEM;
void create()
{
	set_name(HIC"������"NOR, ({"pilidan", "dan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����µ������ޱȵ���������\n");
		set("unit", "��");
		set("value", 100);
	}
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

	me = this_player();
	if( environment(me)->query("no_fight") )
		return notify_fail("��Ҫ���ƻ�����\n");
	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy()) return notify_fail("������æ����\n");

	tell_room(environment(me),me->query("name")+"�����͵�����һ����һ�����죬���ʲôҲ��������һƬ��������ɢ�ӿ���\n"NOR);

	inv = all_inventory(environment(me));
	for(i=0; i<sizeof(inv); i++)
	{
		ob=inv[i];
		ob->set_temp("no_follow",1);
		if( (ob->is_character()) && (!ob->is_corpse()) )
		{
			GO_CMD->do_flee(ob);
		}
	}

	destruct(this_object());
	return 1;
}
