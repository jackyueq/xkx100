// Npc: /d/guiyun/npc/zhuangding3.c ׯ��
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("ׯ��", ({ "zhuang ding", "zhuang", "ding" }));
	set("gender", "����");
	set("age", 34);
	set("long", "���ǹ���ׯ��ׯ����\n");
	
	set("combat_exp", 5000 + random(500));
	set("shen_type", 0);
	set("max_qi", 200);
	set("max_jing", 200);
	set("neili", 290);
	set("max_neili", 290);
	set("jiali", 9);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_temp("apply/attack", 18);
	set_temp("apply/defense", 18);

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
