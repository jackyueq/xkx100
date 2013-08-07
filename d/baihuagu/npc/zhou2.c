//
// zhou.c �ܲ�ͨ

#include <ansi.h>;

inherit NPC;
void create()
{
	set_name("�ܲ�ͨ", ({ "zhou botong", "zhou", "bo tong" }));
	set("gender", "����");
	set("nickname", CYN "����ͯ" NOR ) ;
	set("title", "ȫ��̵�һ������") ;
	set("age", 45);
	set("long",
		"�������˳ơ�����ͯ�����ܲ�ͨ��\n"
		"��һ���ɷ���ǵ����ӣ��������������ʮ���ꡣ������������ʵ�Ѿ������ϡ�ˡ�\n"
	);

	set("combat_exp", 5000000);
	set("shen_type", 1);
	set("max_neili", 10000);
	set("neili", 10000);
//	set("jiali", 0);
	set("per",39);

	set_skill("force", 180);
	set_skill("xiantian-qigong", 180);    //��������
	set_skill("sword", 180);
	set_skill("quanzhen-jian", 180);  //ȫ�潣
	set_skill("dodge", 180);
	set_skill("jinyan-gong", 180);   //���㹦
	set_skill("strike", 180);
	set_skill("haotian-zhang", 180);    //�����
	set_skill("cuff", 180);
	set_skill("chunyang-quan", 180);    //����ȭ
	set_skill("unarmed", 200);
	set_skill("kongming-quan", 200);     //����Ȫ
	set_skill("hubo", 100);
	set_skill("parry", 180);
	set_skill("literate", 80);
	set_skill("taoism", 100);

	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("strike", "haotian-zhang");
	map_skill("unarmed","kongming-quan");
	map_skill("cuff", "chunyang-quan");
	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "haotian-zhang");

	set("inquiry", ([
		"�����澭" : "����������ʲ�ӣ��ҾͲ��������ˡ�\n",
		"����"     : "��֪�������Ķ��𣿿죬������ҡ�",
		"��"       : "��Ҫ���ң����������ˣ�\n",
		"�ݰ��ֵ�" : "�����ҵİݰ��ֵܹ����������Ǹ���Ӣ�ۡ���������������������",
		"����"     : "�����ҵİݰ��ֵܹ����������Ǹ���Ӣ�ۡ���������������������",
		"����"     : "��СѾͷ����飬�ұȲ�������",
	]) );
	create_family("ȫ���", 1, "����");
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);
	setup();

	carry_object("/clone/cloth/cloth")->wear();
}
int accept_object(object who, object ob)
{
	if (ob->query("id") == "du she")
	{
		message_vision("$N�ó�һ������������ͯ����ǰ���˻Σ�����������
����ͯ�ŵ�����������������⣡���ܱߺ������͸�ˣ�����ͯ�ⷬ�����ˣ�\n\n
��������Զȥ�����ڲ������š�\n" ,who);
		destruct(this_object());
		return 0;
	}
	if (ob->query("id") == "mi")
	{
		if(who->query_temp("marks/mihave") && (int)who->query("marks/mi_age")<=121 )
		{
			message_vision("����ͯ�ӹ����ۣ����˵�˵�����ã��ã��á�\n\n",who);
			if(who->query("combat_exp") < 100000)
			{
				tell_object(who,HIW"��ľ��������ˣ�\n���Ǳ�������ˣ�\n" NOR);
				who->add("combat_exp",100+random(50));
				who->add("potential",20+random(30));
			}
			who->set_temp("marks/mihave",0);
			who->add("marks/mi",1);
			if((who->query("marks/mi"))>60 && who->query("age")>39)
			{
				tell_object(who, HIG "���������䣬���Եø��������ˣ�\n" NOR);
				who->add("mud_age",-86400);
				who->delete("last_slp");
				who->delete("jingzuo_time");
				who->add("marks/mi_age",1);
				who->set("marks/mi",0);
			}
		}
		else if(who->query_temp("marks/mihave") && (int)who->query("marks/mi_age")>121)
		{
			message_vision( HIY"����ͯ�ӹ����ۣ���$N���˸�������Ц����������������Ҳ�����ˣ���Ȼ�ҳ��������͵��ۣ��������԰ײ��ԡ�\n\n"NOR,who);
		}
		else
		{
			message_vision( HIY"����ͯ�ӹ����ۣ���$N���˸�������Ц������������Ҳ���������ģ����԰ײ��ԡ�\n\n"NOR,who);
		}
		call_out("delmi",2);
		return 1;
	}
	return 0;
}
int delmi()
{
	object obj2;
	obj2=present("mi", this_object());
	destruct(obj2);
	return 1;      
}
