// Npc: /d/lingxiao/npc/xuanyuan.c
// Last Modified by winder on Jul. 15 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��ԯ����", ({ "xuanyuan cangyi", "xuanyuan" }));
	set("title", "�������ϰ�");
	set("shen_type", 1);
	set("gender", "����" );
	set("age", 33);
	set("long", "��˵��ԯ������ŷұ�ӵĺ����Ϊ�˱��ⱻȨ��ǿ��������\n"
		"�����������ڴ˿��꣬��˵�ɽ�Īа���������ϡ�\n");
	set("combat_exp", 400000);
	set("inquiry", ([ 
		"�ɽ�Īа" : "����Ҫ�ɽ�Īа����ɵ��Ȱ��Ҹ�æ����ȥ�����õ�ѩɽ�ı����񾫰ɡ���\n", 
		"�ɽ�" : "���ɽ�������������а����ɱ��̫�࣬ԩ������ ����\n", 
		"Īа" : "��Īа������������а����ɱ��̫�࣬ԩ������ ����\n", 
	]));
	set("attitude", "friendly");
	set("vendor_goods",({
		WEAPON_DIR+"changjian",
		WEAPON_DIR+"gangdao",
		WEAPON_DIR+"hammer",
		WEAPON_DIR+"dagger",
		WEAPON_DIR+"qimeigun",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

int accept_object(object who, object obj, object ob1, object ob2)
{
	if ((string)obj->query("id") != "bingpo yujing")
	{
		command("say ��λ"+(string)who->query("name") +"������Ҫ����������");
		return 0;
	}
	command("say �������������ҵ���������");
	ob1=new(WEAPON_DIR"treasure/ganjiang-jian");
	ob2=new(WEAPON_DIR"treasure/moye-jian");
	ob1->move(who);
	ob2->move(who);
	command("say ��λ"+RANK_D->query_respect(who)+ "�����ҵ��˱����񾫣���Ҳ˵�������������ѽ������ȥ�ɡ�\n");
	message_vision("��ԯ����ҿ�һ���������ӣ�ವ�һ��������ѽ����ݸ�$N��\n",who);
	destruct(obj);
	return 0;
}

