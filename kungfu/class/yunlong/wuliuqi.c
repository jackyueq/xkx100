// wuliuqi.c

#include <ansi.h>;

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_weiwang();

void create()
{
	set_name("������", ({"wu liuqi", "wu","liuqi"}));
	set("nickname", HIB"��ؤ"NOR);
	set("gender", "����");
	set("age", 50);
	set("long", 
		"����Ͻл����������������ġ���ؤ�������棬�����������\n"
		"���ڹپӹ㶫�ᶽ֮ʱ������һʡ�ر������˲���諵�Ȱ����\n"
		"�Ĵ淴�帴��֮־��������ػᣬ��ְ��˳��������\n"
	);

	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	
	set("combat_exp", 150000);
	set("score", 30000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("claw", 120);
	set_skill("hand", 120);
	set_skill("literate", 50);
	set_skill("yunlong-shengong", 120);
	set_skill("yunlong-shenfa", 120);
	set_skill("yunlong-shou", 120);
	set_skill("yunlong-zhua", 120);
	map_skill("hand", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "yunlong-shou");
	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");

	set("chat_chance", 3);
	set("chat_msg", ({
		"�������Ȼ�ſ������������������߽��ߣ���ǻ�ߺ���˭�ԣ�����\n"
		"���������������ζ������¸����̡������Դ��У�������Զ��\n",
		"������˵: ������������Ҫ�������ߴ��кô�����\n",
		"������ͻȻ˵��: �ɰض�֦�����ң��нں黪����ͤ��\n",
		"������ͻȻ˵��: ������ǰ����Ը�����帴���Һ�Ӣ��\n",
	}));
	set("inquiry", ([
		"�½���" : "����ܶ����ɲ����װ���\n",
		"��ػ�" : "ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" : "ֻҪ��������ػᣬ��������и�λ����ѧ�书��\n",
		"���帴��" : "ȥҩ�̺͹ײĵ���ϸ���ưɣ�\n",
		"����" : (: ask_weiwang :),
		"��������" : (: ask_weiwang :),
	]) );
	set("party/party_name", HIR"��ػ�"NOR);
	set("party/rank", HIG"��˳��"HIC"����"NOR);
	create_family("������", 2, "����");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	say( "������˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
	say("\n��������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
	return 1;
}

int recognize_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ�����Ҳ��̡�\n"); 
		return 0;
	}
	return 1;
}

void init()
{
	::init();
	add_action("do_join","join");
}
/*
int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="wu" )
		return 0;
	if(wizardp(ob))
		return 0;
	if(wizardp(ob)) return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
		return 1;
	}
	command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �л����� (begging)                       - �������  50/   \n"+ 
"  ����;˵ (checking)                      - �������  50/   \n"+ 
"  �����Ṧ (dodge)                         - һ����ʦ  90/   \n"+ 
"  �����ڹ� (force)                         - һ����ʦ  95/   \n"+ 
"���������� (huntian-qigong)                - һ����ʦ  90/   \n"+
"  �����м� (parry)                         - �Ƿ��켫  85/   \n"+
"  ����ȭ�� (unarmed)                       - һ����ʦ  90/   \n"+
"������ʮ���� (xianglong-zhang)             - �Ƿ��켫  85/   \n"+
"����ң�� (xiaoyaoyou)                      - һ����ʦ  95/   \n");
	return 1;
}
*/
#include "tiandihui.h";
