//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("��˪��",({ "ling shuanghua", "ling"}));
	set("gender", "Ů��" );
	set("nickname", HIY"�˵����"NOR);
	set("title",HIM"֪��ǧ��"NOR);
	set("age", 18);
	set("long", 
"һ��������׵���Ů���ڹ��;ջ�����һ���ۻ����ӣ��������˵���ա�\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("flower_count", 1);
	set("attitude", "friendly");
	set("chat_chance", 5);
	set("chat_msg", ({
		"��˪�������˺죬�����������Բ�����������֣�СѾͷ�����˵����\n",
	}) );
	set("inquiry", ([
		"�̾�"   : (: ask_me :),
		"�̾ջ�" : (: ask_me :),
		"����"   : "�������Ϊ���ܾ����衣��˵�գ���Ȧ����һ�졣\n",
                "�����" : "�������Ϊ���ܾ����衣��˵�գ���Ȧ����һ�졣\n",
	]));
	setup();
	carry_object("/d/jiangling/obj/nenhuangshan")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
}


string ask_me()
{
	object ob;
	
	if (query("flower_count") < 1)
		return "лл�������ң��һ�����������̾ջ��ġ�";
	add("flower_count", -1);
	ob = new("/d/jiangling/obj/greenflower1");
	ob->move(this_player());
	return NOR"�鷳�㣬����䡸"HIG"��������"NOR"��ת��������磬���ͻ����׵ġ�"NOR;
}
