// npc: /d/city/npc/libailv.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name( YEL "����" NOR, ({ "peng baoxian","peng","baoxian" }) );
	set("gender", "����" );
	set("title", "����ʹ����ϰ�");
	set("age", 49);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϸ�");
	set("rank_info/rude","�����˵�");
	set("long", @LONG
���ϰ���������ʹ��������ݳ�Ҳ�������������������Ʒ�Ĺ˿ͺ�
�࣬�������������Ǻܽ��ţ��ⲻ�����ϰ嶼���������ˡ�����һ�߸�
һ���˿����ʣ�һ�߻ش�����һ���˿͵���Ѷ������ʱ��ͷ�Ի�ƷԸ�
Щʲô��
LONG);
	set("chat_chance", 30);
	set("chat_msg", ({
		"���ϰ������ô�����͹٣������������ӳ���ô��\n",
		"���ϰ���������͹٣������ϲ���ҪǮ��\n",
		"���ϰ�������ȵȣ������æ���˾͹�����\n",
		"���ϰ壺��һ�ưգ��͹٣���֪����ү�ҵĹ�Ʒ����С�깩Ӧ�ġ�\n",
	}));
	set("inquiry", ([
		"�ʹ�" : "�����ǰ��ǰ���С������ʹ�Ӧ�о��У������ɣ�",
		"here" : "�ף����ҿ��ˣ�������ʹ��̡�������Ʋ��������ŵ�ô��",
	]) );
	set("vendor_goods", ({
		FRUIT_DIR+"banana",
		FRUIT_DIR+"banli",
		FRUIT_DIR+"boluo",
		FRUIT_DIR+"caomei",
		FRUIT_DIR+"foshou",
		FRUIT_DIR+"ganzhe",
		FRUIT_DIR+"guiyuan",
		FRUIT_DIR+"hamigua",
		FRUIT_DIR+"hetao",
		FRUIT_DIR+"hongzao",
		FRUIT_DIR+"juzi",
		FRUIT_DIR+"lemon",
		FRUIT_DIR+"laiyangli",
		FRUIT_DIR+"lizhi",
		FRUIT_DIR+"lizi",
		FRUIT_DIR+"mangguo",
		FRUIT_DIR+"pipa",
		FRUIT_DIR+"putao",
		FRUIT_DIR+"shiliu",
		FRUIT_DIR+"shizi",
		FRUIT_DIR+"taozi",
		FRUIT_DIR+"xianggua",
		FRUIT_DIR+"xigua",
		FRUIT_DIR+"xingzi",
		FRUIT_DIR+"yali",
		FRUIT_DIR+"yangmei",
		FRUIT_DIR+"yingtao",
	}) );
	set("combat_exp", 10000);
	set_skill("unarmed", 22);
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}

void init()
{
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision("���ϰ����ߺ�ȵ�����ʱ���ʹ����������У���Ǯ������ͯ�����ۣ���\n",ob);
	return;
}
