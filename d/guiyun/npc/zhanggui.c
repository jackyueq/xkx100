// Npc: /d/guiyun/npc/zhanggui.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("�ƹ�", ({ "zhang gui", "zhanggui", "zhang" }) );
	set("gender", "����" );
	set("age", 52);
	set("long",
		"��λ���ƹ�����æ���ô����̡�\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "�����͹�˵��С�϶���С��ʵ�������������԰�����",
		"rumors" : "����ׯ�ĵ��������������ʱ��̸���һ���������¶�����������顣",
		"here" : "������̫���ߣ������߾Ϳ��Կ�������ׯ�ˡ�",
		"�һ���": "��˵�Ƕ����ϵ�С���������ݵĶ����ߣ������߿��ܲ��ܹʹ��ɣ�",
		"����" : "��Ϊ����ׯ�ĵ����������չ�С������⣬���Ի��㲻��",
		"����ׯ" : "���߾��ܿ����������ׯ����½��ƽʱ�ѵü�����",
	]) );
	setup();
}

void init()
{	
}

int accept_object(object who, object ob)
{
	int pay, value;

	if (ob->query("money_id")) {
		if (!(pay = who->query_temp("total_pay"))) {
			tell_object(who, "�ƹ�æ������Ц�������͹����ֲ�ǷС���Ǯ���ͱ�����ͷ��Ѱ�����ˡ���\n");
			return 0;
		}
		if (!who->query_temp("to_pay")) {
			tell_object(who, "�ƹ�˵�������͹����Ƚ���(pay)�ٸ����\n");
			return 0;
		}
		value = ob->value();
		if (value >= pay) {
			who->delete_temp("to_pay");
			who->delete_temp("total_pay");
			if (value == pay) message_vision("�ƹ���������Ц����$N����������л�͹��������ߺá���\n", who);
			else message_vision("�ƹ���������Ц����$N����������л�͹�����С�ѣ��϶��������������ˣ����ߺá���\n", who);
			return 1;
		}
		else {
			pay -= value;	
			message_vision("�ƹ����$N˵����������������" + chinese_number(pay) + "�ġ���\n", who);
			who->set_temp("total_pay", pay);
			return 1;
		}
	}
	return 0;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��ɥ�ط����ƹ�վ�ڸ߸ߵĹ�̨���棬��������\n", ob);
}

void unconcious()
{
	say( "�ƹ��һ�������Ҳ����ˣ������Ӱ࣡��\n");
	say( "����ӹ�̨���������һ���ƹ�����˵����û���⣬�����Ұɡ���\n");
	say( "ǰһ���ƹ�����������뿪�ˡ�\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}

