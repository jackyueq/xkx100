// daiyisi.c
// Last Modified by winder on Oct. 30 2001

#include "ansi.h";
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
string ask_fan();
void create()
{
	set_name("���˿", ({"dai yisi", "dai", "yisi", }));
	set("long",
"���˿վ�ڴ�ǰ�����󺣣����������ȴ����ͷ��ֻ������Ӱ��
��㷢Ʈ������շ��������ٹ����ˣ��������ԡ�лѷ˵��
�����������е�һ���ˣ����Ե��治�飬ң��������ϣ���ˮ̶
�ߣ������绨������ʤѩ����֪�㵹�˶���Ӣ�ۺ��ܡ�\n");

	set("nickname", HIM "��������" NOR);
	set("gender", "Ů��");
	set("attitude", "peaceful");

	set("age", 33);
	set("shen_type", 1);
	set("per", 29);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);

	set("combat_exp", 900000);
	set("score", 800000);

	set_skill("force", 160);
	set_skill("dodge", 140);
	set_skill("throwing", 250);
	set_skill("parry", 140);
	set_skill("sword", 140);
	set_skill("cuff", 140);
	set_skill("hand", 140);
	set_skill("jiuyang-shengong", 160);
	set_skill("qingfu-shenfa", 140);
	set_skill("changquan", 140);
	set_skill("sanshou", 140);
	set_skill("liehuo-jian", 140);
	set_skill("duoming-jinhua", 250);
	set_skill("literate", 100);

	map_skill("force", "jiuyang-shengong");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	map_skill("dodge", "qingfu-shenfa");
	map_skill("throwing", "duoming-jinhua");
	map_skill("parry", "changquan");
	map_skill("sword", "liehuo-jian");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");

	set("inquiry", ([
		"лѷ"   : (: ask_fan :),
		"������" : (: ask_fan :),
		"����" : (: ask_fan :),
	]) );
	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform duo") :),
	}) );
	set("party/party_name",HIG"����"NOR);
	set("party/rank",HIW"���̷���"NOR);
	create_family("����", 34, "����");
	setup();
	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

string ask_fan()
{
	mapping fam;
	object *allob,env,ob,me=this_player();
	string *sname;
	int i, count, here = 0;

	if (!(fam = me->query("family")) || fam["family_name"] != "����")
		return RANK_D->query_respect(me) +
		"�뱾��������������֪�˻��Ӻ�̸��";

	add("fan",-1);
	ob = new("/d/binghuo/obj/fan");
	ob->move(me);
	message_vision("$N���һ�淫����\n",me);

	return "�ðɣ����ϼ��գ�����һ�鷫�������Լ�ȥ��л����ɡ�";

}
#include "fawang.h"
