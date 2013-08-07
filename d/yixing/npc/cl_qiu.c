// /d/yixing/npc/cl_qiu.c ��ɽ��
// Last Modified by winder on Jul. 12 2002

#define TUCHAN "/d/yixing/obj/cl_tuchan"

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("��ɽ��", ({ "qiu shanfeng", "qiu" }));
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "����������");
	set("long", "����һλ��ʮ����ı��δ󺺡�\n");
	set("gender", "����");
	set("age", 32);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 28);
	set("dex", 25);

	set("max_qi", 700);
	set("max_jing", 400);
	set("max_neili", 600);
	set("neili", 600);
	set("jiali", 30);
	set("combat_exp", 150000);
	set("score", 7000);
/*
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("cuff",  90);
	set_skill("club",  100);

	set_skill("ding-force", 90);
	set_skill("wuxingbu", 90);
	set_skill("wuxing-quan", 90);
	set_skill("wuhu-gun", 100);

	map_skill("force", "ding-force");
	map_skill("dodge", "wuxingbu");
	map_skill("cuff", "wuxing-quan");
	map_skill("parry", "wuhu-gun");
	map_skill("club", "wuhu-gun");

	prepare_skill("cuff", "wuxing-quan");
*/
	set("inquiry", ([
		"���ְ�" : "������ǳ��ְ��ܶ����ڵء�",
		"˾ͽ��" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
		"������" : "�������Դ��ҵ�������һ��ǧ�������������",
		"����" : "��λ�����������ɰ������˼�˵���㡣",
		"����ʯ" : "������ڱװ��Ϳ๦�ߣ��ĵð������Ρ�",
		"����" : "�ҼҰ���˾ͽ��ү�������ϵġ������족Ҳ��",
	]));

	setup();
	carry_object(WEAPON_DIR"sword/panguanbi")->wield();
}

int accept_object(object who, object ob)
{
	if( base_name(ob) != TUCHAN )
		return notify_fail(name() + "���˰��֣�˵�����㻹���Ը��������ðɡ�\n");

	command("joythank " + who->query("id"));
	who->set_temp("changle", 1);
	call_out("do_destroy", 1, ob);
	return 1;
}

void do_destroy(object ob)
{
	if( ob ) destruct(ob);
}
