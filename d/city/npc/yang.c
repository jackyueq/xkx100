// yang.c ���ϰ� 

inherit NPC;
inherit F_DEALER;
string ask_mask();

void create()
{
	set_name("������", ({ "Yang yongfu", "yang" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long",
		"���ϰ������������������ˣ����˼�ʮ���С������
��˵���������һ�����ȴ��֪��ʲô�ö�����\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("inquiry", ([
		"����" : (: ask_mask :),
		"����" : (: ask_mask :),
		"mask" : (: ask_mask :),
		"���" : (: ask_mask :),
	]));
	set("vendor_goods", ({
		"/clone/misc/chutou",
		"/clone/misc/fire",
		"/clone/misc/shihui",
		"/clone/misc/yanwu",
		WEAPON_DIR"muchui",
		WEAPON_DIR"club",
		FOOD_DIR+"sugar/xitang",
		__DIR__"obj/mabudai",
		__DIR__"obj/beixin",
		__DIR__"obj/toukui",
		__DIR__"obj/cycle",
		__DIR__"obj/surcoat",
		__DIR__"obj/shield",
		__DIR__"obj/huwan",
		__DIR__"obj/zhitao",
		__DIR__"obj/huyao",
		__DIR__"obj/caoxie",
		__DIR__"obj/pixue",
		__DIR__"obj/shoutao",
		__DIR__"obj/tieshou",
		__DIR__"obj/jinsijia",
		__DIR__"obj/hongbao", 
		__DIR__"obj/lan",
		__DIR__"obj/marrybox",
		__DIR__"obj/map",
	}));
	
	setup();
	set("count",1);
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
string ask_mask()
{
	object me, ob;
	
	me = this_player();
	ob = this_object();
	if (query("count")>0)
	{
		message("vision",ob->name()+"��"+me->name()+"�����ֹ��˼���ʲô��\n",me,({me}));
		tell_object(me,ob->name()+"���ĸ����㣺���������Ϲű���������������ƽ��ת�ø��㡣\n");
	}
	return "û��û�У���ʲô����֪������";
}
int accept_object(object who,object ob)
{
	object obj;
	
	if (!query("count") || !ob->query("money_id") || ob->value()<5000000)
	{
		message_vision("$N˵��������������ʲô��\n",this_object());
		return 0;
	}
	if (query("count")>0)
	{
		obj = new("/clone/misc/mask1");
		obj->move(this_player());
		add("count",-1);
		message_vision("$Nȡ��һ������������$n��\n",this_object(),who);
		tell_object(who,"�㼱æ�򿪰�������Ȼ��һ�����µ���Ƥ��ߡ�\n");
		return 1;
	}
}