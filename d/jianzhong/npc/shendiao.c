//shendiao.c

inherit NPC;

void create()
{
	set_name("���", ({ "shen diao", "diao" }) );
	set("race", "����");
	set("subrace", "����");
	set("age", 20);
	set("long", @LONG
    ����������ޣ����˻��ߣ���ò��ª֮����ȫ����ë������
�䣬���Ǳ��˰�ȥ��һ����Ƶģ�ëɫ�ƺڣ��Ե����ǰ��࣬��
����������ͷ��������Ѫ��Ĵ�������˫����֣��������̡�
LONG
);
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
		"�����������ȥ��ֻ�Ǹ�������������һ���������š�\n",
		"���ʱ�������ȴ�����̣���֪��η��裬���Ĵ�����ɷ硣\n",
		"���ͻȻ�������У�����΢��˻�ƣ�����Խ����������������\n",
	}));
       set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("str", 86);
	set("cor", 80);
	set("limbs", ({ "ͷ��", "����", "���", "�ҳ�", "��צ", "��צ" }) );
	set("verbs", ({ "poke", "claw", "wind" }) );

	set("combat_exp", 2000000);

	set_skill("dodge",100);
	set_skill("parry",100);

	set_temp("apply/attack", 120);
	set_temp("apply/damage", 120);
	set_temp("apply/armor", 120);
	set_temp("apply/defence",120);
	setup();
}


