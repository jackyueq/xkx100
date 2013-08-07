// /d/yixing/npc/zhan.c չ��
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("չ��", ({ "zhan fei", "zhan" }));
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "����������");
	set("long", "����һ���������µĺ��ӡ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 700);
	set("max_jing", 400);
	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 30);
	set("combat_exp", 120000);
	set("score", 6000);

	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("strike", 90);
/*
	set_skill("ding-force", 90);
	set_skill("wuxingbu", 90);
	set_skill("cuixin-zhang", 90);

	map_skill("force", "ding-force");
	map_skill("dodge", "wuxingbu");
	map_skill("strike", "cuixin-zhang");
	map_skill("parry", "cuixin-zhang");

	prepare_skill("strike", "cuixin-zhang");
*/
	set("inquiry", ([
		"���ְ�" : "��Ϊ���ְ︰������ʮ���꾹�������³���",
		"˾ͽ��" : "��������������������֪Ҫ��ʲô���͹ŹֵĻ�������ĥ�ң�",
		"����"   : "��������������������֪Ҫ��ʲô���͹ŹֵĻ�������ĥ�ң�",
		"������" : "û���ҵĹ�Ͻ���������ۿ�Ҫ���ˡ�",
		"����ʯ" : "������ڱװ��Ϳ๦�ߣ��ĵð������Ρ�",
		"����"   : "��λ�����������ɰ������˼�˵���㡣",
	]));

	setup();
}
