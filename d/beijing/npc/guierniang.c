// /beijing/npc/guierniang.c
// Last modified by winder 2003.10.10

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("�����", ({ "gui erniang", "gui" }));
	set("long", 
"һ���������ϸ���ͷ����ף���������ȴ�Ǿ����ӣ�\n"
"Ƣ���൱�Ļ𱩡���������ȭ�޵й����������ˡ�����\n"
"���\n");
	set("gender", "Ů��");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 40);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);
	
	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 20000);

	set_skill("cuff", 100);
	set_skill("force", 100);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike", 100);
	set_skill("sword", 150);
	set_skill("huashan-sword", 150);
	set_skill("zixia-shengong", 150);
	set_skill("poyu-quan", 100);
	set_skill("hunyuan-zhang", 100);
	set_skill("feiyan-huixiang",150);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-sword");
	map_skill("strike", "hunyuan-zhang");
	map_skill("sword", "huashan-sword");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");
	set("chat_chance", 2);
	set("chat_msg", ({
		"��������˹���һ�ۣ������̾�˿�����\n",
	}) );	

	create_family("��ɽ��", 31, "����");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"sword")->wield();

}
