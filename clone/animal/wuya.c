// wuya.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("��ѻ", ({ "wuya", "crow" }) );
	set("race", "����");
	set("age", 3);
	set("long", "һֻ��ɫ����ѻ����ª���ˡ�\n");
	set("attitude", "peaceful");

	set("combat_exp", 300);
	set_temp("apply/attack", 3);
	set_temp("apply/defense", 5);
	set_temp("apply/armor", 1);

	setup();

	set("chat_chance", 10);
	set("chat_msg", ({
		"��ѻ���¸¡����˼�����\n",
		"��ѻ�е������¸¡���\n",
		"��ѻ������ǰ���Ϸ��¡�\n",
	}) );
}
