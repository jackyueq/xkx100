inherit NPC;
#include <ansi.h>

void create()
{
	set_name("������", ({ "feng xifan", "feng" }) );
	set("nickname", HIR"һ����Ѫ"NOR);
	set("gender", "����");
	set("age", 45);
	set("long",
		 "����������ƽ�������ӳ��������ɵ�һ���֣�һ�Ű�տտ����Ƥ��\n"
		 "̨��ս�ܺ�齵��͢������Ϊһ���ҳ�����");
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 30);
	set("max_qi",2000);
	set("max_jing",1200);

	set("shen_type", -1);
	set("combat_exp", 1000000);

	set_skill("hand", 180);
	set_skill("sword", 160);
	set_skill("cuff", 180);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("literate", 100);
	set_skill("changge-jian", 180);
	set_skill("changquan", 170);
	set_skill("sanshou", 170);

	map_skill("sword", "changge-jian");
	map_skill("parry", "changge-jian");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");
	create_family("������", 3, "����");
	setup();

	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
}

