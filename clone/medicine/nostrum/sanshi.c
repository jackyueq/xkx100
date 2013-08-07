// sanshi.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"��ʬ����"NOR, ({"sanshinao shendan", "sanshi dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", 
"һ�����ɫ�ĵ�ҩ�������Ӳ���Ѱ����Ʒ����ֻ���Գ˱������²�֪ʱ
ι(wei)���˼ҳԡ�\n");
		set("unit", "��");
		set("value", 20000);
	}
	set("pour_type", "1");
	setup();
}

int init()
{
	add_action("do_wei", "wei");
}

int do_wei(string arg)
{
	object me = this_player(), ob = this_object(), who;

	if (!present(ob, me)) return 0;
	if (me->query("id") != ob->query("owner"))
		return notify_fail("�ⲻ�������ĵ�����ιҲû�á�\n");
	if(!arg) return notify_fail("��Ҫ��˭ι��ʬ���񵤣�\n");
	if(!objectp(who = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if(living(who) && !who->query_temp("noliving") )
		return notify_fail("�˼���֪�о��ģ�˭�ϳ���ĳ�ҩ��\n");
	message_vision("$N�˿�$n���죬��"+ob->query("name")+"����$n���\n", me, who);
	who->set("sanshi", me->query("id"));
	destruct(this_object());
	return 1;
}

