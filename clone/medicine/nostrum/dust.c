// dust.c
#include <ansi.h>
inherit ITEM;
void setup()
{}
void create()
{
	set_name(HIC"��ʬ��"NOR, ({"dust"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���û�ʬ�𼣵Ļ�ʬ�ۣ�ֻҪһ����Ϳ��Ի�ȥ(dissolve)һ��ʬ�壡\n");
		set("value", 50);
	}
	set("pour_type", "1");
	setup();
}

void init()
{
	if( this_player()==environment() )
		add_action("do_dissolve", "dissolve");
}
								
int do_dissolve(string arg)
{
	object ob, me = this_player();

	if( !arg ) return notify_fail("��Ҫ�û�ʬ���ܽ�ʲô������\n");
	if(!present(this_object(), me)) return 0;
	if( me->is_busy() ) return notify_fail("����æ���������ء�\n");

	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("����û������������\n");
	if( !ob->is_corpse() )
		return notify_fail("��ʬ��ֻ�������ܽ�ʬ�塣\n");
	message_vision(
		"$N��ָ������һ�㻯ʬ����$n�ϣ�ֻ����һ�����͡��������\n"
		"һ�ɿ��µĶ����$nֻʣ��һ̲��ˮ��\n", me, ob);
	destruct(ob);
	return 1;
}

