//Npc : lixiaoqi.c ��С��

inherit NPC;
#include "kid.h"

void create()
{
	set_name("��С��",({ "li xiaoqi", "xiao hai", "kid"}) );
	set("title", "ѧͯ");
	set("gender", "����" );
	set("age", 12);
	set("long", "���Ǹ�һ��������Ժ��ѧͯ�����ں�ͬ����ˣ��\n");
	set("combat_exp", 4);
     set("positive_score", 10);
	set("str", 11);
	set("con", 18);
	set("chat_chance", 3);
	set("chat_msg", ({
		"��С�����������ϴ��Ȼϲ�����˹��¶��ˣ���������ˣ�\n",
        "��С�������벻���Ҹ�����һ�������أ�\n",
        "��С���������ǵ���ʦ�Ǹ�������������\n"
    }));
    set("inquiry", ([
        "����" : (: ask_secret :),
        "secret" : "�Ҳ������ĵġ�\n",
    ]));
    set("papa_name", "��ǧҶ" );
	set("cps", 20);
	set("per", 24);
	set("attitude", "peaceful");
	setup();
	carry_object(__DIR__"obj/xiaogua")->wear();
}
