// yangleishi.c

inherit NPC;

#include "kid.h"

void create()
{
	set_name("����ʯ",({ "yang leishi", "xiao hai", "kid"}) );
	set("title", "ѧͯ");
	set("gender", "����" );
	set("age", 12);
	set("long", "���Ǹ�һ��������Ժ��ѧͯ�����ں�ͬ����ˣ��\n");
	set("combat_exp", 4);
	set("chat_chance", 3);
	set("chat_msg", ({
		"����ʯ��������ϲ�����¶��ˣ�������һ��ҪȢ��Ϊ�ޡ�\n",
		"����ʯ�����벻���Ҹ�����һ�������أ�\n",
		"����ʯ���������е�ѧͯ�������ϴ󣡣���\n"
	}));
	set("inquiry", ([
		"����" : (: ask_secret :),
		"secret" : "�Ҳ������ĵġ�\n",
	]));
	set("str", 11);
	set("cor", 18);
	set("cps", 20);
	set("per", 24);
	set("papa_name", "������" );
	set("attitude", "peaceful");
	setup();
	carry_object(__DIR__"obj/xiaogua")->wear();
}

