// /kungfu/class/gumu/limochou.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

int do_look(string var);
int ask_me();

void create()
{
	object ob;
	set_name("��Ī��", ({ "li mochou", "li", "mochou" }));
	set("long", "�����ü�Ϊ��ò���������Ŀ�����˲���������\n");
	set("nickname", "��������");
	set("gender", "Ů��");
	set("rank_info/respect", "����");
	set("age", 27);
	set("attitude","heroism");
	set("str", 30);
	set("dex", 35);
	set("per", 30);
	set("con", 17);
	set("int", 25);
	set("shen_type", -1);

	set_skill("unarmed", 90);
	set_skill("force", 80);
	set_skill("dodge", 100);
	set_skill("whip",130);
	set_skill("qiufeng-chenfa",180);
	set_skill("yunv-xinfa", 100);    //��Ů�ķ�	
	set_skill("throwing",130);
	set_skill("meinv-quan",100);
	map_skill("force", "yunv-xinfa");
	map_skill("whip","qiufeng-chenfa");
	map_skill("unarmed","meinv-quan");
	set("jiali",50);

	set("combat_exp", 95000);

	set("max_qi", 1500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);

	set("inquiry", ([
		"name" : "վԶ�㣡",
		"here" : "�Ҳ��Ǳ����ˣ���֪����",
		"��" : "����������������˼֮�ࡢ���֮�⣿",
		"½չԪ" : "�����Ǹ������С������ʲô��",
		"�����" : (: ask_me :),
		"С��Ů" : "�����ҵ�ʦ�á����������ʲô��",
		"�ֳ�Ӣ" : "�����ҵ�ʦ�棬�������ʵ�����ʣ�С���������㡣",
	]) );

         create_family("��Ĺ��", 3, "����");
 
	set("chat_chance", 10);
	set("chat_msg", ({
		"��Ī���������裬�������񣬸�����������䣬���Ǻ��ֱ������������\n",
		"��Ī�����������ϵر�˫�ɿͣ��ϳἸ�غ����\n",
		"��Ī�����������Ȥ�����࣬���и��гն�Ů����\n",
		"��Ī���������Ӧ�����������ƣ�ǧɽĺѩ��ֻӰ��˭ȥ����\n",
		"��Ī����Ɐ�У��������ǰ�Թ�������������·����į������ġ���������ƽ������\n",
		"��Ī���������л�Щ��ർ���ɽ��������ꡣ��\n",
		"��Ī���������Ҳ�ʣ�δ���룬ݺ�����Ӿ��������\n",
		"��Ī�������ǧ����ţ�Ϊ����ɧ�ˣ����ʹ�����������𴦡���\n",
	}) );

	setup();
	carry_object("/d/quanzhou/obj/fuchen")->wield();
	carry_object("/d/wudang/obj/greenrobe")->wear();
	ob=new(__DIR__"obj/yinzhen");
	ob->set_amount(10);
	ob->move(this_object());
}
void attempt_apprentice(object ob)
{
	if(ob->query("per") < 20)
	{
        	command("say ����ʵ�ڲ��ҹ�ά������ѧ������Ů�ķ���\n");
	}
	if ((string)ob->query("gender") != "Ů��")
	{     
	      message("vision", HIY "��Ī���ŭ���ȵ��������������Щ����ĳ����ˣ�ȥ���ɣ�\n��Ī�����ɱ��" + ob->name() +"\n" NOR, environment(), this_object() );
	      kill_ob(this_player());
	}		
	else
	{
	        command("say �ðɣ��Ҿ����������ͽ���ˡ�\n");
        	command("recruit " + ob->query("id"));
	}
}
void init()
{
	::init();
	add_action("do_look","look");
	add_action("do_look","hug");
	add_action("do_look","mo");
	add_action("do_look","18mo");
	add_action("do_look","kiss");

}

int ask_me()
{
	object me;
 
	me = this_player();
	message("vision", HIY"��Ī����Цһ���������������ȥ������\n��Ī�����ɱ��" + me->name() +"\n" NOR, environment(), this_object() );
	kill_ob(this_player());
	return 1;
}

int do_look(string target)
{
	object me;
 
	me = this_player();
	if (target=="li" || target=="li mochou" || target=="mochou" ) 
		if ((string)me->query("gender") != "Ů��")
		{
			message("vision", HIY "��Ī���ŭ���ȵ��������������Щ����ĳ����ˣ�ȥ���ɣ�\n��Ī�����ɱ��" + me->name() +"\n" NOR, environment(), this_object() );
			kill_ob(this_player());
		}
}

