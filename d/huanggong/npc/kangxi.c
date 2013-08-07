//kangxi.c �������

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

string * officer = ({
	"�ر�",
	"��˾",
	"�λ�",
	"�ν�",
	"����",
	"�ܱ�",
	"�ᶽ",
	"�ܶ�",
	"�󽫾�",
});
int ask_officer();
void dest(object ob);

void create()
{
	set_name(HIR "�������" NOR, ({"kang xi", "kang"}));
	set("title", "��ʥ��");
	set("gender", "����");
	set("age", 36);
	set("str", 25);
	set("dex", 20);
	set("int", 28);
	set("con", 28);
	set("per", 27);
	set("long", HIR @LONG
��λ�ߴ���࣬Ӣ�����������Ӿ������¶���Ŀ�����ۡ�
LONG NOR
	);

	set("combat_exp", 500000);
	set("score", 20000);
	set("shen_type", 1);
	set("attitude", "peaceful");


	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("literate", 100);
	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("finger", 100);
	set_skill("nianhua-zhi", 100);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "nianhua-zhi");
	map_skill("finger", "nianhua-zhi");
	prepare_skill("finger", "nianhua-zhi");

	set_temp("apply/attack", 50);
	set_temp("apply/defence", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 35);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 600);
	set("max_jing", 600);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 80);

	set("inquiry", ([
		"ΤС��" : "\nС�����ҵ��ĸ�,������Ϊ���ռ������Ա����Ϣ.\n",
		"����": "\n�������ǿ���Ԫ��,��̫����ϸ���,�����ҵ��ĸ���.\n",
		"��ְ" : (:ask_officer:),
		"ְ��" : (:ask_officer:),
		"����" : (:ask_officer:),
	]));
        set("chat_chance", 3);
        set("chat_msg", ({
    "�������Ҷ��Ͽ��˿���\n",
		"����˵��������֮�£�Ī������������֮����Ī��������\n",
		"����˵��������ȡʿ�����ͻ��¡��ҳ����ϵ����£��������������¡� \n",
		"����˵������Ҫ��ְ����Ȼ�����ˡ�\n",
		"����˵����������ʮ���¾��ߣ����������͡�\n",
        }) );
	setup();
	carry_object(__DIR__"obj/jinduan")->wear();
	add_money("gold", 5);
}
int ask_officer()
{
	int lv, worked;
	string officerlvl;
	object ob = this_player();
	lv = ob->query("officerlvl");
	worked = ob->query("bt/worked");
	if (lv < 1) 
	{
		command("say "+ob->query("name")+"����û�и�����֪����ּ�������˺θɣ���\n");
		return 1;
  }
  if (ob->query_temp("guard"))
   {
    command("say "+ob->query("name")+"�����Ѿ�������͹�ְ�ˣ�����ȥ�ɣ�");
    return 1;
   }
  officerlvl = officer[lv-1];
	command("chat "+ob->query("name")+"�������ּ�⣬�Ҿ��������������ű���ʵ��"+officerlvl+"ְ֮��\n");
	ob->set("guard",HIY+officerlvl+NOR);
	ob->set_temp("guard",1);
	return 1;
}

int accept_object(object me, object ob)
{
	object gold;
	object cloth;
	int exp,pot,score;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( ob->query("id") == "book1") 
	{
		me->set_temp("book14/1", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else if ( ob->query("id") == "book2") 
	{
		me->set_temp("book14/2", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else	if ( ob->query("id") == "book3") 
	{
		me->set_temp("book14/3", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	if ( ob->query("id") == "book4") 
	{
		me->set_temp("book14/4", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	if ( ob->query("id") == "book5") 
	{
		me->set_temp("book14/5", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	if ( ob->query("id") == "book6") 
	{
		me->set_temp("book14/6", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	if ( ob->query("id") == "book7") 
	{
		me->set_temp("book14/7", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	if ( ob->query("id") == "book8") 
	{
		me->set_temp("book14/8", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	{
		command("shake ");
		command("say ��ֻ��������ʮ���¾����������¡�");
	}
	if ( me->query_temp("book14/1") &&
	     me->query_temp("book14/2") &&
	     me->query_temp("book14/3") &&
	     me->query_temp("book14/4") &&
	     me->query_temp("book14/5") &&
	     me->query_temp("book14/6") &&
	     me->query_temp("book14/7") &&
	     me->query_temp("book14/8")) 
	{
		command("chat "+me->query("name")+"�����һذ˲���ʮ���¾����й�����𢣬�ͻ����һ����\n");
		cloth = new(__DIR__"obj/ycloth");
		me->delete_temp("book14");
		cloth -> move(me);
		gold = new("/clone/money/gold");
		gold->set_amount(20);
		gold->move(this_object());
		command("give 20 gold to "+me->query("id"));
		if (!me->query("skybook/luding/42jing"))
   {
		 me->set("skybook/luding/42jing",1);
		 exp=500+random(1000);
     pot=exp/2;
     score=pot/2;
     me->add("combat_exp",exp);
     me->add("potential",pot);
     	tell_object(me,HIC"��ɹ��õ��˿��������Σ�\n�����������������"+
     	         chinese_number(exp)+"�㾭�顢"+
               chinese_number(pot)+"��Ǳ���Լ�"+
               chinese_number(score)+"�㽭��������\n\n"NOR);
		}
		
	}
	return 1;
}

void dest(object ob)
{
	destruct(ob);
}