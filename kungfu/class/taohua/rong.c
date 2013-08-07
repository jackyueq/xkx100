// /kungfu/class/taohua/rong.c ����

#include <ansi.h>
#include "game.h"

inherit NPC;
inherit F_MASTER;

string ask_chicken();
int ask_jiuyin();
int ask_game();

void create()
{
	set_name("����", ({"huang rong", "huang", "rong"}));
	set("gender", "Ů��");
	set("age", 18);
	set("long", "�����һ������Ķ���Ů�������ڵ����������������������Ů�������۰������������ѷ��ϲ���Ĵ����ܡ�\n");

	set("attitude", "peaceful");
	set("class", "scholar");
	set("per", 30);
	set("str", 18);
	set("int", 30);
	set("con", 21);
	set("dex", 26);

	set("qi", 1800);
	set("max_qi", 1800);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 0);
	
	set("combat_exp", 200000);
	set("score", 0);
	set("jiacount", 1);
	set("env/wimpy", 60);
	
	set_skill("force", 60);
	set_skill("bibo-shengong", 80);
	set_skill("unarmed", 80);
	set_skill("xuanfeng-leg", 80);	  // ����ɨҶ��
	set_skill("strike", 80);			// �����Ʒ�
	set_skill("luoying-zhang", 80);
	set_skill("dodge", 150);
	set_skill("anying-fuxiang", 100);
	set_skill("parry", 85);
	set_skill("literate",150);		   // ����ʶ��
	set_skill("sword", 80);
	set_skill("luoying-shenjian",80);
	
	map_skill("force"  , "bibo-shengong");
	map_skill("unarmed", "xuanfeng-leg");
	map_skill("strike" , "luoying-zhang");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("sword"  , "luoying-shenjian");
	
	create_family("�һ���", 2, "����");

	set("inquiry", ([
		"��ҩʦ" : "����ѽ, ����������? ",
		"����"   : "��ô? �����Ҿ�������Ϣ��? ",
		"���߹�" : "ʦ�������˼Ҿ�ϲ���Խл���! ",
		"�л���" : (: ask_chicken :),
		"�����澭����" : (: ask_jiuyin :),
		"��Ϸ"   : (: ask_game :),
	]) );

	setup();
	carry_object(__DIR__"obj/ruanwei")->wear();
	carry_object(__DIR__"obj/shudai")->wear();
}

init()
{
	object ob;
	mapping myfam;
		
	::init();
	add_action("do_kiss", "kiss");
	if (interactive(ob = this_player()) && !is_fighting())
	{
		myfam = (mapping)ob->query("family");
		if ((!myfam || myfam["family_name"] != "�һ���") &&
			(!wizardp(ob)))
		{
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
	}
}
int do_kiss ( string arg )
{
	object ob = this_player () ;
	if( !arg || arg!="rong" ) return 0;
   
	if ( (string) ob -> query ("gender") == "����" )
		command("say ���ˣ���������"+ob->query("name")+"Ҫ�����ң�\n");
	else
		message_vision("\n���ض�$NЦ�������ý�㲻Ҫ����������������\n", ob);
	return 1 ;
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	if ((string)ob->query("gender") == "����")
		message_vision("\n�������־���֮ɫ��������$Nһ�ۣ�˵����������ʲô�ˣ������Ҵ��ҵĹ뷿��\n�ٲ�����ȥ��������ô���㣡��\n", ob);
	else
		message_vision("\n���ؿ��˿�$N��˵�������þ�û���������ˣ���֪��λ�������Ҿ�������Ϣ��\n", ob);
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_temp("marks/�ض�")==1)
	{
		say( "����һ��Ц�⣺����л����������Ŀ��ţ���\n");
		if (query("jiacount")== 1)
		{
			say( "��������һЦ���Ҳ���ͽ��..��Ҳ�����������������⫼׾��͸���ɡ�\n");
			new("/kungfu/class/taohua/obj/ruanwei")->move(ob);
			tell_object(ob,"���ش���������һ����⫼׵ݸ��㡣\n");
			ob->set_temp("marks/�ض�",2);
			set("jiacount", 0);
		}
	}
	else
		command("say �������ôС����ͽ�ܣ�������Ц��������");
}

string ask_chicken()
{
	if (this_player()->query_temp("marks/��", 1))
		return "���������ô��ô������˵����ꤻ���\n";
	else
	{
		say("�ض�������˵���л������Ǻ��������ز����ҵ�������˺ô�ľ��Ÿ㵽������\n"
			"�����ط�������������ʲô��\n");
		this_player()->set_temp("marks/��", 1);
		return "����Գ�ȥ�ˡ�\n";
	}
}

int ask_jiuyin()
{
	object me = this_player();
	
	if(me->query("family/family_name")=="����ɽ��" && !me->query("reserve")
		&& me->query("family/master_id") == "ouyang feng" )
	{
		if(me->query("combat_exp")>500000 && present("mask_jiuyin",me))
		{
			destruct( present("mask_jiuyin", me) );
			message_vision(HIY "������������һ˿�������ɫ��������֪���澭�Ľ���ô���ðɣ���˵���������ǡ���\n", me);
			message_vision("˵�գ��ӹ�$N���еľ��飬��������������\n", me);
			message_vision("���������������Ƕ�ã�˹�����������ǡ����ù��࣬����ʮ����Ϣ������˼��\n", me);
			message_vision("�������Ļ�˼����������....����������������������ͨ����...��\n", me);
			message_vision(HIG "$N��Ϊ�˷ܣ�æ������������Ϣ���ڲ�֪�����а��ջ�������֮���Ĵ�����......\n", me);
			message_vision("$N�����ǽ����Ժ�����������ץ��������������ͷ��˼�����ֹ�״�����˲��⡣\n", me);
			message_vision("ͻȻ�䣬$N����žžž�����Լ��������⣬˫�ֳŵأ�������������ȫ�������������� \n"NOR, me);
			if (random(5) == 3)
			{
				tell_object(me,"���˰��Σ���ֻ����ȫ�������з�ʽ��Ϊ�쳣����һ������������ά����ά����ὣ� \n");
				tell_object(me,"���������������֮�ƣ����ɵ��־���ϲ��\n");
				me->set("reserve", 1);
				me->add("eff_jing", -100);
				me->add("max_neili", -2);
			} else {
				tell_object(me,"���˰��Σ�������һ�����飬��������ͷʹ���ѡ�һ��˻�����˹�ȥ...\n");
				me->add("eff_jing", -100);
				me->add("max_neili", -2);
				me->unconcious();
			}
			return 1;
		} else  return notify_fail("���ذ�����һ�ۣ����������΢ĩ���У���ѧ�����澭��Ҳ���±���Ц������ô����\n");
	} else return 0;
}

int ask_game()
{
	object me = this_player();
	object ob = this_object();

	if (me->query_temp("match_game/playing")) {
		write("���Ѿ�������Ϸ�ˡ�\n");
		return 1;
	}
/*	if (me->query_temp("match_game/lost")) {
		message_vision( "$n����ͷ��м�Ķ�$N˵������̫���ˣ��ҲŲ��������ء�\n", me, ob );
		return 1;
	}*/
	if (me->query_temp("match_game/win")) {
		message_vision( "$n���˵�ͷ�����ðɣ��ϴν�������Ӯ�ˣ�������û��ô�������ˡ�\n", me, ob );
		me->delete_temp("match_game/win");
	}
	else
		message_vision( "$nüͷһ���$N˵�����ð��������㵽���ж������\n", me, ob );
	return play_game(me,ob);
}
