// /d/yixing/npc/cl_bangzhong.c ����
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("����", ({ "changle bangzhong", "bangzhong" }));
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "������");
	set("long", "����һ������Ϊ�������ĳ��ְ��ڡ�\n��������ת���ƺ�������ʲô�����⡣\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 300);
	set("max_jing", 200);
	set("max_neili", 100);
	set("neili", 100);
	set("combat_exp", 20000);
	set("score", 1000);

	set_skill("force", 50);
	set_skill("dodge", 40);
	set_skill("cuff", 50);
	set_skill("parry", 50);

	set("inquiry", ([
		"���ְ�" : "������ǳ��ְ��ܶ����ڵء�",
		"˾ͽ��" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
		"������" : "�������Դ����������κ�һ��ǧ�",
		"������" : "��������Ӵ����ˡ�",
		"��ɽ��" : "��������Ӵ����ˡ�",
		"����" : "��λ�����������ɰ������˼�˵���㡣",
		"����ʯ" : "������ڱװ��Ϳ๦�ߣ��ĵð������Ρ�",
		"����" : "�ҼҰ���˾ͽ��ү�������ϵġ������족Ҳ��",
	]));

	setup();

 	carry_object("/clone/weapon/changjian")->wield();
}
