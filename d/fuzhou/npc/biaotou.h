#define lay_exp 20
#define lay_pot 5
#define price_exp 220
#define price_pot 50
int ask_jiaobiao()
{
	object me = this_player();
	object cart,biaotou,money,ob = this_object();
	int i, give_exp, give_pot,give_score;

	if (me->query_temp("fuwei_destm") != ob->query("id"))
	{
		message_vision(HIR"$N��$n����������ˣ�����ˣ�����ô�Ѹ�"+me->query_temp("fuwei_dest")+"�־ֵ��ڳ��͵��������أ���\n"NOR,ob,me);
		return 1;
	}
	if (! objectp(cart = present("cart", environment(me))))
	{
		message_vision("$N��$n�������ڳ��أ�����������кü�������������\n",ob,me);
		return 1;
	}
	if (! objectp(biaotou = present("biao tou", environment(me))))
	{
		message_vision("$N��$n�����������ͷ�أ�·�϶�ʧ���֣��㻹�������ң���\n",ob,me);
		return 1;
	}
	if (cart->query("guarded") != me->query("id"))
	{
		message_vision("$N���˿��ڳ�����$n˵���������ڳ�������Ѻ�ġ�����ڳ�����ȥ�ˣ���\n",ob,me);
		return 1;
	}
	if (biaotou->query("leader_name") != me->query("id"))
	{
		message_vision("$Nָ��$n˵�������Ҳ��Ǻ���һ·�ģ��Ҳ���ʶ������\n",biaotou, me);
		return 1;
	}
	tell_object(me,HIW+ob->query("name")+"Ц������ϲ��ɹ����ڳ��͵�Ŀ�ĵأ��������������\n\n"NOR);

        message("channel:chat", HIM"��ҥ�ԡ���˵"+cart->query("guardby")+"�ɹ����ڳ��͵�Ŀ�ĵ��ˣ�\n"NOR,users());

	i = 0;
	give_exp = lay_exp * biaotou->query("total_steps");
	give_pot = lay_pot * biaotou->query("total_steps");
	while ( i < biaotou->query("combat_num") )
	{
		give_exp += (price_exp/2 + random(price_exp/2));
		give_pot += (price_pot/2 + random(price_pot/2));
		i++;
	}
        
	message_vision(YEL"$N������һ�����������������ڵ��ˡ��ҿɺͻ���ǺȾ�ȥ�ˡ���\n"NOR,biaotou);
	message_vision(YEL"$N��"+me->query_temp("fuwei_dest")+"�־ֵ���������һ����Ի����������ع���һӵ����ȥ�ˡ�\n"NOR,biaotou);
	message_vision(HIC"�ڳ���"+me->query_temp("fuwei_dest")+"�־ֵĻ�����ƽ��˿ⷿ��\n\n"NOR,biaotou);
	destruct(biaotou);
	destruct(cart);

	if(give_exp > 5000) give_exp = 4000 + random(1000);
	if(give_pot > 1000 ) give_pot = 900 + random(100);
        give_score = 800 + random(400);
	money=new("/clone/money/gold");
	money->set_amount(40);
	money->move(me);

	tell_object(me, sprintf(HIR+ob->query("name")+"��"+me->query("name")+"����������㱻�����ˣ��õ�%s�㾭���%s��Ǳ�ܺ�%s�㽭���������ھַ�������ʮ���ƽ������н��Ͳ������Ѻ�𡣡�\n"NOR, chinese_number(give_exp),chinese_number(give_pot),chinese_number(give_score) ) + NOR);
	message_vision("$N��$nһЩ"YEL"�ƽ�"NOR"��\n"NOR, ob, me);
	log_file("mission/ms_biaoche",sprintf("%20s�������ڳ����񣬵õ���%4i��EXP��%4i��Ǳ�ܡ�\n",
       me->query("name")+"("+getuid(me)+")",give_exp,give_pot));
	me->add("combat_exp",give_exp);
	me->add("potential",give_pot);
  me->add("score",give_score);
	me->add("baobiao",1);
	ob->set_temp("prize_reason","����");
	ob->set_temp("can_give_prize",1);
	ob->set_temp("prize_exp",give_exp);
	ob->set_temp("prize_pot",give_pot);
	me->delete_temp("fuwei_destm");
	me->delete_temp("fuwei_dest");

	return 1;
}

