// pill.c

inherit COMBINED_ITEM;

void init()
{
	add_action("do_eat", "eat");
	add_action("do_pour", "pour");
}

int do_eat(string arg)
{
	string what = query("cure");
	int howmuch = query("amount");

	if (!id(arg))
		return notify_fail("�����ʲô��\n");

	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ��" + this_object()->name() + "��\n");
	else {
		this_player()->receive_curing("qi", 50);
		message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", this_player());
		destruct(this_object());
		return 1;
	}
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg || sscanf(arg, "%s in %s", me, what)!=2 || !id(me) )
		return notify_fail("ָ���ʽ: pour <ҩ��> in <��Ʒ>\n");
	ob = present(what, this_player());
	if( !ob ) return notify_fail("������û�� " + what + " ����������\n");
	if( !what->query("pourable") )
	{
		write(this_object()->name() + "�ƺ����ܲ���ˮ����ġ�\n");
		return 1;
	}
	if( !ob->query("liquid/remaining") )
	{
		write(ob->name() + "��ʲôҲû�У���װЩˮ�Ʋ����ܻ���"+this_object()->name()+"��\n");
		return 1;
	}
// We let call other to call the "master copy" of the object in case the
// powder object got destructed after used up.
	f = (: call_other, base_name(this_object()), "effect_in_liquid" :);
	ob->set("liquid/drink_func", bind(f, ob));
	message_vision("$N��һ" +query("unit") + name() + "�ӽ�" + ob->name() + "��ҡ���˼��¡�\n", this_player());
	destruct(this_object());
	return 1;
}

