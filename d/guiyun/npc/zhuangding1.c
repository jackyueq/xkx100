// Npc: /d/guiyun/npc/zhuangding1.c ׯ��
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("ׯ��", ({ "zhuang ding", "zhuang", "ding" }));
	set("gender", "����");
	set("age", 32);
	set("long", "���ǹ���ׯ��ׯ����\n");
	
	set("combat_exp", 4000 + random(300));
	set("shen_type", 0);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_temp("apply/attack", 16);
	set_temp("apply/defense", 15);
	set("max_qi", 170);
	set("max_jing", 170);
	set("neili", 240);
	set("max_neili", 240);
	set("jiali", 8);

	set("inquiry",([
		"name" : "��ֻ��һ��С��ɫ�������������ԣ�",
	]));
	setup();
	set("chat_chance",10);
	set("chat_msg",({
		"ׯ��������Ц��Ц���������䣬�������������Ͳ��ؾ�����\n",
	}));
	carry_object("/clone/misc/cloth")->wear();
}
