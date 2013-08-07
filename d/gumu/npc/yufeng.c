// yufeng.c ���

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW "���" NOR, ({"yufeng","feng","bee"}) );
	set("race", "����");
	set("subrace", "�ɳ�");
	set("age", 8);
	set("long","����һֻ��ɫ���۷䣬��ͷ����ͨ�۷��ö࣬\n����ϱ����ü�������֡�\n");

	set("no_train", 1);
	set("str", 40);
	set("dex", 50);

	set_temp("apply/attack", 35);
	set_temp("apply/armor", 25);

	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
"�������ͷ��ת��һȦ���ƺ������ⲻ�ǿɲ��۵ĵط����������˵ط����ˡ�\n",
"���Χ�����ʻ��ɷ�ͣͣ���ƺ�Ҳ�������ڲ����ϡ�\n",
	}) );

	setup();
}

void init()
{
	mapping fam;
	object ob;

	::init();
	if (interactive(ob = this_player()) &&
		(fam = ob->query("family")) && fam["family_name"] != "��Ĺ��")
	{
		message_vision(HIR"$N���Դ����Ĺ���ء�\n"NOR,ob);
		remove_call_out("killob");
		call_out("killob", 1, ob); 
	}
}

void die()
{
	message_vision("$N�͵���ᣬ�����ˡ�\n", this_object());
	destruct(this_object());
}
void killob(object ob)
{
	if (environment(ob)==environment())
	 kill_ob(ob);
}
