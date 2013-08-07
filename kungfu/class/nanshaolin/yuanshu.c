// yuanshu.c
// Last Modified by winder on May. 29 2001

#include "/kungfu/class/nanshaolin/yuan.h";
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("Ԫˡ", ({ "yuan shu", "shu", "yuan" }));
	set("long","����һλ�еȸ��ӵĺ��У���һϮ�಼������ġ�̫��Ѩ΢͹��˫Ŀ��������\n");
	set("nickname", "����Ժ�����޺�");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 30);
	set("dex", 20);
	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 3000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("zhanzhuang-gong", 100);
	set_skill("dodge", 100);
	set_skill("yiwei-dujiang", 100);
	set_skill("cuff", 100);
	set_skill("luohan-cuff", 100);
	set_skill("staff", 100);
	set_skill("pudu-staff", 100);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("staff", "pudu-staff");
	map_skill("parry", "pudu-staff");
	prepare_skill("cuff", "luohan-cuff");

	create_family("��������", 20, "����");

	setup();
	carry_object(WEAPON_DIR+"staff/fangbianchan")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	object ob;

	::init();
	add_action("do_nod", "nod");
}

