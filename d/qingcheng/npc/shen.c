// shen.c

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("���˿�", ({ "shen renjun", "shen", "renjun" }));
	set("gender", "����");
	set("age", 25);
	set("long", "�����Ǻͼ���ͨ���ϲ�������˿���\n");

	set("combat_exp", 60000);
	set("shen_type", -1);

	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("strike", 60);
	set_skill("unarmed", 00);
	set_skill("force", 60);
	set_skill("bixie-sword", 60);
	set_skill("songfeng-jian", 60);
	set_skill("chuanhua", 60);
	set_skill("wuying-leg", 60);
	set_skill("cuixin-strike", 60);
	set_skill("qingming-xuangong", 60);
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

