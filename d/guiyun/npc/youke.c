// Npc: /d/guiyun/npc/youke.c �ο�
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("�ο�", ({ "you ke", "you", "ke" }));
	set("gender", "����");
	set("age", 28);
	set("long", "����һ������������ˣ��ƺ��Ѿ�������ɽˮ֮�С�\n");
	
	set("combat_exp", 3500);
	set("shen_type", 0);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 25);
	set_skill("dodge", 25);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set("inquiry",([
		"name" : "��ֻ��һ��С��ɫ�������������ԣ�",
	]));

	set("chat_chance",10);
	set("chat_msg",({
		"�ο�ҡͷ���Ե�����������֮�ⲻ�ھƣ��ں�ɽˮ֮��Ҳ��\n",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
