// majiajun.c ��ҿ�

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��ҿ�", ({ "ma jiajun", "ma", "jiajun"}));
	set("gender", "����");
	set("age", 35);
	set("long", 
"��һ����������þ��⣬��Ŀ��ΪӢ������ʱ��ʱ����
��ѹ�â�£�����һƬ�Ұף�ȫ��Ѫɫ�������ǰ���ʦ
���߶������ܳ�����˲���װ��ɼ�үү����ҿ���\n");
	set("combat_exp", 50000);
	set("shen_type", 1);

	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 10);

	set_skill("force", 40);
	set_skill("sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set("inquiry", ([
		"������" : "���ʵ��ǰ���ɡ�\n",
	]) );

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

