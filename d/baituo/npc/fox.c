// fox.c
// Last Modified by Winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("����", ({ "fox", "huli", "hu" }) );
	set("race", "����");
	set("age", 4);
	set("long", "һֻ���ɳ��Եĺ��ꡣ\n");
	set("attitude", "peace");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 90);
	set_temp("apply/armor", 10);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"�������Ų��Ų�����ǽ䱸�����顣\n",
		"������Ŷ��ɵ��۹���㿴��ȫ��һ���ܽ��ŵ�ģ����\n",
	}) );
}

