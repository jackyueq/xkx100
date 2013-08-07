// yangguo.c ���
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("���", ({"yang guo", "yang", "guo"}));
	set("nickname", HIB"������"NOR);
	set("gender", "����");
	set("age", 26);
	set("long",
	"�����������������һ����񳿡������ף���ü���ޣ�����������\n"
	"��Ȼ��ֻ��һֻ�첲�����ǿ�ΰ����������˸о�Ӣ�����ˡ�\n");
	set("attitude", "friendly");

	set("per", 28);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);
	set("chat_chance", 1);
	set("chat_msg", ({
		"����૵�����������ܣ�������ܣ���һ�ܶ����ɵã���\n", 
	}));
	set("chat_chance_combat",50);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.anran" :),
		(: command("wield jian") :),
		(: command("unwield jian") :),
	}));

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 0);

	set_skill("force", 200);
	set_skill("yunv-xinfa", 200);
	set_skill("sword", 200);
	set_skill("yunv-jian", 200);
	set_skill("quanzhen-jian",200);
	set_skill("dodge", 200);
	set_skill("anran-zhang",220);
	set_skill("yunv-shenfa", 200);
	set_skill("parry", 200);
	set_skill("unarmed",200);
	set_skill("meinv-quan", 200);
	set_skill("literate",120);
	set_skill("qufeng",120);
	set_skill("tanzhi-shentong",200);
	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "anran-zhang");

	create_family("��Ĺ��", 4, "����");
	set("letter_count", 1);

	set("inquiry", ([
		"С��Ů"   :  "��Ҳ�����ҵ�������\n",
		"��Ů����" : "��Ů������ȫ�潣���ϱڣ������޵У�\n",
		"��Ĺ��"   : "�ҵ�����ʦүү������������ʦ��һ����ˣ�����..\n",
		"����"     : "�ҹ������ǵ���һ��������\n",
		"����"     : "�ҹ���ĸȷʵ�������Ųߡ�\n",
		"����"     : "���ּ�����ʦ���ิ���ѡ�\n",
		"���"     : "���ʵ��֣�\n",
		"������"   : "�������ڸ߲��ųǡ�\n",
		"���½�ڣ" : "���½�ڣ��Լ��Ұɡ�\n",
		"dan"      : (: ask_me :),
		"�ش���"   : (: ask_me :),
	]) );
	set("env/wimpy", 40);
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/kungfu/class/gumu/obj/junzijian");
}

string ask_me()
{
	object ob;
	string wan_num;
	int wannum;

	wan_num = read_file("/data/HUICHUN", 1, 1);
	wannum = atoi(wan_num);
	if (wannum == 0)
		return "��λ"+RANK_D->query_respect(this_player())+"���ش����辭һ�������������гɡ����ٵ�"RED+ chinese_number(12-(int)(uptime()/7200))+CYN"���������ɣ�\n";
	if (wannum == 2)
		return "��λ"+RANK_D->query_respect(this_player())+"���ش���������������ˡ����Ժ������ɣ�\n";
	ob = new("/clone/medicine/nostrum/huichundan");
	ob->move(this_player());
	write_file("/data/HUICHUN", "2", 1);
	command("rumor "+this_player()->query("name")+"�õ��ش���������\n");
	return "�ðɣ������㳢���ش�������Ҳ��֪������ζ���ɡ�";
}

