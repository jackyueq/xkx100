/*


��־��(Shen zhifan)����
��־̹(Wang zhidan)���
��־��(Cui zhifang)����
��־��(Zhao zhijing)��Ȩ
��־��(Chen zhiyi)���
��־��(Li zhichang)����
��־ƽ(Yin zhiping)ҡ��

��־�����𴦻������йء�job������Ϣ��
�𴦻����˵�ͷ��
�𴦻�˵������ȥ��У����־���Ƕ��ú���ϰһ�¡��������!


��־ƽ����һ�������������ջص������Ҳ�ָ�������

*/
// qixing.c
#include <ansi.h>;
int main(object me, string arg)
{
	string msg, enemy, ob1, ob2, ob3, ob4, ob5, ob6;
	string myname=me->query("name");
	object en, obj1, obj2, obj3, obj4, obj5, obj6, *obs;
	int i, j, power;
	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");
	if( !arg )
	{
		return notify_fail("��������������ָ���������ѺͶ��֡�\n");
	}
	if(sscanf(arg, "%s %s %s %s %s %s %s",enemy,ob1,ob2,ob3,ob4,ob5,ob6)!=7)
	{
		return notify_fail("ָ���ʽ��qixing ���� ����1 ����2 ����3 ����4 ����5 ����6\n");
	}

	if(!objectp( en= present(enemy, environment(me))))
		return notify_fail("û�е��˰���\n");
	if(!en->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");
	if( en->is_fighting() )
		return notify_fail("�˼��Ѿ���ս�����ˣ����벼��\n");
	if( !living(en) || en->query_temp("noliving") )
		return notify_fail(en->name()+"���ѵ����ˣ����õ���Χ����\n");
	if((int)en->query("age") <= 15 && userp(en))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱɡ�\n");
	if(en==me) return notify_fail("�ɵ��Լ�������ô�벻����\n");

	if(!objectp( obj1 = present(ob1, environment(me))))
		return notify_fail("���������ûָ���԰ɣ�\n");
	if(!objectp( obj2 = present(ob2, environment(me))))
		return notify_fail("���������ûָ���԰ɣ�\n");
	if(!objectp( obj3 = present(ob3, environment(me))))
		return notify_fail("���������ûָ���԰ɣ�\n");
	if(!objectp( obj4 = present(ob4, environment(me))))
		return notify_fail("���������ûָ���԰ɣ�\n");
	if(!objectp( obj5 = present(ob5, environment(me))))
		return notify_fail("���������ûָ���԰ɣ�\n");
	if(!objectp( obj6 = present(ob6, environment(me))))
		return notify_fail("���������ûָ���԰ɣ�\n");
	if(en==obj1 || en==obj2 || en==obj3 || en==obj4 || en==obj5 || en==obj6 || en==me || obj1==obj2 || obj1==obj3 || obj1==obj4 || obj1==obj5 || obj1==obj6 || obj1==me || obj2==obj3 || obj2==obj4 || obj2==obj5 || obj2==obj6 || obj2==me || obj3==obj4 || obj3==obj5 || obj3==obj6 || obj3==me || obj4==obj5 || obj4==obj6 || obj4==me || obj5==obj6 || obj5==me || obj6==me)
		return notify_fail("���а��費�ԡ�\n");
	me->dismiss_team();
	me->set_leader();
	me->add_team_member(obj1);
	me->add_team_member(obj2);
	me->add_team_member(obj3);
	me->add_team_member(obj4);
	me->add_team_member(obj5);
	me->add_team_member(obj6);

	if(pointerp(obs=me->query_team()) )
	{
		for(i=0;i<sizeof(obs);i++)
		{
			if(!obs[i]->is_character() )
return notify_fail(obs[i]->query("name")+"�������\n");
			if( obs[i]->is_fighting() )
return notify_fail(obs[i]->query("name")+"����ս�����ˡ�\n");
			if( !living(obs[i]) || obs[i]->query_temp("noliving") )
return notify_fail(obs[i]->name()+"�ѵ��ڵ����ˣ��޷�׷���㡣\n");
			if((int)obs[i]->query("age") <= 15 && userp(obs[i]))
return notify_fail(obs[i]->query("name")+"�˼һ�С�������ɡ�\n");
			if((int)obs[i]->query_skill("array",1) <= 50 ||
			  (int)obs[i]->query_skill("xiantian-qigong",1) <= 50 ||
			  (int)obs[i]->query_skill("quanzhen-jian",1) <= 50)
return notify_fail(obs[i]->query("name")+"�ļ��ܲ��㲼��\n");
		}

		if(sizeof(obs) != 7)
			return notify_fail("�����������㡣\n");

	}

	for(i=0;i<sizeof(obs);i++)
	{
		if(obs[i] != me)
			message_vision(myname+ "����"+obs[i]->query("name")+"������׼����\n",me);
	}
	message_vision(myname+ "���������������˵�����ã�ʱ���ѵ������ڿ�ʼ������������󡹣�\n",me);
	message_vision(myname+ "ͻȻ�����ƶ���������ȫ�������ռλ�ã�������ˣ��ұ����ˣ����ǰڵġ���������󷨡�\n",me);
	remove_call_out("do_qixing");
	call_out("do_qixing", 1, me, en);
	return 1;
}
int do_qixing(object me, object en)
{
	object *obs, weapon, enweapon;
	int i, j, power;
	string *where = ({
		"����",
		"���",
		"����",
		"��Ȩ",
		"���",
		"����",
		"ҡ��"
	});

	if(pointerp(obs=me->query_team()) )
	switch (random (4))
	{
		case 0:
message_vision("����������ƺ��ǰ�������������ӣ������ۻ����ң������ʧ��\n",me);
			break;
		case 1:
message_vision("������󷨹����ƶ����������಻����˲�佫����Χ�����ġ�\n",me);
			break;
		case 2:
message_vision("�������Խ��ԽС�����ν������˳�һ��������룬��������Ϣ֮�С�\n",me);
			break;
		case 3:
message_vision("ֻ��������󰵺����а���֮�������˲������������ϵ������޷죬����֮������̾Ϊ��ֹ��\n",me);
			break;
	}
	for(i=0;i<sizeof(obs);i++)
	{
		weapon = obs[i]->query_temp("weapon");
		power = obs[i]->query_skill("force",1)/10;
	        obs[i]->add_temp("apply/attack", power);
	        obs[i]->add_temp("apply/damage", power);

		switch (random(4))
		{
			case 0:
message_vision(where[i]+"λ�ϵ�"+obs[i]->query("name")+ "������������񹦣���Ȼ����������������ǰһ��, ����", me);
				break;
			case 1:
message_vision(where[i]+"λ�ϵ�"+obs[i]->query("name")+ "ͦ������������������ƮƮ��������硣ֻ��", me);
				break;
			default:
		}
		COMBAT_D->do_attack(obs[i],en,weapon);
		if(en->query("qi")*2 <= en->query("max_qi"))
		{
			remove_call_out("do_end");
			call_out("do_end", 1, me, en, 0);
			return 1;
		}
		obs[i]->add_temp("apply/attack", -power);
		obs[i]->add_temp("apply/damage", -power);
	}
	j = random(7);
	enweapon = en->query_temp("weapon");
	COMBAT_D->do_attack(en,obs[j], enweapon);
	if(obs[j]->query("qi")*2 <= obs[j]->query("max_qi"))
	{
message_vision(HIR+obs[j]->query("name")+"һ��ſ�ڵ��ϣ�ˤ��������\n"NOR,me);
		remove_call_out("do_end");
		call_out("do_end", 1, me, en, 1);
		return 1;
	}
	if(obs[j]->query("qi")*3 <= obs[j]->query("max_qi")*2)
	{
message_vision(obs[j]->query("name")+ "������һ�������ˤ��������\n",me);
	}
	else if(obs[j]->query("qi")*5 <= obs[j]->query("max_qi")*4)
message_vision(obs[j]->query("name")+"����û��˼��Σ�������վ���˲��ӡ�\n",me);

	remove_call_out("do_qixing");
	call_out("do_qixing", 1, me, en);
	return 1;
}
int do_end(object me, object en, int result)
{
	if( result == 1)
	{
		if(en->query_temp("pre_qixing") && !wizardp(en))
		{
			en->set("qixing", 1);
		}
		en->delete_temp("pre_qixing");
		message_vision(HIR"\n�������"+en->query("name")+"�����ˡ�\n"NOR,me);
	}
	else
	{
		en->delete_temp("pre_qixing");
message_vision(HIR"\n$NЦ��Ц�����������Ϊȫ�����֮����\n"NOR,me);
	}
	remove_call_out("do_back");
	call_out("do_back", 1, me);
	return 1;
}
int do_back(object me)
{
	object *obs, weapon;
	int i;

	if(pointerp(obs=me->query_team()) )
	{
		for(i=0;i<sizeof(obs);i++)
		{
			if (objectp(weapon = obs[i]->query_temp("weapon"))
				&& (string)weapon->query("skill_type")=="sword")
message_vision("$N�������һ�ݣ�ʹһ�С��ս�ʽ������������һ��������������һ�����˳���������󡹡�\n", obs[i]);
			else
message_vision("$N�������һ�ݣ�ʹһ�С���ɽʽ������ȭ����һȦ������������һ�����˳���������󡹡�\n", obs[i]);

message_vision("$N���˸�鮵���ƶ���ȸ����ˣ�˵��Ϳ첽�뿪�ˡ�\n", obs[i]);
		}
	}
	me->dismiss_team();
}

