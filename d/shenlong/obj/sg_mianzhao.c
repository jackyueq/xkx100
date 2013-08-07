// sg_mianzhao.c ����
// Last Modified by winder on Jul. 12 2002

#include <armor.h>
inherit HEAD;

#define SGCANGKU "/d/shenlong/cangku"

void do_copy(object, object);
void do_flee(object);
int eff_fam(object);

#include "/d/shenlong/masters.h"
#include "/d/shenlong/safeplaces.h"

void create()
{
	set_name("����", ({ "mianzhao", "mask" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǹ����������еĺڲ�ͷ�ף��ܰ������Դ���������ֻ¶�������۾���\n��ÿ��Ϊ�����̰참�������ʬ����д��(sign)������������ɱ������\n");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("value", 10);
		set("no_get", "�������������뿪�Ƕ���\n");
		set("no_drop", "�������������뿪�㡣\n");
	}
	setup();
}

void init()
{
	add_action("do_wear", "wear");
	add_action("do_remove", "remove");
	add_action("do_sign", "sign");
	add_action("do_forcejoin", "forcejoin");
	add_action("do_search", "search");
	add_action("do_open", "open");
	add_action("do_job", "job");
	add_action("do_jobtime", "jobtime");
}

int do_wear(string arg)
{
	if (!arg || (arg != "mianzhao" && arg != "mask") ) return 0;

	this_player()->set_temp("apply/name",  ({"������"}));
	this_player()->set_temp("apply/short", ({"������(Mengmian ren)"}));
	this_player()->set_temp("apply/long",  ({"һ���ڲ����棬��������ļһ\n"}));

	return 0;
}

int do_remove(string arg)
{
	if (!arg || (arg != "mianzhao" && arg != "mask") ) return 0;

	this_player()->delete_temp("apply/name");
	this_player()->delete_temp("apply/short");
	this_player()->delete_temp("apply/long");

	return 0;
}

int do_sign(string arg)
{
	object obj;
	object me = this_player();
	string v_id, v_name;
	mapping pkjob;
	int mygain;

	if( !me->query("sg/spy") && !mapp(me->query("sgjob_join")) )
		return 0;

	if( !arg || arg != "corpse" || !(obj = present(arg, environment(me))) )
		return 0;

	if( obj->query("my_killer") != me->query("id") )
		return 0;

	v_name = obj->query("victim_name");
	if( obj->query("signed") ||
		(v_name != (string)me->query("sgjob/victim_name") &&
		v_name != (string)me->query("sgjob_join/victim_name")) )
		return 0;

	if( v_id = me->query("sgjob_join/victim_id") )
	{
		me->delete("sgjob_join");
		me->set("sg_ok/join", 1);
	}
	else
	{
		v_id = me->query("sgjob/victim_id");
		me->delete("sgjob");
		me->set("sg_ok/pk", 1);
		mygain = (int)obj->query("combat_exp") / 1000;
		me->add("sg/exp", 100 + mygain * (mygain/2000 + 1)/40);
		if( mygain > 1000 ) mygain = 1000;
		me->add("combat_exp", mygain);
	}

	obj->set("signed", 1);
	log_file("test/ShenlongPker", sprintf("%s��%sʱɱ��%s(%s).\n", me->query("name"), ctime(time()), v_name, v_id));

	me->set("sg_victim/" + time(), v_id);
	tell_room(environment(me), "��������ʬ����д�¡�����������ɱ�����������֡�", ({me}));
	tell_object(me, "����ʬ����д�¡�����������ɱ�����������֡�\n");
	return 1;
}

int do_forcejoin(string arg)
{
	object *inv, target, me = this_player();
	int fp, dp;
	mixed busy;

	if( !me->query("sg/spy") )
		return notify_fail("�㲻�������̵��ˣ���ʲô����\n");
	if( me->query("sg_ok/forcejoin") )
		return notify_fail("���Ȼ�ȥ�����ɡ�\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ��ǿ�ȵĵط���\n");
	if ( busy = me->query_busy() )
	{
		if (intp(busy)) me->start_busy(busy+1);
			return notify_fail("��������æ�ţ�\n");
	}
	if( !arg || !(target = present(arg, environment(me))) )
		return notify_fail("��Ҫ��˭�������̣�\n");

	if( me->query("sgjob/forcejoin") != target->query("id") )
		return notify_fail("���Ҵ����ˡ�\n");

	if( target->query("sg/spy") ||
		target->query("family/family_name") == "������" )
		return notify_fail(target->name()+ "�Ѿ����������ˣ������ٷ����ˡ�\n");
	if( !living(target) )
		return notify_fail("�������ٱ�"+target->name()+"Ҳû���á�\n");
	if( me->query_temp("forcejoining") )
		return notify_fail("���Ѿ��ڱ������ˡ�\n");
	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 40 ||
		(int)me->query("jingli")*100/(int)me->query("max_jingli") < 40)
		return notify_fail("��̫���ˣ���Ϣһ�����Ȱ�ɡ�\n");

	me->receive_damage("jing", 60);
	me->receive_damage("qi", 60);

	message_vision("\n$N��$n�����ȵ���" + RANK_D->query_rude(target) + "����������̣������ɱ���ۣ�����\n", me, target);

	inv = all_inventory(environment(target));
	for(int i = 0; i < sizeof(inv); i++)
	{
		if( living(inv[i]) && inv[i] != me && inv[i] != target &&
			!inv[i]->query("sg/spy") &&
			(string)inv[i]->query("family/family_name") &&
			(string)inv[i]->query("family/family_name") == (string)target->query("family/family_name") ) inv[i]->kill_ob(me);
	}
	fp = (int)me->query_skill("force") * 3 +
		(int)me->query_skill("parry") * 2 +
		(int)me->query_skill("dodge");
	fp *= (int)me->query("sg/exp")  +
		(int)me->query("combat_exp") / 1000 + 1;
	dp = (int)target->query("jing") + (int)target->query("max_jing") +
		(int)target->query("qi") + (int)target->query("max_qi") +
		(int)target->query("jingli") * 2 +
		(int)target->query("neili") * 3;
	if ( dp < 1 ) dp = 1;
	dp *= (int)target->query("combat_exp") / 1000 + 1;

	me->set_temp("forcejoining",  target->query("id"));
	call_out("complete_forcejoin", 8+random(10), me, target, fp, dp);
	return 1;
}

private void complete_forcejoin(object me, object target, int fp, int dp)
{
	object ob, *inv;
	int t_shen, t_exp, bonus = 2, times, record;

	if( !present(target, environment(me)) ) return ;
	if( !objectp(me) )  return;
	me->delete_temp("forcejoining");
	target->add_temp("forcetimes", 1);

	if( !objectp(target) ) return;
	if( environment(target) != environment(me) ) return;

	if( !living(target) )
	{
		tell_object(me, "�������ٱ�Ҳû���á�\n");
		return;
	}
	t_shen = (int)target->query("shen");
	while ( t_shen > 10 )
	{
		bonus += 1;
		t_shen = t_shen/16;
	}
	if( member_array(target->query("id"), masters) != -1 ) bonus *=30;
	dp *= bonus;
	dp *= 4 * eff_fam(target);
	if( target->query_condition("embedded") ) dp /= 2;
	if( (int)target->query_condition("snake_poison") > 0 ) dp /= 2;
	if( (int)target->query_condition("insect_poison") > 0 ) dp /= 2;
	if( (int)target->query_condition("xx_poison") > 0 ) dp /= 2;
	if( (int)target->query_temp("hgmz") > 0 ) dp /= 4;
	if( (int)target->query_condition("hyz_damage") > 0 ) dp /= 2;
	if( (int)target->query_condition("hsf_poison") > 0 ) dp /= 2;
	if( dp < 1 ) dp = 1;
	if( random(fp+dp)  > dp )
	{
		message_vision("$N����������ֻ�ô�Ӧ$n���������̡�\n", target, me);
		if( member_array(target->query("id"), masters) != -1 )
			bonus += 100;
		bonus += (int)me->query("sg/exp") * 2000 / (int)me->query("combat_exp");
		bonus *= eff_fam(target);
		if(bonus>300)bonus = 300;

		record = bonus/3 + random(bonus/3);
		me->add("combat_exp", record);
		me->add("sg/exp", 1);
		me->add("shen", -(int)target->query("combat_exp")/100);

		log_file("test/ForceJoin", sprintf("%s��%sʱ��%s�������̻��%s�����\n", me->query("name"), ctime(time()), target->query("name"), chinese_number(record)));

		bonus /= 4;
		me->add("potential", bonus/3 + random(bonus/3));
		if( me->query("potential") > me->query("max_potential") )
		me->set("potential", me->query("max_potential"));

		me->delete("sgjob");
		me->set("sg_ok/forcejoin", 1);

		inv = all_inventory(target);
		for(int i = 0; i < sizeof(inv); i++)
			if( inv[i]->is_unique() ||
				inv[i]->query("weapon_prop/damage") > 100 ||
				inv[i]->query("armor_prop/armor") > 100 )
			{
				inv[i]->move(me);
				message_vision("$N��" + inv[i]->name() + "˫�ַ��ϵݸ�$n��\n", target, me);
			}
		target->set("sg/spy", 1);
		target->delete_temp("forcetimes");
		target->set("attitude", "heroism");
		target->set("shen_type", -1);
		target->remove_killer(me);
		target->start_busy(1);
		me->remove_killer(target);
		me->start_busy(1);
	}
	else
	{
		if( random((int)target->query_temp("forcetimes")) > 2 )
		{
			"/cmds/std/halt"->main(target);
			if( !random(3) ) do_flee(target);
			else target->random_move();
			if( !mapp(environment(target)->query("exits")) )
				target->return_home(target->query("startroom"));
		}
		else
		{
			target->kill_ob(me);
			message_vision("\n$N��м��ƲƲ�죺" + RANK_D->query_rude(me) + "������ɱ�������ͽ������\n", target);
		}
		me->start_busy(1+random(3));
	}
}

int eff_fam(object ob)
{
	switch((string)ob->query("family/family_name"))
	{
		case "�䵱��"   :
		case "ȫ���"   :
		case "������"   :
		case "��������" :
		case "������"   :
		case "�컨��"   :
		case "����μ�" :  return 10; break;
		case "��ü��"   :
		case "������"   :
		case "��Ĺ��"   :
		case "��ɽ��"   :  return  9; break;
		case "̩ɽ��"   :
		case "��ɽ��"   :
		case "��ɽ��"   :
		case "��ɽ��"   :  return  8; break;
		case "�����"   :
		case "����Ľ��" :
		case "�һ���"   :  return  7; break;
		case "��ң��"   :
		case "������"   :  return  6; break;
		case "����"     :
		case "ؤ��"     :  return  5; break;
		case "ѩɽ��"   :
		case "��ľ��"   :  return  4; break;
		case "�嶾��"   :
		case "����ɽ��" :  return  3; break;
		case "���ư�"   :
		case "������"   :  return  2; break;
		default:
			if( ob->query("attitude") == "aggressive" ||
				ob->query("attitude") == "heroism" )
				return 6;
			else return 3;
			break;
	}
	return  5;
}

void do_flee(object ob)
{
	message("vision", ob->name() + "һת�۱���ʧ�ˡ�\n", environment(ob), ({ob}));

	if( mapp(ob->query("family")) &&
		member_array((string)ob->query("id"), masters) == -1 )
	{
		switch((string)ob->query("family/family_name"))
		{
		case "�䵱��"   : ob->move("/d/wudang/sanqingdian"); break;
		case "ȫ���"   : ob->move("/d/quanzhen/datang1"); break;
		case "������"   : ob->move("/d/shaolin/dxbdian"); break;
		case "��������" : ob->move("/d/nanshaolin/pingtai"); break;
		case "������"   : ob->move("/d/beijing/dating"); break;
		case "�컨��"   : ob->move("/d/huijiang/zongduo"); break;
		case "����μ�" : ob->move("/d/dali/wangfugate"); break;
		case "��ü��"   : ob->move("/d/emei/hcaguangchang"); break;
		case "������"   : ob->move("/d/kunlun/qianting"); break;
		case "��Ĺ��"   : ob->move("/d/gumu/zhongting"); break;
		case "��ɽ��"   : ob->move("/d/songshan/chanyuan"); break;
		case "̩ɽ��"   : ob->move("/d/taishan/riguan"); break;
		case "��ɽ��"   : ob->move("/d/huashan/buwei3"); break;
		case "��ɽ��"   : ob->move("/d/henshan/zhurongdian"); break;
		case "��ɽ��"   : ob->move("/d/hengshan/baiyunan"); break;
		case "�����"   : ob->move("/d/qingcheng/songfengguan"); break;
		case "����Ľ��" : ob->move("/d/yanziwu/lanyue"); break;
		case "�һ���"   : ob->move("/d/taohua/dating"); break;
		case "��ң��"   : ob->move("/d/xiaoyao/qingcaop"); break;
		case "������"   : ob->move("/d/lingxiao/dadian"); break;
		case "����"     : ob->move("/d/mingjiao/square"); break;
		case "ؤ��"     : ob->move("/d/yueyang/gaibangtang"); break;
		case "ѩɽ��"   : ob->move("/d/xueshan/dadian"); break;
		case "��ľ��"   : ob->move("/d/heimuya/chengdedian"); break;
		case "�嶾��"   : ob->move("/d/wudujiao/dating"); break;
		case "����ɽ��" : ob->move("/d/baituo/dating"); break;
		case "���ư�"   : ob->move("/d/tiezhang/guangchang"); break;
		case "������"   : ob->move("/d/xingxiu/riyuedong1"); break;
		default  : 
			ob->move(safeplaces[random(sizeof(safeplaces))]); break;
		}
	}
	else ob->move(safeplaces[random(sizeof(safeplaces))]);

	message("vision", ob->name() + "���˹�����\n", environment(ob), ({ob}));
}      

private int is_spy(object ob)
{
	if( !ob->query("sg/spy") ) return 0;
	return 1;
}

int do_search(string arg)
{
	string str, *option;
	object *list;
	int i, j, ppl_cnt, total;

	if( !arg || !(arg == "shenlong" || arg == "������") ||
		this_player()->query("sg/exp") < 1000 )
		return 0;

	if( !wizardp(this_player()) && (int)this_player()->query("jing") < 30 )
		return notify_fail("��ľ���̫���ˣ�û�а취��֪������֯����ϸ���ϡ�\n");

	this_player()->receive_damage("jing", 30);
	seteuid(getuid());

	str = "�� " + MUD_NAME + "\n";
	str += "��������������������������������������������������������������������������\n";

	list = filter_array(users(), "is_spy", this_object());   
	total = sizeof(list);

	list = sort_array(list, "sort_user", this_object());
	j = sizeof(list);
	while( j-- )
	{
// Skip those users in login limbo.
		if(!environment(list[j]) ) continue;
		if(this_player() && !this_player()->visible(list[j]) ) continue;
		str = sprintf("%s%12s %s\n", str, RANK_D->query_rank(list[j]), list[j]->short(1) );
	}

	str += "��������������������������������������������������������������������������\n";
	str = sprintf("%s���� %d λ�����̳�Ա�����С�\n", str, total);

	this_player()->start_more(str);
	return 1;
}

int sort_user(object ob1, object ob2)
{
	return (int)ob2->query("sg/exp") - (int)ob1->query("sg/exp");
}

int do_job()
{
	string job;

	if( this_player()->query("sg_ok/pk") ||
		this_player()->query("sg_ok/join") )
	{
		write("����������һ��׷ɱ����\n");
		return 1;
	}
	if( this_player()->query("sg_ok/stuff") )
	{
		write("����������һ���Ҷ���������\n");
		return 1;
	}
	if( this_player()->query("sg_ok/forcejoin") )
	{
		write("����������һ��������̵ĵ�����\n");
		return 1;
	}
	if( !mapp(this_player()->query("sgjob")) &&
		!mapp(this_player()->query("sgjob_join")) )
	{
		write("������û�н������\n");
		return 1;
	}
	if( (job = this_player()->query("sgjob/forcejoin")) )
	{
		write("�㵱ǰ�������Ǳ���" + job + "��̡�\n");
		return 1;
	}
	if( (job = this_player()->query("sgjob/victim_name")) )
	{
		write("�㵱ǰ��������׷ɱ" + job + "(" + this_player()->query("sgjob/victim_id") + ")��\n");
		return 1;
	}
	if( (job = this_player()->query("sgjob/sgjob")) )
	{
		write("�㵱ǰ����������" + job + "��\n");
		return 1;
	}
	write("������û�н������\n");
	return 1;
}

int do_jobtime()
{
	int start_time, time, s, m;

	if( mapp(this_player()->query("sg_ok")) )
		return notify_fail("���Ѿ���������ˣ������ں�ʱ�䡣\n");
	if( !(start_time = this_player()->query("sgjob/assigntime")) )
	if( !(start_time = this_player()->query("sgjob_join/assigntime")) )
		return notify_fail("������û�н������\n");
	time = time() - start_time;
	if( time > 1800 )
	{
		write("�Ѿ����˰�Сʱ������ȥ���������ˡ�\n");
		return 1;
	}
	s = time % 60;
	m = time / 60;
	write("���ͣ����ͣ����ͣ��Ѿ�����" + chinese_number(m) + "��" + chinese_number(s) + "��\n");
	return 1;
}

