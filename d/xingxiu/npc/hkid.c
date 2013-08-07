// Room: /d/xingxiu/npc/hkid.c
// Last Modified by Winder on Apr. 25 2001

inherit NPC;

void create()
{
	set_name("��ͯ", ({ "mutong", "kid"}));
	set("gender", "����");
	set("age", 8 + random(5));
	set("long", "һ����ͯ������ʮ��ֻ��\n");
	set("attitude", "friendly");
	set("env/wimpy", 60);
	set("combat_exp", 200);

	set_skill("unarmed", 5);
	set_skill("dodge", 5);
	set_skill("parry", 5);
	set_skill("whip", 5);

	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	
	setup();
	set("chat_chance", 2);
	set("chat_msg", ({
	      "��ͯ���ߵ��µ����ǰ������ɵ���������������˫�ס�\n",
	      "��ͯ���췢�ģ��Ҵ���һ��Ҫ����\n",
	}));
}

