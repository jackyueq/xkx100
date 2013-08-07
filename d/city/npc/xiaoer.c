// xiaoer.c

// inherit NPC;
inherit F_VENDOR_SALE;
#include <ansi.h>;

void create()
{
//	reload("xiaoer");
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	setup();
}
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (wizardp(ob)) return;
	if (!ob->query_temp("welcome100") || ob->query("mud_age")<1000)
	{
		ob->set_temp("welcome100","1");
tell_object(ob,"\n\n��С��Ц�����˵������λ"+RANK_D->query_respect(ob)+"����ӭ����"GRN"������һ�١�"NOR"

    �������ʲô�����׵ģ�������"RED"tell"NOR"����ҡ�ȱǮ����Ҳ��������
��Ұ����ݶ��ѹء������Ƕ����������˵ġ���Ȼ��Ҳ������"RED"help"NOR"����
�����Ǹ����İ�����
    ����"HIR"help"NOR"���ܿ����ܶ������Ŀ��
    ����Ĺ��º���ڣ�����Ļ��������ǽ�ӹ��ʮ�屾С˵�������
�Թ��²�̫�ǵ��˻����˽��Щ������"RED"help intro"NOR"�������������
��û��� MUD��Ϸ���Ǿ��ȿ���"RED"help newbie"NOR"��������·�ɡ�"RED"help cmds"NOR"
������������Ҷ����õ��������ʶһ������ĵ�ͼ��"RED"map map"NOR"����
���кܶ���Ŀ�ģ�������ѡ���ͼ��Ŀ"RED"map all"NOR"����������Ϸ�ĵ�ͼ��
����¶��ֱ��"RED"map "NOR"���������ڴ��ĵط��ĵ�ͼ����Ȼ����Ҫ����������
����̣����һ��Ҫ��ʹ��"RED"chat"NOR"���������������İ����ļ�Ҳ��Ϊ��
�ǵĹ��������£��������Ŷ���͵��������ϣ��ϣ����͵�����ˣ���
ʦ�������Կ��ģ�����û��ð��ĸ����ɾ���ȥ���ѧ�����ݵ�����
����Ϣ���ģ���ȥ��������Ĺ��棬���µ���Ϣһ��������������
    ������������Ϸ����ƺ͹�����ʲô�����������벻��ֱ����
��"RED"mailto winder"NOR" ����������ʦ������һ�������濼�ǵġ�\n\n");
	}
	switch( random(2) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}
int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 5000) 
	{
		tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
