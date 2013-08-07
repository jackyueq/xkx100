//NPC /d/baituo/npc/ouyangke.c
#include <ansi.h>
inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
void greeting(object ob);
int do_give(string arg);
void do_back();
void create()
{
	seteuid(getuid());
	set_name("ŷ����", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "��һ��Ʈ�ݵİ�ɫ��������ҡ���ȣ��������š�\n");
	set("title", "����ɽ��ׯ��");
	set("nickname", HIM "��������" NOR);
	set("gender", "����");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("env/wimpy", 60);
	set("no_get",1);

	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 10);

	set("combat_exp", 200000);
	set("score", 40000);

	set_skill("hand", 80);
	set_skill("dodge", 120);
	set_skill("parry", 90);
	set_skill("force", 90);
	set_skill("staff", 80);
	set_skill("training", 50);
	set_skill("cuff", 100);
	set_skill("hand",80);
	set_skill("strike",80);
	set_skill("literate", 100);
	set_skill("xidu-poison", 100);

	set_skill("hamagong",90);
	set_skill("chanchu-bufa", 180);
	set_skill("shexing-diaoshou", 120);
	set_skill("lingshe-zhangfa", 120);
	set_skill("hamaquan", 150);
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("cuff", "hamaquan");
	map_skill("strike", "hamagong");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
	prepare_skill("hand", "shexing-diaoshou");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "staff.shoot" :),
		(: perform_action, "staff.saoye" :),
		(: perform_action, "strike.hama" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );
	create_family("����ɽ��",2,"����");
	set("chat_chance", 10);
	set("chat_msg", ({
		"ŷ���˳���: Ư���������������������Ҷ࿴��һ�ۣ���\n",
		"ŷ����ɫ���Եؿ��Žֱߵ�С���\n",
		"ŷ���˰�ֽ��һչ��ת����ȥ�����������������֪�����ѵã�\n",
		(: random_move :)
	}) );

	setup();
	carry_object(__DIR__"obj/baipao")->wear();
	carry_object(__DIR__"obj/shexing")->wield();
	add_money("silver",10);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
  add_action("do_give","give");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
   if (ob->query("family/family_name")=="����ɽ��")
     {
                command("nod " + ob->query("id"));
                return;
      }
	if ((string)ob->query("gender")=="Ů��")
	{ 
		if (ob->query("per") < 20)
                        return;

    if (ob->query("sex/ŷ����"))
        {
           command("kiss " + ob->query("id"));
           command("say ��ô����Ҫ��Ҫ�������Σ�");
        } else
		switch(random(3))
		{
			case 0:command("rose "+(string)ob->query("id"));break;
			case 1:command("kiss "+(string)ob->query("id"));break;
			case 2:command("love "+(string)ob->query("id"));break;
		}
	}
	else say("ŷ����̾��һ����˵����λ"+RANK_D->query_respect(ob)+",��Ҫ���ܸ���Ūһ��Ů�����ͺ��ˡ�\n");
	return;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") == "����ɽ��")
	{
		if((int)ob->query("combat_exp")<10000)
			command("say ��ľ���̫�ͣ��һ��������㡣����Ŭ���ɡ�\n");
		else
		{
			command("say �������Ҫ�ú�ѧ��\n");		
			command("recruit "+ob->query("id"));
		}
		return;
	}
	if ((string)ob->query("gender") == "Ů��")
		message_vision("ŷ���˶����˵������λ" + RANK_D->query_respect(ob) + "�����ҵĺ���֪����\n�����ڻ��������㣬ֻ�������ϰ���ɽ��\n",ob);
	else
		message_vision("ŷ����ЦЦ˵����λ"+RANK_D->query_respect(ob) + "�������ڻ��������㣬ֻ�������ϰ���ɽ��\n",ob);
	write(HIY "ֻ��ŷ���˰�ֽ��������ǰһ�Σ�\n
	�������ǰһ����������ƮƮ�ط��˳�ȥ����\n" NOR);
	ob->move("/d/baituo/liangong");
}

int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "Ů��")
	{
		message_vision("ŷ���˰ڰ���˵������λ"+RANK_D->query_respect(ob)+ "���������۸�Ů�����أ�\n", ob);
		return 0;
	}
	if ((string)ob->query("family/family_name") == "����ɽ��")
	{
		if((int)ob->query("combat_exp")<100000)
			return notify_fail("ŷ����Ц������ľ���̫���ˣ���������ɡ���\n");
	}
	message_vision("ŷ����һ����˵������λ"+RANK_D->query_respect(ob)+ "����������ˡ�\n", ob);
	return 1;
}
 
//int accept_object(object who, object ob)
int do_give(string arg)
{
	object who=this_player();
	object obn;
	object ob;
	string item,target;
	int amount;
	if (!arg) return 0;
	if( sscanf(arg, "%s to %s", item, target)!=2 &&
		sscanf(arg, "%s %s", target, item)!=2 )
	return 0;
  if (!id(target)) return 0;
	ob=present(item,this_player());
	if ( !ob || !objectp(ob) || !ob->is_character()) return 0;
	if ( query_ip_name(this_player()) == query_ip_name(ob) )
	  return notify_fail("���Լ������������е��ˡ�\n");
	if (  (string)ob->query("gender") != "Ů��")
	{
		say("ŷ���˲���Ҫ���������\n");
		return 1;
	}
	if (ob->is_corpse())
	{
		command("slap " + who->query("id"));
		command("say �����㣬��Ȼ�þ�ʬ������Ū�ң��һ�������");
		return 1;
	}
	 if ((string)ob->query("family/family_name") == "����ɽ��")
   {
     command("kick " + who->query("id"));
     command("slap " + who->query("id"));
     command("say �ҿ����㵨�ӿ��治С�����ҵİ�����Ҳ���۸���");
                return 1;
    }

	if( environment(this_object())->query("short") == "����Ժ" )
	{
		say("ŷ����Ц��������ү�տ���꣬�����û����Լ����Űɡ�\n");
		return 1;
	}
	if ( (int)ob->query("age") <18 )
	{
		say("ŷ���˴�ʧɫ����δ������Ů������Ҫ��\n");
		return 1;
	}
	if ( (int)ob->query("age") >40 )
	{
		say("ŷ���������һЦ���������ϹŶ������������Լ��ɣ�\n");
		return 1;
	}
	if (ob->query("sex/ŷ����") >= 3)
    {
                command("shake");
                command("say ���������Ѿ������ˣ����Ը����Űɡ�");
                return 1;
    }       
  amount=0;
  if (userp(ob))
    {
      if (sizeof(ob->query("sex")) > 2 + 2 ) 
        {
           command("say ��������Ů���˾��ɷ���ŷ���˿ɲ���Ҫ��");
           return 1;
        }

        if (ob->query("per") < 25)
        {
           command("shrug");
           command("say �⡭�����ֻ�ɫҲδ����˵㣬��"
				"Ҳ�Ҹ�Ư��Щ�İ���");
                        return 1;
         }
         amount += ob->query("per");
          if (!ob->query("sex"))
                {
                        command("say �ۣ��⻹�Ǹ���Ů����ôҲ�ö��"
			        "�������ѣ�");
                        amount += 30;
                }
        command("rumor "+ob->query("name")+"�����͸�ŷ�����ˣ�����׬��"+chinese_number(amount+30)+"���׻��������ӡ�");
     }
     else
     {
        ob->set("chat_chance", 15);
        ob->set("chat_msg", ({CYN + ob->name() + CYN "��ס�ĳ�����\n" NOR,
                   CYN + ob->name() + CYN "���ʵ���" + this_object()->name() +
                   CYN "�����������������������\n" NOR,
                   CYN + ob->name() + CYN "�����������Ҳ�����ˣ�\n" NOR,
                }) );

     	}
  obn=new("/clone/money/silver");
	obn->set_amount(30+amount);
	obn->move(who);
	message_vision("ŷ����һ�Ѱ�"+ob->query("name")+ "���ڻ����$N˵����������������ѣ��ۻ�ͷ����\n˵�꣬��Я��"+ob->query("name")+"������Ժ��ȥ...\n",who);
	move("/d/city/lichunyuan",1);
  ob->move("/d/city/lichunyuan",1);
  message_vision("$N���Ż��Բ��ѵ�$n���˽�����\n", this_object(), ob);

  ob->add("sex/ŷ����", 1);
  ob->add("sex/times",  1);
  if (ob->query("sex/times") == 1)
        ob->set("sex/first", "ŷ����");
  ob->remove_call_out("revive");
  ob->revive();
  tell_object(ob, HIY "��ո������۾���ȴ����һ����"
		        "�������㣬����һ�����������˹�ȥ��\n\n" NOR);
        command("kiss " + ob->query("id"));
        command("say ���������ʲôô�����" + who->name() + "�����͹����İ���");
        remove_call_out("do_back");
        call_out("do_back", 30 + random(10));

	return 1;
}
void do_back()
{
        remove_call_out("do_back");
        if (base_name(environment()) == query("startroom"))
                return;

        if (! living(this_object()) ||
            is_busy() || is_fighting())
        {
                call_out("do_back", 10 + random(10));
                return;
        }

        message_vision(HIW "$N" HIW "��ҡ���ȣ�ƮȻ��ȥ��\n" NOR, this_object());
        move(query("startroom"));
        message_vision(HIW "$N" HIW "��ҡ���ȣ�ʩʩȻ�����˹�����\n" NOR, this_object());
}