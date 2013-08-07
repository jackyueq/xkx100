// npc: /d/city/npc/lulixian.c

#include <ansi.h>
inherit NPC;

int ask_riddle();

void create()
{
	set_name("½����", ({ "lu lixian", "lu", "lixian" }) );
	set("gender", "Ů��" );
	set("title", MAG"�輧"NOR );
	set("nickname", YEL"�𶧴�ϵ��"NOR);
	set("age", 18);
	set("long", 
"���ߴ��ӣ����溬������ʱ�������������ȹ��ò�����ӣ�����С�����˲�ӯ�ա�\n");

	set("per", 28);
	set("int", 28);
	set("combat_exp", 5000);

	set("attitude", "peaceful");
	set("inquiry", ([
		"����" : (: ask_riddle :),
		"����" : (: ask_riddle :),
	]) );
	set("times", 100);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
	}) );
	carry_object(CLOTH_DIR+"cloth/qi-dress")->wear();
	carry_object(CLOTH_DIR+"shoes")->wear();
}

void init()
{
	::init();
	add_action("do_answer", "answer");
	add_action("do_enjoy",  "enjoy");
}

int ask_riddle()
{
	object me = this_player();

	if( me->query("trill_marks/guessing") )
	{
		write("½����Ц��Ц��˵�����Ȱ��ϸ��ղ³�����˵��\n");
		return 1;
	}
	else
	{
		switch( (int)me->query("trill_marks/guess") ) {
		case 0:
			message_vision("½������Ц�Ŷ�$N˵�����ǲ¸�����ɣ�\n", me);
			write("ң��ɽ�����紶 �򡶺�¥�Ρ�����һ\n");
			me->set("trill_marks/guessing", 1);
			break;
		case 1:
			message_vision("½������Ц�Ŷ�$N˵�����ǲ¸�����ɣ�\n", me);
			write("�ɶ������Ҳ��� �򡶺�¥�Ρ�ʫ��һ\n");
			me->set("trill_marks/guessing", 2);
			break;
		case 2:
			message_vision("½������Ц�Ŷ�$N˵�����ǲ¸�����ɣ�\n", me);
			write("�˽��������   ��ʫ����ʫ��һ\n");
			me->set("trill_marks/guessing", 3);
			break;
		default :
			command("sigh");
			message_vision("½���ɶ�$N˵�����ն�����¹��ˣ������Ƴ��µ���˵�ɣ�\n", me);
		return 1;
	}
	write("����˻ش� (answer) �ҡ���ס������й¶������յס�\n");
	message("vision", "½���ɶ���"+me->name()+"�ֹ��˼��仰��\n", environment(me), ({me}));
	return 1;
	}
}

int do_answer(string arg)
{
	object me;
	int soln,riddle;
	me = this_player();
	riddle = me->query("trill_marks/guessing");

	if (!riddle) {
		write("ʲô���������\n");
		return 1;
	}

	if( !arg || arg=="" ) {
		write("����յ��ٻش�\n");
		return 1;
	}
	message("vision", me->name() + "����յ�½���ɵĶ������ֹ�����\n", environment(me), ({me}) );

	switch (arg)
	{
	case "���": soln=1; break;
	case "�����" : soln=1; break;
	case "��ƾ��ˮ��ǧ" : soln=2; break;
	case "������Ҳ" : soln=3; break;
	default :
		say("½����������Ц��������˵�������ԣ����ԡ�\n"
		 + me->name() + "����৵ĺ���������\n");
	return 1;
	}

	if ( riddle == soln )
	{
		me->set("trill_marks/guess", riddle);
		message_vision("½�������Ķ�$N΢Ц�š�\n", me);
		me->set("score", me->query("score")+80);
		me->delete("trill_marks/guessing");
		write ("��Ľ������������ˣ�\n");
	}
	else
		write ("���ԣ����ԣ���Ϲ�¿ɲ��ã�\n");
	return 1;
}

int do_enjoy()
{
	object me;
	string msg, me_msg;
	int jin, e_jin, m_jin, bonus;

	if( query("times") < 0)
		return notify_fail("½����ƣ����Ц��Ц������������ˣ�����������ɡ���\n");
	add("times", -1);
	me = this_player();
	me_msg="��Ȼ";
	if ( objectp( present( "zizhu xiao",me) ) )
		me_msg = "$N�����֮������������������Ȼ��\n��Ȼ";
	msg = "½����Ц��һ�����콫��Ѽ���㣬Ȼ�������뱧���������ߣ��������У����ӵ�����\n"+me_msg+"���������������֦�����䣬��Ȼ����������������\n";
	message_vision(msg, me);
	jin = me->query( "jing" );
	e_jin = me->query( "eff_jing" );
	m_jin = me->query( "max_jing" );
	bonus = me->query_skill("literate",1) + me->query_per() - 60;
	if ( bonus < 0 ) bonus = 0;
	if ( bonus )
	{
		write("������һ���������������㡣\n");
		if ( jin < e_jin )
		{
			if ( ( jin + bonus ) > e_jin ) jin = e_jin;
			else jin += bonus;
		}
		me->set("jing", jin);
	}
	me->add("lu_sing", 1);
	return 1;
}

