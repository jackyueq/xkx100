// /d/yixing/npc/shijian.c �̽�
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("�̽�", ({ "shijian" }));
	set("long","���ǳ��ְ�����СѾ�ߣ���������Բ�Σ���Ҳ���Ŀ�ϲ��\n��ͷ���Լ����ɣ�ѩ�׵ĳ���̤��һ˫�廨��Ь�С�\n");
	set("gender", "Ů��");
	set("age", 16);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 20);
   
	set("max_qi", 500);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 10);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 40);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 20);

	setup();
	carry_object("/d/city/obj/pink_cloth")->wear();
}
