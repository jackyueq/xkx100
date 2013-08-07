// zheng.c ֣����
 
inherit NPC;
 
void create()
{
	set_name("֣����", ({ "zheng  qimie", "zheng" }));
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
	set("combat_exp", 2000000+ random(500000));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	set_skill("force", 150);
	set_skill("xuantian-wuji", 150);
	set_skill("dodge", 180 + random(50));

	set_skill("kunlun-shenfa", 270 + random(50));
	set_skill("unarmed", 180 + random(50));
	set_skill("changquan", 270 + random(50));
	set_skill("parry", 180 + random(50));
	set_skill("murong-blade", 270 + random(50));
	set_skill("blade", 180 + random(50));
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("blade", "murong-blade");
	map_skill("unarmed", "changquan");
  	map_skill("parry", "murong-blade");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield(); 
	add_money("silver", 50);
}
#include "npc.h"
