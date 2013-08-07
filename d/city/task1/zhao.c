//  zhaoyishang.c ��һ��
 
inherit NPC;
 
void create()
{
	set_name("��һ��", ({ "zhao  yishang" }));
	set("nickname", "�������");
	set("long","ԭ�������еľ޿ܣ�����Ϊ��ܹٸ��ͳ�ң�������˸������֡�\n");
	set("gender", "����");
	set("age", 36);
	set("attitude", "peaceful");
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("combat_exp", 1800000+ random(500000)); 
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: perform_action, "strike.diezhang" :),
		 (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	
	})); 
	set_skill("force", 100);
	set_skill("xuantian-wuji", 140);
	set_skill("dodge", 180 + random(50));
	set_skill("kunlun-shenfa", 270);
	set_skill("strike", 180 + random(50));
	set_skill("kunlun-strike", 270 + random(50));
	set_skill("parry", 180 + random(50));
	set_skill("literate", 80);
	set_skill("sword",180 + random(50));
	set_skill("changge-jian",270 + random(50));
	map_skill("sword","changge-jian");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("strike", "kunlun-strike");
  	map_skill("parry", "kunlun-strike");
  	prepare_skill("strike", "kunlun-strike");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 50);
}
#include "npc.h"
