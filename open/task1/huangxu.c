// huangxu.c �������

inherit NPC;
 
void create()
{
	set_name("�������", ({ "huangxu  daoren", "daoren" }));
	set("long", "�䵱����ͽ��Ϊ�˼�թ��������Щ���¡�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 50);
	set("combat_exp", 500000 + random(40000)); 
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		     
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	set_skill("force", 60);
	set_skill("taiji-shengong", 100);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 150 + random(50));
	set_skill("cuff", 110 + random(50));
	set_skill("parry", 100 + random(50));
	set_skill("taiji-quan", 150 + random(50));
	set_skill("literate", 20);
	set_skill("sword",100 + random(50));
	set_skill("changge-jian",150 + random(50));
	map_skill("sword","changge-jian");
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
  	map_skill("parry", "taiji-quan");
  	prepare_skill("unarmed", "taiji-quan");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
