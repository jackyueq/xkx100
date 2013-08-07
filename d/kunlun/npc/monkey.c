// Npc: /d/kunlun/npc/monkey.c
// Last Modified by winder on Jun. 29 2001

inherit NPC;

void create()
{
	set_name("����", ({ "monkey" }) );
	set("gender", "����");
	set("race", "����");
	set("age", 5);
	set("long", "��ֻ���������������������£�����ʱ�����ζ�ؿм��������ҡ�\n");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("water", 200);
	set("food", 200);

	set("apply/attack", 10);
	set("apply/defense", 10);

	set("chat_chance", 2);
	set("chat_msg", ({
		"���ӳ������������ߴߴ����һ���ҽ�......!\n",
		"���Ӻ�Ȼ���˹�����һ��������ǰצһ��ժ����Ĳ�ñ!\n",
		"���Ӻ��һ��һ�����������������������������һ����!\n",
	}) );

	setup();
}
