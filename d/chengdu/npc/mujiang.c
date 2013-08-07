// mujiang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��ľ��", ({ "zhang mujiang", "mujiang", "zhang" }));
	set("str", 20);
	set("gender", "����");
	set("age", 43);
	set("long", "���Ǹ����ո߳���ľ������˵����Ϊ�������¡�\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("inquiry", ([
		"name": "С�����ţ��ڳɶ�Ҳ��һ���������ˡ�",
		"ľ��": "˵��ľ����ǿ��Ǵ�����о��ĳɹ�Ŷ��",
		"������": "��....�Ұ���������뱲�ӣ�����.......",
	]));
	set("vendor_goods", ({
		WEAPON_DIR"staff/muzhang",
		WEAPON_DIR"rake/mupa",
		WEAPON_DIR"spear/muqiang",
		WEAPON_DIR"hammer/muchui",
		WEAPON_DIR"blade/mudao",
		WEAPON_DIR"sword/mujian",
		WEAPON_DIR"stick/mugun",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

