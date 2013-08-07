// npc: /d/city/npc/gubancheng.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( YEL "�˰��" NOR, ({"gu bancheng","gu","bancheng"}) );
	set("gender", "����" );
	set("title", "�˼Ҳʲ����ϰ�");
	set("age", 51);
	set("long", @LONG
���ϰ��������Ǻ�𣬵�����ȫ���ˣ�������Ӧ����������ˡ�����
˵������������úã�����ǡ������ǵ��˶�������������ƥ��
�У����⻹�ܲ��ã������������ƺ����а����ָĳɡ�ȫ�ǡ��Ĵ��㡣
LONG
	);
	set("chat_chance", 40);
	set("chat_msg", ({
		"���ϰ�����͹٣��������Ϻõĺ���ɣ�\n",
		"���ϰ�������ݳ�����������ĵط�����û��ɶ�����򲻵��ġ�\n",
		"���ϰ�����Ǻǣ�С�϶���ҵ�Ҳ���ܺ��ڣ�����������Ϲ����\n",
		"���ϰ�����ţ������ĳ���ү�������ǰ������Ӱ���\n",
	}));
	set("inquiry", ([
		"�ʲ�" : "����Ҫ���У�����������������\n",
		"here" : "��������ݸ���������������ʹ����ܷ���ġ�\n",
	]) );
	set("attitude", "friendly");
	set("rank_info/respect", "�ϸ�");
	set("rank_info/rude","�����˵�");
	set("combat_exp",100);
	set_skill("unarmed", 5);
	setup();
	carry_object( "/clone/cloth/male-cloth")->wear();
}

void init()
{
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision("���ϰ�æ�Ÿ�����������һ��ͷ�������˽������к�һ���������Եȣ���\n",ob);
	return;
}
