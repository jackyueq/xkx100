//NPC /d/city/npc/geji.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("���", ({ "ge ji", "ji" }));
	set("long", "����������������ĸ�ˣ����ղ�����\n");
	set("gender", "Ů��");
	set("age", 17);
	set("attitude", "friendly");
	set("shen_type", 1);

	set("per", 27);
	set("str", 15);
	set("int", 14);
	set("con", 15);
	set("dex", 16);
	set("qi", 100);
	set("max_qi", 100);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 10);
	set("max_neili", 10);
	set("combat_exp", 500);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);

	set("chat_chance", 10);
	set("chat_msg", ({
		"�����ת������
����ɽ����ˮ�������ﾡ���ϲ�ľ�򡣶�ʮ��������ҹ�����˺δ��̴����\n",
		"��������ͳ���
�����ǽ����ؾ��У�������ϸ�����ᡣʮ��һ�������Σ�Ӯ����¥����������\n",
		"�������ǳ����
���Ƿ�ţ����������������������⡣����·�㣬ݺ����������ʮ�ﴺ�硣
��������硣ҷ�մ����ϣ��ɸ���ӡ����봹������ϱ������С���\n",
		"�������ǳ����
����ɽ��Զ�䣬��ˮ�����̡���Ӱ��¥̨�����������ˡ�˭֪徹��⣬����
��«�ݡ�ʱ����ױ�ˣ���ȹҷ��������\n",
		(: random_move :)
	}) );

	setup();
	carry_object(CLOTH_DIR+"cloth/qi-dress")->wear();
}
