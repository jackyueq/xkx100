// gaoyanchao.c ���峬

#include <ansi.h>;

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int ask_weiwang();

void create()
{
	set_name("���峬", ({ "gao yanchao", "gao", "yanchao" }));
	set("gender", "����");
	set("age", 32);
	set("str", 25);
	set("dex", 20);
	set("long", "��������ʮ��ͷ��ȴ�Ե��쳣������\n");
	set("combat_exp", 40000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("claw", 70);
	set_skill("hand", 70);
	set_skill("literate", 50);
	set_skill("yunlong-shengong", 60);
	set_skill("yunlong-shenfa", 60);
	set_skill("yunlong-shou", 80);
	set_skill("yunlong-zhua", 80);
	map_skill("hand", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "yunlong-shou");
	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");

	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 25);
	set("qi", 400);
	set("max_qi", 400);
	set("jing", 300);
	set("max_jing", 300);
	set("neili", 250); 
	set("max_neili", 250);
	set("jiali", 35);
	set("inquiry", ([
		"�½���" : "����ܶ����ɲ����װ���\n",
		"��ػ�" : "ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" : "ֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
		"���帴��" : "ȥ�ײĵ�������ϸ���ưɣ�\n",
		"����" : "�����£�\n",
		"�п�" : "�����£�\n",
		"����" : (: ask_weiwang :),
		"��������" : (: ask_weiwang :),
	]) );
	set("party/party_name", HIR"��ػ�"NOR);
	set("party/rank", HIG"��ľ��"NOR"����");
	create_family("������", 2, "����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 1);
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	say("\n���峬˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
	say("���峬��˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
	return 1;
}

void init()
{
	::init();
	add_action("do_join","join");
}

int recognize_apprentice(object ob)
{
	if (ob->query("weiwang")<50)
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ�����Ҳ��̡�\n"); 
		return 0;
	}
	return 1;
}
/*
int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="gao" ) return 0;
	if(wizardp(ob)) return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
		return 1;
	}
	command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �������� (club)                          - �Ƿ��켫  80/    \n"+
"  �����Ṧ (dodge)                         - �����뻯  70/    \n"+
"  �����ڹ� (force)                         - �����뻯  70/    \n"+
"����Ԫһ���� (hunyuan-yiqi)                - ����似  60/    \n"+
"  ����д�� (literate)                      - �������  50/    \n"+
"  �����м� (parry)                         - �����뻯  70/    \n"+
"�������� (shaolin-shenfa)                - ����似  60/    \n"+
"  ����ȭ�� (unarmed)                       - �����뻯  70/    \n"+
"��������� (zui-gun)                       - �����뻯  70/    \n");
	return 1;
}
*/
#include "/kungfu/class/yunlong/tiandihui.h";
