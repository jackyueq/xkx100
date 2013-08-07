// laoban.c �ϰ� 

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�ϰ�", ({ "lao ban", "boss" }));
	set("shen_type", 1);
	set("gender", "����");
	set("age", 45);
	set("long","�ϰ����������������������˼�ʮ���С���������µľ�����ؤ�����ˡ����������������ֲ�������Զ�ߣ�����ʲô�취�أ���\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/xingxiu/obj/fire",
		WEAPON_DIR"muchui",
		WEAPON_DIR"club",
		ARMOR_DIR"beixin",
		ARMOR_DIR"huwan",
		ARMOR_DIR"huxin",
		ARMOR_DIR"huyao",
		ARMOR_DIR"huzhi",
		ARMOR_DIR"niupi",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("�ϰ�������Ц��˵������λ" + RANK_D->query_respect(ob) + "����лݹˣ���㿴��Ҫ��ʲô��\n");
}

