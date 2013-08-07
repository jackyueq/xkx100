// tea.c ���Ų�

#include <ansi.h>
#include <command.h>
#include <login.h>
inherit ITEM;

int mpc_effect(object me);
void create()
{
	set_name(GRN "���Ų�" NOR,({GRN "mengpo tea" NOR, "cha", "tea"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
 		set("long", GRN"����Ǵ�˵�����������Ų衣ÿ�������Ͷ̥ת��֮ǰ����Ҫ����һ�����Ų裬��˵�������������������һ��һ�оͶ������øɸɾ������ʹ������������һ�й�ϵ��\n");
		set("unit", "��");
	}
	set("pour_type", "1");
	setup();
}

void init()
{
	add_action("do_drink", "drink");
	add_action("do_drink", "he");
}

int do_drink(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
//if a ghost
	if( !me->is_ghost() )
	{
		write("��������˲��ܺ������......\n\n\nҪ��������һ�Σ�......\n");
		return 1;
	}
	message_vision("$N��ԥ��һ��������ǰ�һ�����Ų������ȥ��\n\n\n\n",me);
	remove_call_out("mpc_effect");
	call_out("mpc_effect", 5, me);
	return 1;
}
int mpc_effect(object me)
{     
	string stroom;
	stroom = me->query("startroom");
	if( stroom[0..7] != "/d/death"  )
	if ( me->query("eff_jing") < 5 && me->query("eff_qi") < 5 )
	if( me->query("dietime") && time()-me->query("dietime") < 600 )
	{
		me->set("eff_qi",(int)me->query("max_qi"));
		me->set("qi",(int)me->query("max_qi"));
		me->set("eff_jing",(int)me->query("max_jing"));
		me->set("jing",(int)me->query("max_jing"));
	}
	message_vision(BLU "$N����һ��ͷ��Ŀѣ����ǰ�����������ƺ�������������..........\n\n\n"NOR, me);
	tell_object(me,BLU "���ǰ�...................\n\n\n\n" NOR);
	destruct(this_object());
	return 1;
}

