// Npc: /d/guiyun/npc/guanjia.c �ܼ�
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("�ܼ�", ({ "guan jia", "guanjia", "guan", "jia" }));
	set("gender", "����");
	set("age", 44);
	set("long", "���ǹ���ׯ�Ĺܼң������ճ���ׯ��\n");
	
	set("combat_exp", 8000);
	set("shen_type", 0);
	set("max_qi", 210);
	set("max_jing", 210);
	set("neili", 310);
	set("max_neili", 310);
	set("jiali", 10);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 35);
	set_skill("dodge", 35);
	set_temp("apply/attack", 24);
	set_temp("apply/defense", 22);

	set("inquiry",([
		"name" : "�ȣ���ô�鷳��ʲô����������ֱ���ܼҺ��ˡ�",
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
