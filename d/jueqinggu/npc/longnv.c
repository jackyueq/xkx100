// longnv.c С��Ů
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>;
inherit F_MASTER;
inherit NPC;
string ask_me();

void create()
{
	set_name("С��Ů", ({"long nv", "long"}));
	set("gender", "Ů��");
	set("age", 18);
	set("long",
	"ӯӯ��վ��һλ�������׵�Ů�ӣ�����������һ��Ѫɫ���Եò԰��쳣��\n"
	"����һϮ��ɴ��İ��£����������������\n"
	"��������������ѩ���������֮�������䣬\n"
	"ʵ��������������¡������ݡ�\n");
	set("attitude", "friendly");

	set("per", 30);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);

	set("chat_chance_combat", 9);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "sword.he" :),
	}) );

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 800000);
	set("score", 0);
	set_skill("force", 150);
	set_skill("yunv-xinfa", 150);    //��Ů�ķ�
	set_skill("sword", 150);
	set_skill("yunv-jian", 150);     //��Ů��
	set_skill("quanzhen-jian",140);  //ȫ�潣
	set_skill("dodge", 160);
	set_skill("yunv-shenfa", 160);   //��Ů��
	set_skill("parry", 150);
	set_skill("hubo", 120);	  //˫�ֻ���
	set_skill("unarmed",150);
	set_skill("meinv-quan", 160);    //��Ůȭ��
	set_skill("literate",120);
	set_skill("qufeng",200);	 //����֮��

	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");

	create_family("��Ĺ��", 3, "����");
	set("inquiry", ([
		"���"     :"������������ô��\n",
		"��Ů����" :"��Ů������ȫ�潣���ϱڣ������޵У�\n",
		"��Ĺ��"   :"�ҵ�����ʦүү������������ʦ��һ����ˣ�����...\n",
		"���յ�"   :(: ask_me :),
		"dan"      :(: ask_me :),
	]) );

	set("env/wimpy", 40);
	setup();
	carry_object("/kungfu/class/gumu/obj/shunvjian")->wield();
	carry_object("/kungfu/class/gumu/obj/baipao")->wear();
}

string ask_me()
{
	object ob;
	string wan_num;
	int wannum;

	wan_num = read_file("/data/YANGYAN", 1, 1);
	wannum = atoi(wan_num);
	if (wannum == 0)
		return "��λ"+RANK_D->query_respect(this_player())+"�����յ��Ǿ��Ұ���������ɵġ����ٵ�"GRN+chinese_number(6-(int)(uptime()/7200))+CYN"���������ɣ�\n";
	if (wannum == 2)
		return "��λ"+RANK_D->query_respect(this_player())+"�����յ�������������ˡ����Ժ������ɣ�\n";
	ob = new("/clone/medicine/nostrum/yangyandan");
	ob->move(this_player());
	write_file("/data/YANGYAN", "2", 1);
	command("rumor "+this_player()->query("name")+"�õ����յ�������\n");
	return "�ðɣ��������յ�������Ů�ľ������������ã������Ե������ȥ�ɡ�";
}

