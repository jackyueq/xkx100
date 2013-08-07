// Last Modified by Winder on May. 15 2001
// axiang.c
inherit NPC;

int ask_letter();

void create()
{
	set_name("����", ({ "nongfu" , "a xiang", "a", "xiang" }) );
	set("nickname", "ũ��");
	set("gender", "����" );
	set("age", 44);
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("rank_info/respect", "ũ�񲮲�");
	set("inquiry", ([
		"name"   : "���а��飬�������������������������ˡ�",
		"rumors" : "�滳������ʱ�Ͱ���һ���Ĺ��ʱ��ѽ��",
		"here"   : "�����ǲܶ𽭣��㿴���ǿ鱮���𣿱���������Ƕ������߶��걮�ĺ�д�ģ���֪����ʲô��˼���������ѽ��",
		"��"     : "�����Ǳ�ѽ���㲻��û�����ɣ�",
		"��"     : "����д���ǰ˸������Լ���ȥ��",
		"����"   : "����д���ǰ˸������Լ���ȥ��",
		"����"   : "Сʱ��ĺû���ˣ����������������ȴ�����ڴ���",
		"����"   : "�ٺ٣�Ҫ������ʲô���Ѳ�����Ҳ���Ĺ��",
		"��Ĺ"   : "������ǰ�ɵĹ������������ֻ���Ҫ�ù���ѽ����ͨ������ʲô�Ŀɲ�˳�֣�",
		"����"   : "������û����������������ܻ��С�������˵���ڴ����˴�٣������ٸ�����ˡ������д����ȥ����Ҳ�����������������",
		"��"     : (: ask_letter :),
	]) );
	setup();
}

void init()
{
	add_action("do_answer", ({"answer", "huida", "da"}));
	::init();
}

int ask_letter()
{
	this_player()->set_temp("axiang_letter", 1);
	say( "ũ��˵������Ҫ��д��Ҳ�ɣ���������ȸ���(answer)�ұ������ǰ˸��ֵ���˼����\n");
	return 1;
}

int do_answer(string arg)
{
	object ob, me = this_player();
	int flag;

	if (!(flag = me->query_temp("axiang_letter"))) return 0;
	if (!arg) return notify_fail("��Ҫ�ش�ʲô��\n");
	if (arg == "����ô�")
	{
		write( "��˵�������ⲻ����������ˡ����ƾ����ɫ֮˿���ˡ������֣����׸����ߣ���ŮҲ���ˡ���֣��������Ů֮�ӣ��ˡ��á��֣���촾ʡ���������֮������Ϊ���ǡ��֡�������˼�ǡ�����ôǡ�����\n");
		tell_room(environment(), me->name() + "����ũ��٩٩��̸��\n", ({me}));
		if (flag == 2)
		{
			command("kick " + me->query("id"));
			message_vision("$N��������㲻��˵��һ��������ô�������£���\n", this_object());
		}
		else
		{
			message_vision("$Nһ�Ĵ��ȣ�������ôû���뵽ѽ����\n", this_object());
			write("����˵�����ðɣ��Ҿ�д���Ÿ���������\n");
			me->set_temp("axiang_letter", 2);
			ob = new(__DIR__"obj/axiang_xin");
			ob->move(me);
		}
	}
	else
	{
		message_vision("$N���������ף�������" + arg + "����˼���\n", me);
		command("laugh " + me->query("id"));
		message_vision("ũ���$N˵�������ұ���Ϊ�Լ����������û�Ļ��ģ����ڿ���ֻ���ŵڶ��ˡ���\n", me);
	}
	return 1;
}

