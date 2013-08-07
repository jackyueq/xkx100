// Npc: /kungfu/class/nanshaolin/fangxian.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("����", ({ "fang xian", "fang", "xian"}));
	set("long", "����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 100);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("luohan-cuff", 50);
	set_skill("hand", 50);
	set_skill("fengyun-hand", 50);
	set_skill("sword", 50);
	set_skill("damo-sword", 50);
	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("hand", "fengyun-hand");
	map_skill("sword", "damo-sword");
	map_skill("parry", "damo-sword");
	prepare_skill("hand", "fengyun-hand");
	prepare_skill("cuff", "luohan-cuff");
	create_family("��������", 21, "����");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(WEAPON_DIR+"sword/changjian")->wield();
}
#include "/kungfu/class/nanshaolin/fang.h";

