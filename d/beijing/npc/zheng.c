// /beijing/npc/zheng.c
// Last modified by winder 2003.10.10

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("֣��ˬ", ({ "zheng keshuang", "zheng" }));
	set("title", HIC"һ�Ⱥ��ι�"NOR);
	set("long", "����һ��������������ͷ����ͷ�����ף���ɫ�㲲�����\n"
		"��ϸ�ٿ���������͵�Ҳ����ô�ϣ�ֻ�ǳ�ü�������۽�\n"
		"�߶������ƣ�������˶��룬Ҳ�ѻ��ף�������һ����ȴ\n"
		"����֣��ˬ��˭\n");
	set("gender", "����");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 50);
	set("int", 40);
	set("con", 40);
	set("per", 40);
	
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 100000);

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	setup();
	carry_object("/d/beijing/obj/goldcloth")->wear();
}

