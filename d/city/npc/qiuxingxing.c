// qiuxingxing.c

inherit NPC;
#include "kid.h"
void create()
{
	set_name("������",({ "qiu xingxing", "xiao hai","kid"}) );
	set("title", "ѧͯ");
	set("gender", "����" );
	set("age", 11);
	set("long", "���Ǹ�һ��������Ժ��ѧͯ�����ں�ͬ����ˣ��\n");
	set("combat_exp", 3);
    set("positive_score", 10);
	set("shen_type", 1);
	set("str", 10);
	set("cor", 16);
	set("cps", 20);
	set("per", 23);
	set("chat_chance", 3);
	set("chat_msg", ({
        "�����ǵ��������ϴ�ϲ�����˹��¶��ˣ���������������\n",
        "�����ǵ����벻���Ҹ�����һ�������أ�\n",
        "�����ǵ������ǵ���ʦ�Ǹ�������������\n"
    }));
    set("inquiry", ([
        "����" : (: ask_secret :),
        "secret" : "�Ҳ������ĵġ�\n",
    ]));
    set("papa_name", "���ʯ" );
	set("attitude", "peaceful");
	setup();
	carry_object(__DIR__"obj/xiaogua")->wear();

}
