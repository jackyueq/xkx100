// Room: /d/nanyang/npc/boss.c
// Last Modified by winder on Nov. 20 2001

#include <ansi.h>;

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("���ӷ�", ({ "fan zifa","fan","seller"}) );
	set("gender", "����" );
	set("age", 46);
	set("long", "���ӷ������С�̺ŵ��ϰ壬д��һ�ֺ��֡�\n");
	set("chat_chance", 20);
	set("chat_msg", ({
		"���ӷ������������������ǡ���\n",
		"���ӷ������������Ǳ�����ԭ���϶ɺ�ˮ���͹���ȥ����ѽ����\n",
	}));
	set("chat_chance_combat", 20);
	set("chat_msg_combat",({
		"���ӷ������������ʲô�����������������\n",
		"���ӷ��ߴ�ߺ������ҿ�����ɽ�ɵĺ��ˣ��㾹��ɱ�ң���������\n",
	}) );
	set("inquiry", ([
		"here"   : "�����������ǣ��������������������Ү��",
	]) );
	set("attitude", "friendly");
	set("rank_info/respect", "�ϸ�");
	set("rank_info/rude","�����˵�");
	set("vendor_goods", ({
		__DIR__"obj/zheshan",
		__DIR__"obj/jiuhulu",
		__DIR__"obj/jiutan",
		__DIR__"obj/xianbing",
	}) );
	set("combat_exp",100);
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision("���ϰ�Ц������ӭ��ǰ����˵�������͹٣�����������\n",ob);
}
