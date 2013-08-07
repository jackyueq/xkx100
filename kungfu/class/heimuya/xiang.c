// xiang.c
#include <ansi.h>
inherit NPC;
int ask_kill();

void create()
{
	set_name("������", ({ "xiang wentian", "xiang"}));
	set("nickname", HIR "��������" NOR );
	set("gender", "����");
	set("long", "������������̵Ĺ�����ʹ��Ϊ�˼�Ϊ��ˬ��ֻ������ò��񳣬�����������һ�Ի��׳��룬������ǰ��\n");
	set("age", 45);
	set("shen_type", 1);
	set("env/wimpy", 40);

	set("str", 21);
	set("per", 28);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("chat_chance", 1);
	set("inquiry", ([
		"����ͤ"     : "�����ˣ���ɱ��\n",
		"��������"   : "��λ��ͽ���ҷ�ɱ�������ɣ�\n",
		"ɱ��������" : (: ask_kill() :),
		"������"     : "��������������ʮ��......\n",
	]));
	set("count",1);
	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 350);

	set("combat_exp", 2500000);
	set("score", 0);

	set_skill("force", 200);            // �����ڹ�
	set_skill("finger", 200);           // ����ָ��
	set_skill("dodge", 200);            // ��������
	set_skill("parry", 200);            // �����м�
	set_skill("dagger", 200);           // �����̷�
	set_skill("sword", 200);            // ��������
        set_skill("shigu-bifa", 200);       // ʯ�Ĵ�Ѩ�ʷ�
	set_skill("piaoyibu", 200);         // Ʈ�ݲ���
	set_skill("wuyun-jian", 200);       // �������ҽ�
	set_skill("xuantian-zhi", 200);	    // ��������ָ
	set_skill("kuihua-xinfa", 200);	    // �����ķ�

	map_skill("force", "kuihua-xinfa");
	map_skill("sword", "wuyun-jian");
	map_skill("dagger", "shigu-bifa");
	map_skill("finger", "xuantian-zhi");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun-jian");

/*	set("inquiry", ([
		"�������" : "���������������̣��͵����Ĵ��ó��ϡ�",
		"���"     : "���������������̣��͵����Ĵ��ó��ϡ�",
	]));
*/
	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIR"�ڰ˴�������ʹ"NOR);
	create_family("��ľ��", 8, "����");

	setup();
	carry_object("/d/mingjiao/obj/baipao")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	command("say ��ĳ�������������յ��ӡ�\n");
	return;
}

int ask_kill()
{
	object ob,me = this_player();

	command("tell "+this_player()->query("id")+" ��Ҫȥɱ�������ܣ�");
	if (query("count")>0)
	{
		add("count",-1);
	  message_vision(HIC "�������$N���˵�ͷ˵��������һ��֮����\n" NOR,this_player());
	  ob=new("/d/heimuya/npc/obj/card4");
	  ob->move(me);
	  tell_object(me,"������ӻ�������һ����������������ϡ�\n");
	}
	return 1;
}
