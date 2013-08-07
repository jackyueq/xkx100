// npc: /d/city/npc/bookboss.c
// Last Modified by Winder on Jul. 15 2000

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("���Ϲ�", ({ "feng laogou","feng" }) );
	set("title","����ϰ�");
	set("gender", "����" );
	set("age", 38);
	set("long", "���ϰ�С���Ϲ�������һ����֪�����Ǹ����Ĺ���֮�ˣ�һ�����鷷��Ϊ����Ҳ��Ϊ�Եá�\n");
	set("attitude","friendly");
	set("inquiry",([
		"��"   : "������ʲô�鶼�У�������ʲô��\n",
		"here" : "�����һ������������������ĵ��̡�\n",  
	]));
	set("vendor_goods",({
		"/clone/book/lbook1",
		"/clone/book/lbook2",
		"/clone/book/lbook6",
		"/clone/book/lbook7",
		"/clone/book/lbook8",
		"/clone/book/blade_book0",
		"/clone/book/blade_book1",
		"/clone/book/dodge_book1",
		"/clone/book/dodge_book2",
		"/clone/book/sword_book1",
		"/clone/book/cuff_book",
		"/clone/book/unarmed_book",
	}));
	set("chat_chance", 15);
	set("chat_msg",(
	{
	    "�ϰ���������һ�Ѽ�ë���ӣ����ᵧȥǽ�ϣ�����ϵĳ�����\n",
	    "�ϰ�Ц���ʵ��������飿���ǿ����ֻ�������\n",
	}));
     
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}
void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}
