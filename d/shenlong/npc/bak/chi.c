// chi.c �����ŵ���
// Last Modified by winder on Jul. 12 2002

inherit NPC;

void create()
{
	set_name("�����ŵ���", ({ "chilong dizi","dizi" }) );
	set("gender", "Ů��");
	set("age", 15+random(10));
	set("long", "���ǳ����ŵ��ӣ���Ͷ���С���ƺ��������¡�\n");
	set("combat_exp", 1800+random(20000));
	set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack", 15);
	set("apply/defense", 15);

	set("chat_chance", 5);
	set("chat_msg", ({
		"����˵�����������ͨ���ӣ��ڵ��������ٱ�����һ���٣��԰ٵ���\n",
		"����˵�����������Ŀ��磬�����ķ���\n",
		"����˵�����ҵ���ɱ�л��̣�������׼���Σ�����ʥְ��\n",
		"����˵�����ҽ̵��ӻ��̶�����ͬ�����á�\n",
	}) );

	set_skill("sword", 15+random(50));
	set_skill("unarmed", 15+random(50));
	set_skill("parry", 15+random(50));
	set_skill("dodge", 15+random(50));
	set_skill("strike", 15+random(50));

	create_family("������", 4, "����");

	setup();
	switch( random(5) )
	{
		case 0:
			carry_object(WEAPON_DIR"sword/houjian")->wield();
			break;
		case 1:
			carry_object(WEAPON_DIR"sword/changjian")->wield();
			break;
		case 2:
			carry_object(WEAPON_DIR"sword/duanjian")->wield();
			break;
		case 3:
			carry_object(WEAPON_DIR"sword/kuojian")->wield();
			break;
		case 4:
			carry_object(WEAPON_DIR"sword/xijian")->wield();
			break;
	}

	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("coin", 20);
}
