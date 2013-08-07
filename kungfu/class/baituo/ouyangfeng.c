// /kungfu/class/baituo/ouyangfeng.c
// Last Modified by Winder on May. 15 2001

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

int ask_help();
int do_accept();

void create()
{
	object ob;
	set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "���ǰ���ɽׯ�����ųơ���������ŷ���档\n"
		+"����ϰ���������澭���߻���ħ���ѱ�þ�\n"
		+"����ң�������ͷɢ����\n");
	set("title", "����ɽׯ��");
	set("gender", "����");
	set("age", 53);
	set("nickname", HIY "����" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");
	set("no_get",1);

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 900);
	set("max_jing", 900);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 3000000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("hand",200);
	set_skill("strike",200);
	set_skill("staff", 200);
	set_skill("training",200);
	set_skill("literate", 100);
	set_skill("xidu-poison", 150);
	set_skill("hamagong", 200);
	set_skill("hamaquan", 300);
	set_skill("chanchu-bufa", 300);
	set_skill("shexing-diaoshou", 300);
	set_skill("lingshe-zhangfa", 300);
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("cuff", "hamaquan");
	map_skill("strike", "hamagong");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
	prepare_skill("hand", "shexing-diaoshou");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "staff.shoot" :),
		(: perform_action, "staff.saoye" :),
		(: perform_action, "strike.hama" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );

	create_family("����ɽ��",1, "��ɽ��ʦ");
	set("chat_chance",2);
	set("chat_msg",({
		"ŷ������������������հ���ɽ�ɲ����ذԽ����ء�\n",
		"ŷ��������Ҷ�ŷ���˱��ܹ��������ɽ���۷磡\n",
		"ŷ������������ն����������ģ�\n",
	}));
	
	set("inquiry", ([
		"name":   "���֣���...��û�����֣���...����˭?",
		"����":   "���֣���...��û�����֣���...����˭?",
	]));
	setup();
	if (clonep())
	 {
	 	ob = new(WEAPON_DIR"treasure/lingshezhang");
	 	if ( ob -> violate_unique() )
	 	{
	 		destruct(ob);
	 		ob=new("/d/baituo/obj/shezhang");
 		}
 		ob->move(this_object());
 		ob->wield();
	 }
	carry_object(__DIR__"obj/baipao")->wear();
	add_money("silver",50);
}

void init()
{
	add_action("do_accept", "accept");
        add_action("do_qiecuo","qiecuo");
}

int ask_help()
{
	object me = this_player();
	
	if (me->query("family/family_name") == "����ɽ��" &&
		me->query("family/master_id") != "ouyang feng" &&
		me->query_condition("ice_sting") &&
		me->query_condition("ice_sting") < 10)
	{
		message_vision(HIG"ŷ����˵�������ã����㲻�ѣ����������Ӧ(accept)����һ���ְ֡���\n"NOR, me);
		me->set_temp("helpme", 1);
		return 1;
	}
	return 0;
}

int do_accept()
{
	if (this_player()->query_temp("helpme"))
	{
		this_player()->set("oyf_son", 1);
		this_player()->apply_condition("ice_sting", 0);
		message_vision( HIY"ŷ���������Ц���������ң����ã��ã��Զ��ӣ��Ҿʹ����󡹦��������ɣ�ֻҪ���ڼ���ϰ����\n", this_player());
		message_vision( HIY"������ȥ���Ͼ綾����׾٣����ճư����֣����Ұ���������£��� \n", this_player());
		tell_object(this_player(),HIG"�㰴��ŷ�������������й����ؿ�ʹ�����������ɵ�ϲ��ü�ҡ�\n"NOR);
		this_player()->set_temp("baifeng", 1);
		return 1;
	} else return notify_fail("ŷ����Ƴ����һ�ۣ�����û��Ϲ��Ӧ��ô����\n");
}

void attempt_apprentice(object ob)
{
//	if (ob->query_temp("baifeng") && ob->query("combat_exp") > 50000 && ob->query("age") <= 18 && ob->query("age") >= 16)
	if (ob->query_temp("baifeng") && ob->query("combat_exp") > 50000 )
		command("recruit " + ob->query("id"));
	else message_vision("ŷ�������$Nһ�۵������Ұ���ɽ������ҵ����ᴫ����\n", ob); 	
}
