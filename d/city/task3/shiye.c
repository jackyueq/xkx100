#include <ansi.h>
inherit NPC;

int ask_me();

void create()
{
	set_name("̷�Ѽ�", ( { "tan youji", "tan" }) );
	set("title", "���ݸ�ʦү");
	set("gender", "����" );
	set("age", 57);

	set("combat_exp", 30000);
	set_skill("unarmed", 50);
	set_skill("dodge", 60);
	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);
	set("shen_type", 0);

	set("inquiry", ([
		"�л���" : (: ask_me :),
		"���ݸ�":"ֻҪ����ٸ�(join guanfu)���Ϳ���Ϊ��͢������\n",
		"�ٸ�":"ֻҪ����ٸ�(join guanfu)���Ϳ���Ϊ��͢������\n",
		"����":"ֻҪ����ٸ�(join guanfu)���Ϳ���Ϊ��͢������\n",
		"����":"ֻҪ����ٸ�(join guanfu)���Ϳ���Ϊ��͢������\n",
		"����":"ֻҪ����ٸ�(join guanfu)���Ϳ���Ϊ��͢������\n",
		"task":"ֻҪ����ٸ�(join guanfu)���Ϳ���Ϊ��͢������\n",
		"quest":"ֻҪ����ٸ�(join guanfu)���Ϳ���Ϊ��͢������\n"
	]));
	set("chat_chance", 3);
	set("chat_msg", ({
		"̷ʦү���������뵱�ٵ���Խ��Խ���ˣ�\n",
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	object ob;
	mapping myfam;
	ob = this_player();
	::init();
	add_action("do_join", "join");
}

int do_join(string arg)
{
	object ob = this_player();
	if(!arg || arg!="guanfu") return notify_fail("̷�Ѽ͵�����Ҫ����ʲô��֯��\n");
	if(ob->query("officerlvl") > 0)
	{
		message_vision(HIC"̷�Ѽ�˵�������Ѿ������ݸ������ˡ�\n"NOR,ob);
		return 1;
	}
	if (ob->query("combat_exp")<20000)
	{
		message_vision(HIC "̷�ѼͶ�$Nҡͷ�������ʵս����̫�͡�\n" NOR,ob);
		return 1;
	}
	if (ob->query("class") != "bonze" &&
		ob->query("class") != "lama" &&
		ob->query("class") != "quanzhen" &&
		ob->query("class") != "eunach")
		ob->set("class","officer");
	ob->set("officerlvl",1);
	message_vision(HIY "̷�ѼͶ�$N����������������Ǹ�ʵϰ���죡\n" NOR,ob);
	ob->add("weiwang",10);
	message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,ob);
	tell_object(ob, "�����ڵĽ���������" + chinese_number((string)(ob->query("weiwang")))+"��\n"NOR);
	return 1;
}
string ask_me()
{
	if ((int)this_player()->query_temp("marks/��"))
	{
		say("��С�ӣ�����ô֪����ϲ���Խл�����\n");
		command("lick");
		say("��Ȼ���ҳ���ʳ�ѣ��Ҿ͸�����ɡ�����������\n");
		command("whisper " + this_player()->query("id") + " ��ȥ������ȫ�۵µ��ϰ壬ֻҪ���������ҽ���ȥ�ģ����ͻ�...");
		this_player()->delete_temp("marks/��");
		this_player()->set_temp("marks/��2", 1);
		return "������....��....�Ǹ������ܺ�....\n";
	}
	else if((int)this_player()->query_temp("marks/��2"))
		return "���Ǹ��㽭�ˣ�Ҳû������ô���£�\n";
	else
		return "����˿��ż������\n";
}
