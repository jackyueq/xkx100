// Last Modified by Winder on May. 15 2001
// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	if (!query("decay") && userp(environment()))
	{
		set("decay", 1);
		remove_call_out("decay");
		call_out("decay", 280);
	}
}

int do_eat(string arg)
{
	if( !living(this_player()) || this_player()->query_temp("noliving") )
		return 1;
	if( this_player()->query("jing")<0 || this_player()->query("qi")<0 )
		return notify_fail("��̫���ˣ�ʵ��û������ʲô�ˡ�\n");
	if( !this_object()->id(arg) ) return 0;
	if( !present(this_object(), this_player()))
		return notify_fail("��Ҫ��ʲô������\n");
	if( this_player()->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if( !query("food_remaining") )
		return notify_fail( name() + "�Ѿ�ûʲô�óԵ��ˡ�\n");
	if( (int)this_player()->query("food") >=
		(int)this_player()->max_food_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");

	this_player()->add("food", query("food_supply"));
	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	// This allows customization of drinking effect.
	if( query("eat_func") ) return 1;

	set("value", 0);
	add("food_remaining", -1);
	if( !query("food_remaining") )
	{
		message_vision("$N��ʣ�µ�"+name()+"�Եøɸɾ�����\n",this_player());
		if( !this_object()->finish_eat() ) destruct(this_object());
	} else message_vision("$N����" + name()+"ҧ�˼��ڡ�\n", this_player());
//	this_player()->start_busy(1);
	return 1;
}

void decay()
{
	object me = this_object(), ob = environment();
	if (!me || !ob) return;
	switch(add("decay", 1))
	{
		case 2:
			set_temp("apply/long",({query("long")+"���ǿ��������Ǻ����ʡ�\n"}));
			tell_object(ob, me->name()+"����ɫ��Щ�����ˡ�\n");
			break;
		case 3:
			set_temp("apply/long", ({query("long")+"��������ɢ����һ�����ŵ�ζ����\n"}));
			tell_object(ob,me->name()+"ɢ����һ�����ŵ�ζ����\n");
			break;
		case 4:
			set_temp("apply/long",({query("long")+"������Щ�����ˡ�\n"}));
			tell_object(ob,me->name()+"��Щ�����ˣ������̱ǵ�ζ����\n");
			break;
		default:
			tell_object(ob,me->name()+"�������õ��ˡ�\n");
			destruct(this_object());
			return;
	}
	remove_call_out("decay");
	call_out("decay", 150);
}
