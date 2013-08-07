// /d/yixing/npc/fanyifei.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit F_UNIQUE;
inherit NPC;

void create()
{
	set_name("��һ��", ({ "fan yifei", "fan"}));
	set("title", HIB "�ױ���������" NOR);
	set("long", "����һ�����ݵ����ߣ�һ�ź�������������й�
�ʣ��˳ơ��ɶ��ס���\n");
	set("gender", "����");
	set("age", 51);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_qi", 1000);
	set("max_jing", 200);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("dagger", 50);
	set_skill("shigu-bifa", 50);
	set_skill("lingxu-bu",50);
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "shigu-bifa");
	map_skill("dagger", "shigu-bifa");

	set_temp("apply/attack", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);
	set("chat_chance", 3);
	set("chat_msg", ({
		"��һ��˵�������ְ��˾ͽ����밳���й����Ľ��飬����ȥ�ݷ������˼ҡ�\n",
	}) );

	set("inquiry",([
		"������" : "�´�������������������������ҪѨ����һ�㡣",
		"���ְ�" : "��Ҳ��Ҫ�����ְ��ɽ��",
		"˾ͽ���" : "˾ͽ�����¾����ֵ��ҵ��¡�",
		"˾ͽ��" : "��˵���ְ�ļ������ҷ��Ϻ���������",
	]));
	setup();
	carry_object("/d/meizhuang/npc/obj/panguan-bi")->wield();
	carry_object("/clone/misc/cloth")->wear();
}


