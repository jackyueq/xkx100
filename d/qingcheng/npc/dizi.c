// dizi.c 

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("��ǵ���", ({ "qingcheng dizi", "dizi" }));
	set("gender", "����");
	set("age", 20);
	set("long", "���ǡ�����ɡ�����һ�����ӡ�\n");

	set("combat_exp", 30000);
	set("shen_type", -1);

	set_skill("sword", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("strike", 30);
	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("bixie-sword", 30);
	set_skill("songfeng-jian", 30);
	set_skill("chuanhua", 30);
	set_skill("wuying-leg", 30);
	set_skill("cuixin-strike", 30);
	set_skill("qingming-xuangong", 30);
	map_skill("force", "qingming-xuangong");
	map_skill("unarmed", "wuying-leg");
	map_skill("strike", "cuixin-strike");
	map_skill("dodge", "chuanhua");
	map_skill("parry", "bixie-sword");
	map_skill("sword", "songfeng-jian");
	prepare_skill("unarmed", "wuying-leg");
	prepare_skill("strike", "cuixin-strike");
	create_family("�����", 6, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
