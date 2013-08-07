// yuanshang.c
// Last Modified by winder on May. 29 2001

#include "/kungfu/class/nanshaolin/yuan.h";
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("Ԫ��", ({ "yuan shang", "shang", "yuan" }));
	set("long","����һλ���ݺ��У���һϮ�಼������ġ�̫��Ѩ΢͹��˫Ŀ��������\n");
	set("nickname", "��ĦԺ������ɮ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 30);
	set("dex", 20);
	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 3000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("zhanzhuang-gong", 100);
	set_skill("dodge", 100);
	set_skill("yiwei-dujiang", 100);
// basic skill begin
	set_skill("shaolin-cuff", 100);
	set_skill("luohan-cuff", 100);
	set_skill("weituo-strike", 100);
	set_skill("sanhua-strike", 100);
	set_skill("boluomi-hand", 100);
	set_skill("jingang-strike", 100);
// basic skill end
// �֡�צ��������
	set_skill("hand", 100);
	set_skill("fengyun-hand", 100);
	set_skill("qianye-hand", 100);
	set_skill("claw", 100);
	set_skill("jimie-claw", 100);
	set_skill("staff", 100);
	set_skill("pudu-staff", 100);
	set_skill("wuchang-staff", 100);
	set_skill("club", 100);
	set_skill("weituo-club", 100);
	set_skill("zui-club", 100);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("hand", "boluomi-hand");
	map_skill("claw", "jimie-claw");
	map_skill("staff", "wuchang-staff");
	map_skill("club", "zui-club");
	map_skill("parry", "zui-club");

	prepare_skill("hand", "boluomi-hand");
	prepare_skill("claw", "jimie-claw");

	create_family("��������", 20, "����");

	setup();
	carry_object(WEAPON_DIR+"staff/chanzhang")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	object ob;

	::init();
	add_action("do_nod", "nod");
}

