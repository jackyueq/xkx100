// xin.c ����ʦ̫
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����ʦ̫", ({ "jingxin shitai","jingxin","shitai"}));
	set("long", "����һλ������ҵ��ã����ڸ�£����ü��Ŀ��\n");
	set("gender", "Ů��");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 10000);
	set("class", "bonze");
        set("no_get",1);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);

	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 250000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("throwing", 80);
	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("finger", 80);
	set_skill("parry", 90);
	set_skill("strike", 90);
	set_skill("blade", 80);
	set_skill("literate", 90);
	set_skill("mahayana", 100);
	set_skill("jinding-zhang", 120);
	set_skill("tiangang-zhi", 120);
	set_skill("yanxing-dao", 120);
	set_skill("zhutian-bu", 125);
	set_skill("linji-zhuang", 100);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("blade","yanxing-dao");
	map_skill("parry","yanxing-dao");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
//		(: perform_action, "sword.mie" :),
		(: perform_action, "blade.wuxing" :),
		(: perform_action, "strike.bashi" :),
		(: perform_action, "finger.lingkong" :),		
		(: exert_function, "powerup" :),				
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	create_family("������", 4, "����");

	setup();
	carry_object(WEAPON_DIR"gangdao")->wield();
	carry_object(CLOTH_DIR"ni-cloth")->wear();
	carry_object(CLOTH_DIR"ni-shoe")->wear();
}
void attempt_apprentice(object ob)
{
	command ("say �����ӷ�ƶ�᲻�յ��ӡ�\n");
	command ("say ���������ѧ�����ɵĹ��򣬻���ȥ�����׼�ʦ�ðɡ�\n");
	return;
}
