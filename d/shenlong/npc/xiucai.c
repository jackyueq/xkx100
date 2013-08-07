// /d/shenlong/npc/xiucai.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit NPC;

int do_forge();

void create()
{
	set_name(HIY"������"NOR, ({ "xiucai" }));
	set("long","������ʱ���б����������Ա�������\nֻƾһ��ī�ž�����Щ͵�������Ĺ������ա�\n"); 
	set("gender", "����");
	set("age", 35);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	set("combat_exp", 2000);
	set("shen_type", -1);

	set("inquiry", ([
		"α��" : (: do_forge :),
		"weizao" : (: do_forge :),
		"forge" : (: do_forge :),
	]) );

	setup();
}
int do_forge()
{
	object me = this_player(); 

	if( !me->query_temp("cbs_���/a") ) return 0;
	me->delete_temp("cbs_���/a");
	command("hehe");
	command("whisper " + me->query("id") + " " + "һ���ƽ𣬲����ۡ�\n");
	me->set_temp("cbs_���/b", 1);
	return 1;
}
int accept_object(object who, object ob)
{
	object obj;

	if( ob->name() == "�׹���" )
	{
		command("ah " + who->query("id"));
		who->set_temp("cbs_���/a", 1);
		call_out("destroy", 1, ob);
		return 1;
	}
	if( ob->value() >= 10000 && who->query_temp("cbs_���/b") )
	{
		who->delete_temp("cbs_���");
		say("������Ц����˵��������̴ʱ�֤���ˡ�\n");

		obj = new("/d/shenlong/obj/songci");
		obj->move(who);
		message_vision("$N��һ" + obj->query("unit") + obj->query("name") + "����$n��\n", this_object(), who);
		return 1;
	}

	return 0;
}

void destroy(object ob)
{
	destruct(ob);
}
