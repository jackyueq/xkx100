// npc: /d/city/npc/shenwanfu.c
// Last Modified by Sir 9/15/2001
//�����̲�����

#include <ansi.h>
#include <command.h>

#define MAX_EXP 5000
#define MIN_EXP 1000
inherit NPC;
inherit F_DEALER;
int do_gongzuo();
void create()
{
	set_name( YEL "����" NOR, ({ "shen wanfu","shen","wanfu" }) );
	set("gender", "����" );
	set("title", "��Ұ������ϰ�");
	set("age", 45);
	set("long", "������һ�������ӣ���������Ц�Ǻǵģ���һ�����շ𡣿���������
�����Ǹ������ˣ�Ȼ���������ϸ��������˫�з��Ц�ۣ��ͻᷢ����
��ͬ��������һ˿����Ĺ�â����������Ұ����̵��ϰ塣\n");
	set("chat_chance", 50);
	set("chat_msg", ({
		"���򸣵�������������ݳ���������û������ô��\n",
		"���򸣵���������λ�͹٣������Ŀ����ǡ������������Ϸ��������ߡ����������Ķ����˰���\n",
		"���򸣵����͹٣�������£�����û��˵�����Ҳ���������õ�������һ���ɣ�����\n",
		"���򸣵����͹٣������ƣ�������������϶ྫ���ģ��˿��·��������˵�ǲ�����������\n",
	}));
	set("inquiry", ([
		"����" : "Ҫ����£�������������ҶԵط��ˣ�����û��\n",
		"here" : "�ţ�����ɲ��������ݳ��\n",
		"����" : (: do_gongzuo :),
		"job"  : (: do_gongzuo :),
		"work" : (: do_gongzuo :),
	]) );
	set("attitude", "friendly");
	set("vendor_goods", ({
		CLOTH_DIR+"cloth/baiduanshan",
		CLOTH_DIR+"cloth/baizhusipao",
		CLOTH_DIR+"cloth/commcloth",
		CLOTH_DIR+"cloth/hulannaao",
		CLOTH_DIR+"cloth/mabukuanshan",
		CLOTH_DIR+"cloth/shabuzhizhui",
		CLOTH_DIR+"cloth/zhifengkuanshan",
		CLOTH_DIR+"cloth/nenlvchoushan", 
		CLOTH_DIR+"cloth/danhuangshayi",
		CLOTH_DIR+"cloth/yinhongshanzi",
		CLOTH_DIR+"cloth/sahuaao",
	}) );

	set("attitude", "friendly");
	set("rank_info/respect", "�ϸ�");
	set("rank_info/rude","�����˵�");
	set("combat_exp",100);
	set_skill("unarmed", 5);
	setup();
	carry_object( "/clone/cloth/male-cloth")->wear();
}

int do_gongzuo()
{
	object me;	
	me = this_player(); 
	
	if (me->query("combat_exp")<MIN_EXP)
	{
		command("say ���ﶼ�Ǿ�ϸ������ڻ��ɲ��ˡ�\n");
		return 1;
	}
	
	if (me->query("combat_exp")>=MAX_EXP)
	{
		command("say ����С�²���������ݡ�\n");
		return 1;
	}
	if( me->query_temp("gongzuo/yunbu")>0)
	{
		tell_object(me,"��ȥ�Ѳ�ƥ�ٺú󽻸��Ұɡ�\n");
		return 1;
	}
	message_vision(CYN"���򸣶�$N˵���������ٺõĲ�ƥ�������ˣ���͵�����Ŀⷿ��ȥ��Щ������\n"NOR,me); 
	me->set_temp("gongzuo/yunbu", 1);
	return 1;
}
int accept_object(object me, object ob)
{
	object ob1;
	int add_exp,add_pot,add_score;
	if (strsrch(ob->query("name"), "�ٺõĲ�") < 0) 
	{
		command("say ������������������ٺõĲ���\n");
	}
	else if (me->query_temp("gongzuo/yunbu")<1)
	{
		command("say ��û�н�������ٲ�ѽ��\n");
	}
	else if (me->query_temp("gongzuo/yunbuok")<1)
	{
		command("say �ⲻ�����ٵĲ�ѽ��\n");
	}
	else
	{
		message_vision(CYN"���򸣶�$N˵���������ˣ�������Ĺ�Ǯ��\n"NOR,me);
		message_vision(CYN"���򸣵ݸ�$NһЩ���ӡ�\n"NOR,me);

		me->delete_temp("gongzuo/yunbu");
		me->delete_temp("gongzuo/yunbuok");

		add_exp=30+random(20);
		add_pot=15+random(10);
		add_score=10+random(5);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_score);
		ob1->move(me);	
		tell_object(me,HIW"��õ���:"
			+ chinese_number(add_exp) + "��ʵս���飬"
			+ chinese_number(add_pot) + "��Ǳ�ܣ�"
			+ chinese_number(add_score) + "�㽭��������\n"NOR);				
		call_out("destroying", 1, this_object(), ob);
		return 1;
	}
	return 0;
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
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
	message_vision("���ϰ�Ц�Ǻǵ�˵�������͹٣��������ۼҵİ�����ô������\n",ob);
	return;
}
