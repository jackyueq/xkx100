// liusanshun.c ����˳
// Last Modified by Winder on Jul. 15 2000

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����˳", ({ "liu sanshun","liu" }) );
	set("title","���");
	set("gender", "����" );
	set("age", 18);
	set("long", "����˳������������չ͵Ļ�ƣ��ֽ���������ǰ�ܺ�ģ����ϰ�ʡ�˲����ġ�\n");
	set("attitude","friendly");
	set("inquiry",([
		"����":"С��ר�����������������\n",
		"here":"�����Ҽ���ү�ĵ��̣�С���������ģ��������չ����⡣\n",
		"�˴�":"�����Ҽ���ү�ĵ��̣�С���������ģ��������չ����⡣\n",
	]));
	set("vendor_goods",({
		__DIR__"obj/zhubang2",
		__DIR__"obj/zhudao2",
		__DIR__"obj/zhujian2",
	}));
	set("chat_chance", 15);
	set("chat_msg",({
		"�����������һ�Ѽ�ë���ӣ������ص�ȥǽ�ϡ����ϵĳ�����\n",
		"���Ц���ʵ������͹������ʲô����\n",
	}));
	setup();
	carry_object("clone/cloth/male-cloth")->wear();
}
void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}	  
