// moda.c ��ɽ������ Ī��
// Last Modified by ahda on Sep.1 2001
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#define ZHENYUE "/clone/weapon/treasure/zhenyue"
mixed ask_jian();
#include <ansi.h>;
void create()
{
	object ob;
	set_name("Ī��", ({ "mo da", "mo" }) );
	set("nickname", "����ҹ��");
	set("gender", "����");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("per", 22);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);
	set("max_qi",2500);
	set("max_jing",1800);
	set("combat_exp", 3000000);
	set("shen_type", 1);

	set_skill("hand", 200);
	set_skill("unarmed",200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("strike", 200);
	set_skill("hengshan-sword", 300);
	set_skill("huiyan-xinfa",200);
	set_skill("luoyan-hand",300);
	set_skill("biluo-zhang",300);
	set_skill("qiuyan-nanhui",300);
	set_skill("literate",180);
	set_skill("luteplaying",180);

	map_skill("sword", "hengshan-sword");
	map_skill("parry", "hengshan-sword");
	map_skill("dodge", "qiuyan-nanhui");
	map_skill("force", "huiyan-xinfa");
	map_skill("hand", "luoyan-hand");
	map_skill("strike", "biluo-zhang");
	prepare_skill("hand", "luoyan-hand");
	prepare_skill("strike", "biluo-zhang");
  set("inquiry", ([
			"�����з�" : (: ask_jian :),
			"����" : (: ask_jian :),
			"ף�ڽ���" : "���Ž���֮һ��ף�ڽ�������ʦ��ɽһ�ۺ��ʧ���ˡ�",
			]));	 
	set("env/wimpy", 60);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: command("haha") :),
		(: perform_action, "sword.luoyan" :),
		(: perform_action, "sword.luoyan" :),
		(: perform_action, "sword.yunwu" :),
		(: perform_action, "hand.jinghan" :),
		(: perform_action, "strike.huan" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	create_family("��ɽ��", 13, "����");
	setup();
	set("count",1);
  if (clonep())
  {
     	ob=new(ZHENYUE);
     	if ( ob-> violate_unique())
     	{
     		destruct(ob);
     		ob=new(__DIR__"obj/qinjian");
    		}
     ob->move(this_object());
     ob->wield();
  }

//  carry_object(__DIR__"obj/qinjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say �������̫���ˣ����ʺ�ѧϰ�ҵĹ���");
		return;
	}
	if((int)ob->query_skill("literate",1) < 150)
	{
		command("say ��Ķ���д��̫���ˣ������ȶ����ϰ�ɡ�");
		return;
	}
/*
	if((int)ob->query("kar")<25)
	{
		command("say �����ɽ��ѧ��Ե����ذɡ�");
		return;
	}
*/
	if ((int)ob->query_skill("huiyan-xinfa",1) < 180 ) 
	{
		command("say ��ı����ڹ��ķ������,�������Ը�������书��");
		return;
	}
	if((string)ob->query("gender")=="����")
	{
		command("say ���������������ϰ�ҹ���ֽ��߻���ħ��");
		return;
	}
	if((int)ob->query("shen") <= 50000)
	{
		command("say ��Ӧ������Щ����������£��������ġ�");
		return;
	}

	command("say �����������������Һ�ɽһ�ɡ�");
	command("recruit " + ob->query("id"));
}

mixed ask_jian()
{
        object me;
        object ob;
        object owner;
        object *oblist;
        object temp;
        int i;

        me = this_player();
        if (me->query("shen")<0)
        {
                if (me->query("family/family_name") == "��ɽ��")
                        message_vision(CYN "$N" CYN "��ŭ����$n" CYN "����������Ϊ��ɽ���ӣ�"
                                       "��������ħ�������������ת����\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "��ŭ����$n" CYN "�ȵ�������һ��аħ��"
                                       "������Ȼ�ҿ��������з�����\n" NOR,
                                       this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "��ɽ��")
                return "�����з����һ���֮�������������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ����������з����㻹����ذɡ�";

        if (me->query("shen") < 60000)
                return "������������������ò������Ҳ��ܰ������з������㡣";
				if (present("zhenyue shangfang",me))
								return "�����з��������������ô����ô�����������أ�";

        ob=new(ZHENYUE);
        if ( temp=ob->violate_unique())
         {
         destruct(ob);
         ob=temp;
				 owner = environment(ob);
  			 if (owner == me)
	         	return "�����з��������������ô����ô�����������أ�";
        if ( owner->is_character() && owner!= this_object())
           {
                if (owner->query("family/family_name") == query("family/family_name"))
                        return "�����з�������" + owner->query("name") +
                               "���У���Ҫ���þ�ȥ�����ɡ�";
                else
                        return "�������������з���������" + owner->query("name") +
                               "���У����ȥɱ�����ѽ��û�����";
        	 }
         }
        	
				ob->move(this_object());
        message_vision(CYN "$N" CYN "���ͷ�������ã������������з�Ҫ����һЩ��"
		       "����������飡��\n" NOR, this_object(), me);
        command("give zhenyue shangfang to " + me->query("id"));
        add("count",-1);
        return 1;
}

