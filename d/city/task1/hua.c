// hua.c ����Ӱ
inherit NPC;
 
void create()
{
	set_name("����Ӱ", ({ "hua  jianying"}));
	set("nickname", "���Ǹ���");
	set("long","������һ�����������֣��е���ģ��׾���Ƥ��������һ����������ͻ��һ�磬һ����ͷ�����˰�磬������һλ��òӢ���������ϧ����ƽƽ����ʱ�����һЩ·�͡�\n");
	set("gender", "����");
	set("age", random(10) + 25);
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
	set("combat_exp", 400000 + random(40000)); 
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	
	set_skill("force", 60);
	set_skill("dodge", 100 + random(50));
	set_skill("tiezhang-zhangfa", 150 + random(50));
	set_skill("shuishangpiao",150 + random(50));
	set_skill("strike", 100 + random(50));
	set_skill("unarmed", 100 + random(50));
	set_skill("parry", 100 + random(50));
	set_skill("literate", 20);
	set_skill("sword",100 + random(50));
	set_skill("changge-jian",150 + random(50));
	map_skill("sword","changge-jian");
	map_skill("strike","tiezhang-zhangfa");
	map_skill("parry","tiezhang-zhangfa");
        map_skill("dodge","shuishangpiao");
        
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
