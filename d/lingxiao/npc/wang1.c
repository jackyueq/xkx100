// Npc: /d/lingxiao/npc/wang-wanyi.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC; 

void create()
{
	set_name("������",({"wang wanyi","wang"}));
	set("nickname", HIG"���Ϸ�"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", "���������ǵ��������ӹ����ӣ��������������Ṧ������\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 40);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("max_qi", 2000);
	set("qi", 2000);
	set("jiali", 50);
	set("inquiry", ([
	    "dodge"  : "�ҵ��Ṧ�𡭡������������ǣ��������Ṧ�ĺõط���\n��ү�ӻ���֪�������ı���������һ���ö�����",
	    "�Ṧ"   : "�ҵ��Ṧ�𡭡������������ǣ��������Ṧ�ĺõط���\n��ү�ӻ���֪�������ı���������һ���ö�����",
	]) ); 
	set("combat_exp", 200000);
	set("shen_type", 1);
	set("score", 20000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 120);
	set_skill("sword", 120);
	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("dodge", 300);
	set_skill("literate", 80);

	set_skill("xueshan-sword", 120);
	set_skill("bingxue-xinfa", 120);
	set_skill("snow-strike", 120);
	set_skill("snowstep", 300);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("������", 6, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
} 

