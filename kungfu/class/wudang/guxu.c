// guxu.c ����

#include "daozhang.h"
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();

void create()
{
	set_name("�������", ({ "guxu daozhang", "guxu", "daozhang" }));
	set("long","����������ҵĵ��ӹ��������\n��������ʮ�꣬�����䵱�ɵ����¡�\n");
	set("gender", "����");
	set("age", 40);
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

	set_skill("force", 60);
	set_skill("taiji-shengong", 40);
	set_skill("dodge", 60);
	set_skill("tiyunzong", 90);
	set_skill("unarmed", 60);
	set_skill("taiji-quan", 90);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 90);
	set_skill("taoism", 60);
	set_skill("wudang-quan", 90);
	set_skill("wudang-jian", 90);
	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	
	set("env/wimpy", 60);
	create_family("�䵱��", 3, "����");
	set("inquiry", 
	([
		"���¾�" : (: ask_me :),
		"jing"   : (: ask_me :),
		"book"   : (: ask_me :),
	]));
				
	set("book_count", 1);

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}

void init()
{
	object me = this_player();

	::init();

	if ( me->query("family/family_name") == "�䵱��" &&
		me->query("wudang/offerring") > me->query("age")*2 )
		me->set_temp("mark/����", 1);
}

string ask_me()
{
	mapping fam; 
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "�䵱��")
		return RANK_D->query_respect(this_player()) +"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵĵ����澭���ڴ˴���";
	add("book_count", -1);
	ob = new(BOOK_DIR"daodejing-ii");
	ob->move(this_player());
	return "�ðɣ��Ȿ�����¾������û�ȥ�ú����С�";
}
