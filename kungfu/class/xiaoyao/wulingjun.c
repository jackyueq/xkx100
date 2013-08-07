// wulingjun.c �����
// Modified by Winder June 25. 2000
inherit NPC;
inherit F_MASTER;

#include <ansi.h>;

void create()
{
	set_name("�����", ({ "wu lingjun", "wu" }));
	set("long","�����õ��࣬ɽˮ�����ë���ܣ����Ծ��ɡ�����ʦ��֮ǰ���ڴ��γ�͢�����������ְ֮����˴�ұ�����������\n");
	set("nickname","�����Ȱ��ѡ�����");
	set("gender", "����");
	set("age", 40);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 60);
	set("combat_exp", 340000);
	set("score", 50000);

	set_skill("painting", 150);
	set_skill("blade", 70);
	set_skill("ruyi-dao", 100);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("strike", 70);
	set_skill("parry", 70);
	set_skill("lingboweibu", 100);
	set_skill("beiming-shengong", 70);
	set_skill("liuyang-zhang", 100);
	map_skill("strike", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");
	map_skill("parry", "ruyi-dao");
	prepare_skill("strike", "liuyang-zhang");
	set("book_count", 1);
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingbo" :),
		(: perform_action, "strike.zhong" :),
//		(: perform_action, "hand.duo" :),		
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("��ң��", 3, "����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/food/jiudai");
}
