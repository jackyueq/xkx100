// chongxu.c ����

#include "daozhang.h"
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("�������", ({ "chongxu daozhang", "chongxu", "daozhang" }));
	set("long","�����������۵ĵ��ӳ��������\n��������ʮ���꣬�����䵱�ɽ𶥵����¡�\n");
	set("gender", "����");
	set("age", 48);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);
	set("combat_exp", 60000);
	set("score", 8000);

	set_skill("force", 50);
	set_skill("taiji-shengong", 50);
	set_skill("dodge", 50);
	set_skill("tiyunzong", 70);
	set_skill("unarmed", 60);
	set_skill("taiji-quan", 90);
	set_skill("parry", 50);
	set_skill("sword", 60);
	set_skill("wudang-jian", 90);
	set_skill("wudang-quan", 70);
	set_skill("taoism", 50);
	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");

	set("env/wimpy", 60);
	create_family("�䵱��", 3, "����");
	set("class", "taoist");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}

