// xu.c
#include <ansi.h>
inherit NPC;

int ask_gao();

void create()
{
	set_name("��ѩͤ", ( { "xu xueting", "xu" }) );
	set("nickname", HIR "��Ѫ����" NOR);
	set("gender", "����" );
	set("age", 55);
	set("long", "���Ǹ���ʮ����ĸ��ݺ��ӣ���һϮ���£�Ŀ�⾼������Ȼͦ��������ȥʮ�ָ�����\n");

	set("int", 30);
	set("str", 25);
	set("con", 23);
	set("dex", 22);
	
	set("qi",3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 150);
	set("combat_exp", 500000);
	set("score", 250000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("hand", 90);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taoism", 150);
	set_skill("literate", 60);
	set_skill("yixingbu", 80);
	set_skill("shenlong-bashi", 120);
	set_skill("taiji-jian", 120);
	set_skill("dulong-dafa", 100);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("parry", "shenlong-bashi");
	map_skill("sword", "taiji-jian");
	prepare_skill("hand", "shenlong-bashi");
	set("env/wimpy", 60);
	set("party/party_name", HIY"������"NOR);
	set("party/rank", HIR"������"NOR"����ʹ");
	set("party/level", 2);
	create_family("������", 2, "����");

	set("inquiry", ([
		"�ٻ����߸�" : (: ask_gao :),
		"�鰲ͨ" : "������������˵����",
		"�����" : "������ɸ������������룬�������Ŀ��磬�����ķ���",
		"����"   : "û��û�صġ�",
		"������" : "�����������ݵĶ������򣬴������ڳ����㵽��",
		"������" : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"���"   : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"����"   : "����Ƣ�����ã�Ҫ�������Ĳźá�\n",
		"�ں�"   : "���겻�ϣ������ɸ����������룡������ʥ��\n",
	]));
	set("chat_chance", 3);
	set("chat_msg", ({
		"��ѩͤ��Ȼһ���Դ���˵�����ˣ������ðٻ����߸࣡\n",
		"��ѩͤŭ��������ټ��һ�������̣�������һ�����������ˣ�\n",
		"��ѩͤ̾������˵����������ɱ�˺鰲ͨ��˭Ҳ��ˡ�\n",
	}) );
	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/shenlong/npc/obj/gcloth")->wear();
}

int ask_gao()
{
	say( "\n��ѩͤ��������˵������Ǳ��̽��ﰡ����һ����Ѫ������Ũ�㣬\n����ס�������ߵ��ϣ����˶��������ۻƾƣ��Աܶ��ߣ��������\nһ�����ۻƾƣ���ʹ�˽���������ܶ��������ˣ�����ôҲ֪����\n");
	return 1;
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");

	if ( (string)ob->query("name") != "���ߵ�" &&
		(string)ob->query("name") != HIG "���㻨" NOR )
		return notify_fail("��ѩͤҡͷ�������ɱ���˺鰲ͨ������ʲôҲû�ð�������\n");
	if ( (string)ob->query("name") == "���ߵ�" )
	{
		if(query_temp("baixianghua"))
		{
			message_vision("\n��ѩͤ���Ǹ��ߵ�����ϲ�������ߵ����㻨�����ˣ��ٻ����߸������ˣ�\n",who);
			obn=new("/d/shenlong/obj/baihua");
			obn->move(who);
			delete_temp("fushedan");
			delete_temp("baixianghua");
			return 1;		 
		} 		
		else	
		{	
			if(query_temp("fushedan"))
			{
				message_vision("\n��ѩͤ���Ǹ��ߵ�����$Nҡͷ�������ߵ������ˣ��Ͳ���㻨�ˡ�\n",who);
				return 0;
			}
			else
			{
				message("vision","��ѩͤ�������ߵ�����ϲ�������˸��ߵ���ֻ����㻨�ˡ�\n",environment(who));
				set_temp("fushedan",1);	
				return 1;
			}
		}
	}
	if ( (string)ob->query("name") == HIG "���㻨" NOR)
	{
		if(query_temp("fushedan"))
		{
			message_vision("\n��ѩͤ���ǰ��㻨����ϲ�������ߵ����㻨�����ˣ��ٻ����߸������ˣ�\n",who);
			obn=new("/d/shenlong/obj/baihua");
			obn->move(who);
			delete_temp("fushedan");
			delete_temp("baixianghua");
			return 1;		 
		} 		
		else	
		{	
			if(query_temp("baixianghua"))
			{
				message_vision("\n��ѩͤ���ǰ��㻨����$Nҡͷ�������㻨�����ˣ��Ͳ�ߵ��ˡ�\n",who);
				return 0;
			}
			else
			{
				message("vision","��ѩͤ�������㻨����ϲ�������˰��㻨��ֻ��ߵ��ˡ�\n",environment(who));
				set_temp("baixianghua",1);	
				return 1;
			}
		}	
	}
}

void attempt_apprentice(object ob)
{
	command("say �Ҳ���ͽ��");
	return;
}
