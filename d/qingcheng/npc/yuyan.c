// yuyan.c 

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("������", ({ "yu renyan", "yu", "renyan" }));
	set("gender", "����");
	set("age", 20);
	set("long", "�����ǡ�����ɡ���������׺��Ķ������ӡ�������ʵ�ںܲ�������\n");

	set("combat_exp", 40000);
	set("shen_type", -1);

	set_skill("sword", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("strike", 40);
	set_skill("unarmed", 00);
	set_skill("force", 00);
	set_skill("bixie-sword", 40);
	set_skill("songfeng-jian", 40);
	set_skill("chuanhua", 40);
	set_skill("wuying-leg", 40);
	set_skill("cuixin-strike", 40);
	set_skill("qingming-xuangong", 40);
	map_skill("force", "qingming-xuangong");
	map_skill("unarmed", "wuying-leg");
	map_skill("strike", "cuixin-strike");
	map_skill("dodge", "chuanhua");
	map_skill("parry", "bixie-sword");
	map_skill("sword", "songfeng-jian");
	prepare_skill("unarmed", "wuying-leg");
	prepare_skill("strike", "cuixin-strike");
	map_skill("parry", "bixie-sword");
	map_skill("sword", "bixie-sword");
	create_family("�����", 6, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
