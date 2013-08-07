// npc: /d/city/npc/libailv.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name( YEL "�����" NOR , ({ "li bailv","li","bailv" }) );
	set("age", 43);
	set("title", "���˿Ь���ϰ�");
	set("long", @LONG
�������һ����С�ĺ��ӣ��������ģ�����ȴ���о��񡣴��۾����
�ܿ������Ǹ������������ˡ����������Ь����ϰ塣
LONG
	);
	set("chat_chance", 40);
	set("chat_msg", ({
		"���ϰ��������������ݳ����������Ļ������簡��\n",
		"���ϰ����˵�𱾸��ĳ���ү����������һ��һ�Ĵ���ӣ���ѧ�ʣ�\n",
		"���ϰ�����ٺ٣��͹٣������˵�����찡���չ��չ�С�϶������Ⱑ��\n",
		"���ϰ�����͹٣������ƣ���˫˿Ь����ʰ����������ԣ����Ұ������ϣ���ô����\n",
	}));
	set("inquiry", ([
		"˿Ь" : "������Ҫ��˿Ь�ǰɣ�û���⣬�ۼҵ�Ь�����ݳ���ͷһ�ݣ�\n",
		"here" : "�����ݳǰ������Ǵ��ϱ�ͷһ��������ȥ����\n",
	]) );
	set("vendor_goods", ({
		BOOT_DIR+"maxie",
		BOOT_DIR+"pixue",
		BOOT_DIR+"sifeng_huangxue",
		BOOT_DIR+"sifeng_kuanxue",
		BOOT_DIR+"sixie",
		BOOT_DIR+"baodi_kuaixue",
		BOOT_DIR+"xiuhua_xie2",
		BOOT_DIR+"zihua_xie",
		BOOT_DIR+"gongxie",
		BOOT_DIR+"caoxie",
	        BOOT_DIR+"flower_shoe",
	}) );

	set("attitude", "friendly");
	set("rank_info/respect", "�ϸ�");
	set("rank_info/rude","�����˵�");
	set("combat_exp",100);
	set_skill("unarmed", 5);
	setup();
	carry_object( "/clone/cloth/male-cloth")->wear();
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
	message_vision( "���ϰ������ӭ���������͹٣�����˫Ь����������Ҫ����������ɫô����\n",ob);
	return;
}
