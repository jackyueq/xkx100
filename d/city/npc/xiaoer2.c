// xiaoer2.c �Ƶ�С��

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		LIQUID_DIR+"jiudai",
		LIQUID_DIR+"wineskin",
		TEA_DIR+"fuchun",
		TEA_DIR+"longjing",
		TEA_DIR+"kuijian",
		FOOD_DIR+"kaoya",
		FOOD_DIR+"jitui",
		FOOD_DIR+"baozi",
		FOOD_DIR+"mian",
		FOOD_DIR+"tofu",
		FOOD_DIR+"gancai",
		FOOD_DIR+"jiaozi",
		FOOD_DIR+"jicai",
		FOOD_DIR+"jiudai",
		FOOD_DIR+"nuomi",
		FOOD_DIR+"sanding",
		FOOD_DIR+"shaomai",
		FOOD_DIR+"shengrou",
		FOOD_DIR+"shuijing",
		FOOD_DIR+"sunrou",
		FOOD_DIR+"xiaocai",
		FOOD_DIR+"xiehuang",
		FOOD_DIR+"xisha",
		FOOD_DIR+"yacai",
		FOOD_DIR+"yougao",
		FOOD_DIR+"zhima",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "ؤ��" 
		&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n��С�����һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/city/ganquanjie");
	message("vision","ֻ����ƹ����һ����" + ob->query("name") + "���˴�����¥��һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
