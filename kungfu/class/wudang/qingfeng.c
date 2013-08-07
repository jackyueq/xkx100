// qingfeng.c

inherit NPC;

void create()
{
	set_name("���", ({ "qing feng", "qing", "feng" }));
	set("long", "�����䵱ɽ��С��ͯ��\n");
	set("gender", "����");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("wudang-quan", 20);
	map_skill("parry", "wudang-quan");
	map_skill("unarmed", "wudang-quan");
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	set("inquiry", ([
		"���" : "ƶ��������磬��֪��λ"+ RANK_D->query_respect(this_player())+"�кμ��̣�",
		"�䵱" : "ƶ�������䵱�ɵ��ӣ���֪��λ"+ RANK_D->query_respect(this_player())+"�кμ��̣�",
		"�䵱��" : "ƶ�������䵱�ɵ��ӣ���֪��λ"+ RANK_D->query_respect(this_player())+"�кμ��̣�",
		"���޼�" : "Сʦ�壿������֪�������ڲ�����û�У���Ҷ�������������",
		"������" : "��ʦү�������棬��֪��λ"+ RANK_D->query_respect(this_player())+"�Ƿ���Ҫ����������ʦү?",
	]));

	create_family("�䵱��", 5, "����");
	setup();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}
