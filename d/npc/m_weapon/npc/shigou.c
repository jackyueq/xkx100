// npc: shigou.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("�̹�", ({ "shigou"}) );
	set("nickname", HIB "��" NOR );
	set("gender", "����" );
	set("type","��");
	set("age", 20);
	set("no_get", 1);
	set("long", 	
		"��ͷ�ϰ��Űײ�ͷ��һϮ���ۣ�û��һ˿���塣\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	set("shen_type", 0);
	set("max_neli",500);
	set("jiali",50);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("parry",90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);
	set("combat_exp", 250000);
	set("score",0);
	set("attitude", "peaceful");
	set("inquiry", ([
		"����" : "ʦ�����Ұ���������������������Ҳ����һ����Ӱ��˭Ҫ�����أ�\n",
		"ԭ��" : "�������ú�˿���񣬺��׽�ĸ��ǧ����ľ��������ʯ����Ч������һ����\n",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}


int accept_object(object who, object ob)
{	
	if(!(who->query_temp("hook") ) )
	{
		message_vision(HIC"ʦ��û��ͬ��Ϊ������������ذɣ�\n"NOR, who);
		return 0;
	}
	who->delete_temp("hook");
	who->set_temp("m_make","��");
	switch ((string)ob->query("id") ) 
	{
		case "shen mu": 
			who->add_temp("shenmu",1);
			break;
		case "jin mu":
			who->add_temp("jinmu",1);
			break;
		case "han zhu": 
			who->add_temp("hanzhu",1);
			break;
		case "iron stone": 
			who->add_temp("ironstone",1);
			break;
		default :
			message("vision","����ʲô��ʦ��˵�ⲻ���������������\n",who);
			return 0;
	}
	message("vision", "�̹���ͷ������һ�����е�"+(string)ob->query("name")+"���˵�ͷ˵��\n", who);
	message("vision","���������������ھͿ�ʼ������\n", who);

	write("����λ"+RANK_D->query_respect(who)+"���������ְɣ�(zhu �������� Ӣ�Ĵ���)\n");
	return 1;
}
#include "shi.c"