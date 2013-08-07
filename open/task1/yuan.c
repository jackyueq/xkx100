// yuan.c Ԫ�㲨
 
inherit NPC;
 
void create()
{
	set_name("Ԫ�㲨", ({ "yuan  guangbo", "yuan" }));
	set("nickname", "��ɰ�����");
	set("long", 
	"��ɰ��İ��������غ��ش���ҽ��ᣬ�����ˡ�\n");
	set("gender", "����");
	set("age", 46);
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
	set("combat_exp", 1800000 + random(500000)); 
	 set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	set_skill("force", 130);
	set_skill("huntian-qigong", 130);
	set_skill("dodge", 180 + random(50));
	set_skill("xiaoyaoyou", 270 + random(50));
	set_skill("unarmed", 180 + random(50));
	set_skill("jingang-quan", 270 + random(50));
	set_skill("parry", 180 + random(50));
	set_skill("kuangfeng-blade", 270 + random(50));
	set_skill("blade", 180 + random(50));
	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "kuangfeng-blade");
	map_skill("unarmed", "changquan");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield(); 
	add_money("silver", 50);
}
#include "npc.h"
