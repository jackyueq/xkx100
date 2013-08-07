// jingzuo.c
// Dec.11 1997 by Venus

void wakeup(object me, object where);
void del_jingzuoed(object me);

int main(object me, string arg)
{
	mapping fam;
	object where = environment(me);

	seteuid(getuid());

	if ((!(fam = me->query("family")) || fam["family_name"] != "������"))
		return notify_fail("ֻ�ж����ɲ��ܾ�����\n");
	if (where->query("no_sleep_room"))
		return notify_fail("����̫���ӣ���û�����ľ�����\n");
	if (!where->query("sleep_room"))
		return notify_fail("����̫���ӣ���û�����ľ�����\n");
	if (me->query("eff_jing")<50)
		return notify_fail("������̫�أ�û��������\n");
	if (me->is_busy())
		return notify_fail("����æ���أ�\n");
	if (me->is_fighting())
		return notify_fail("ս�����뾲�����㲻Ҫ������\n");
	me->save();
	if (me->query("betrayer") > 0)
		return notify_fail("������ͽ�����ϰ���Ҷ��Ҿ����ķ���\n");
	if (me->query("mud_age") - me->query("jingzuo_time") < 180)
		return notify_fail("��ղž�����������ͷ��һƬ�հס�\n");
	if (me->query_skill("mahayana",1) < 40)
		return notify_fail("��Ĵ�˰����͹���̫ǳ���ˣ�û�����ľ�����\n");
	if (me->query_skill("linji-zhuang",1) < 40)
		return notify_fail("����ټ�ׯʵ��̫���ˣ�û�����ľ�����\n");
	if (where->query("sleep_room"))
	{
		write("����������ϥһ������ʼ������\n");
		write("��һ��������������⣬����������\n");
		me->set_temp("block_msg/all",1);
		message_vision("$Nһ���������ڴ��ϣ���Ŀ������Ĵ�����\n",me);
		where->add_temp("jingzuo_person", 1);

		me->set("no_get", 1);
		me->set("no_get_from", 1);
//		me->disable_player("<������>");
		me->set_temp("noliving/jingzuo", 1);
		call_out("wakeup",random(45)+1 , me, where);

		return 1;
	} else return notify_fail("����̫���ӣ���û�����ľ�����\n");
}

void wakeup(object me,object where)
{
	int skillslvl,addp,addc,exppot,intpot;

	skillslvl = (int) me->query_skill("mahayana",1);
	exppot = (int)(me->query("combat_exp")/20000);
	intpot = (int)(me->query_int()/10);
	addp = (int)(random(skillslvl)/5+intpot);
	addc = (int)(random(skillslvl)/3+exppot);
	if (addp > 200) addp = random(200);
	if (addc > 400) addc = random(400);
	me->receive_damage("jing", 15);
	me->receive_wound("jing", 3);
	me->add("potential",addp);
	me->add("combat_exp",addc);
//	me->enable_player();
	me->delete_temp("noliving");
	message_vision("$N������ϣ��������ۣ���������һ������\n",me);
	me->set_temp("block_msg/all", 0);
	me->set("jingzuo_time", me->query("mud_age"));
//	write("�㾲����ϣ����۵ĸо���\n");
        tell_object(me, "�㾲����ϣ����۵ĸо���\n");
	where->add_temp("jingzuo_person", -1);
	me->delete("no_get");
	me->delete("no_get_from");
	return;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : jingzuo <��������>

    ���ָ���Ƕ����ɵ������Ծ����޵�������.

HELP
        );
        return 1;
}