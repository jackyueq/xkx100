// yu.c 

inherit NPC;
inherit F_SKILL;
#include <ansi.h>;

void create()
{
	set_name("���˺�", ({ "yu renhao", "yu", "renhao" }));
	set("gender", "����");
	set("nickname", HIC"�������"NOR);
	set("age", 25);
	set("long", "�����ǡ�Ӣ�ۺ��ܣ�������㡹֮һ���书ҲԶ��ͬ�š�\n");

	set("combat_exp", 80000);
	set("shen_type", -1);

	set_skill("sword", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("strike", 80);
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("bixie-sword", 80);
	set_skill("songfeng-jian", 80);
	set_skill("chuanhua", 80);
	set_skill("wuying-leg", 80);
	set_skill("cuixin-strike", 80);
	set_skill("qingming-xuangong", 80);
	map_skill("force", "qingming-xuangong");
	map_skill("unarmed", "wuying-leg");
	map_skill("strike", "cuixin-strike");
	map_skill("dodge", "chuanhua");
	map_skill("parry", "bixie-sword");
	map_skill("sword", "songfeng-jian");
	prepare_skill("unarmed", "wuying-leg");
	prepare_skill("strike", "cuixin-strike");
	create_family("�����", 6, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob=this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	say ("���˺���һ�������Ӿ������˺���\n");
	return;
}
