// lion.c
// Last Modified by Winder on May. 15 2001

inherit NPC;

void create()
{
	set_name("��ʨ", ({ "lion", "xiongshi", "shi" }) );
	set("race", "����");
	set("age", 15);
	set("long", "һֻ�ý�����ʨ��ʮ�����硣\n");
//	set("attitude", "aggressive");
	set("attitude", "peace");
	set("shen_type", -1);
	set("combat_exp", 400000);
	set_temp("apply/attack", 300);
	set_temp("apply/defense", 300);
	set_temp("apply/damage", 150);
	set_temp("apply/armor", 50);

	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"��ʨһ���������´���������졣\n",
		"��ʨ����һ�ţ��͵�һԾ�������ǰ��\n",
	}) );
}

