// poison.h
// Last Modified by winder on Feb. 28 2001

void init()
{
//	add_action("do_tu", "tu");
	add_action("do_make", "make");
	add_action("do_dian", "dian");
}

int do_make(string arg)
{
	object fire, me = this_player();
	object obj=this_object();
     
	if(!arg || (arg!="huo yan" && arg != "huoyan" && arg != "huodui"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!objectp(fire = present("fire", me)) && (me->query("neili") < 500))
		return notify_fail("������û�л��֣���ô����\n");
	if(me->query_skill("poison", 1) < 60)
	{
		message_vision("$N���Ż��۽�$n��ȼ��ð��һ������Ķ��̣�\n",me,this_object());
		message_vision("$N����һ��������æ��$n����һ�ӣ�ԶԶ���˿�ȥ��\n",me,this_object());
//		this_object()->add_amount(-1);
		destruct(obj);
		return 1;
	}
	if(present("huo yan", environment(me)))
		return notify_fail("�����Ѿ��л����ˣ���Ҫ��ʲô��\n");
	if(!fire)
	{
		me->add("neili", -100);
		message_vision(HIR"\n$N�����³�һ�����̣�������$n"HIR"������һ��һ�ף����һ��ȼ��һ�����ܻ��棡\n\n"NOR, me, this_object());
	}
	else message_vision( HIR"\n$N������$n"HIR"�û��ֵ�ȼ��Ȼ�������ʹ��һ�ӣ�ȼ����һ�����ܻ��棡\n\n"NOR, me, this_object());    
	new("/d/xingxiu/npc/obj/huoyan")->move(environment(me));
//	this_object()->add_amount(-1);
	destruct(obj);
	return 1;	 
}
/*
int do_tu(string arg)
{
	string me, what;
	object ob;
	   
	if( !arg || sscanf(arg, "%s on %s", me, what)!=2 || !id(me) )
		return notify_fail("�����ʽ: tu <ҩ> on <����>��\n");

	ob = present(what, this_player());

	if( !ob ) return notify_fail("������û��" + what + "����������\n");
	if( !ob->query("weapon_prop")) return notify_fail("ֻ��Ϳ�������ϡ�\n");

	else return notify_fail("��Ҫ�Ƚ�ҩ�۵�ȼ���С�\n");

	return 0;	
}
*/
int do_dian(string arg)
{
	object me,ob,ob1;

	ob = this_object();
	me = this_player();
	if(!arg||arg!=ob->query("id"))
		return notify_fail("��Ҫ��ȼʲô������\n");

	if(!objectp(ob1 = present("fire", me)))
		return notify_fail("����Ҫ�Ҹ����֡�\n");

	message_vision("$N���Ż��۽�$n��ȼ��ð��һ������Ķ��̣�\n",me,ob);
	if(me->query_skill("poison", 1) > 79)
	{
		new(ob->query("drug2"))->move(me);			 
//		ob->add_amount(-1);
	destruct(ob);
		return 1;
	}
	else
	{
		message_vision("$N����һ��������æ��$n����һ�ӣ�ԶԶ���˿�ȥ��\n",me,ob);
//		ob->add_amount(-1);
	destruct(ob);
		return 1;
	}
}

int drink_drug(object ob)
{	
	string poison = ob->query("poison");
	this_player()->apply_condition(poison, (int)this_player()->query_condition(poison) + random(8));
	return 0;
}
 