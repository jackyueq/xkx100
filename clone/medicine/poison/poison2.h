// poison2.h
// Last Modified by winder on Feb. 28 2001

int do_tu(string arg)
{
	string what, my;
	object ob, me = this_player();
	int i;
	i = (me->query_skill("poison")/10)+3+(me->query_skill("five-poison")/10)+3;

	if( !arg || sscanf(arg, "%s on %s", my, what)!=2 || !id(my) )
		return notify_fail("�����ʽ: tu <ҩ> on <����>��\n");

	ob = present(what, me);
	if( !ob ) return notify_fail("������û��" + what + "����������\n");
	if( !ob->query("weapon_prop") )
		return notify_fail("ֻ��Ϳ�������ϡ�\n");
	
	ob->set("poisoned", query("pour_type"));
	ob->set("poison_number", ob->query("poison_number")+i);

	ob->set_temp("apply/long", ({ob->query("long")+"������ȥ"+query("drug_color")+"�������Ǳ�ι�˾綾��\n"}));
	message_vision("$N������ȥ����"+query("name")+"Ϳ��$n�ϡ�\n", me, ob);
	me->start_busy(2);
	add_amount(-1);
	return 1;
}

void destruct(object ob)
{
	message_vision("$N������ȼ�����ˡ�\n",ob);
	ob->add_amount(-1);
	return;
}
