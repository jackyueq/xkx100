//Npc : guyueer.c ���¶�

inherit NPC;

void create()
{
	set_name("���¶�",({ "gu yueer", "xiao hai", "kid"}) );
	set("title", "ѧͯ");
	set("gender", "Ů��" );
	set("age", 10);
	set("long", "���Ǹ�һ��������Ժ��ѧͯ�����ں�ͬ����ˣ��\n");
	set("combat_exp", 1);
	set("positive_score",10);
	set("str", 9);
	set("cor", 18);
	set("cps", 20);
	set("per", 26);
	set("chat_chance", 3);
	set("chat_msg", ({
        "���¶������Ǹ������������ˣ���ɫ���Զ���ң�����Ϊ�ܿᡣ\n",
        "���¶������治������ѧ�ˣ����ǵ����ϱ�������\n",
        "���¶��������ǵ���ʦ������ģ�������������\n"
    }));
    set("inquiry", ([
        "����" : "������ʲô�����أ�\n",
        "secret" : "�Ҳ������ĵġ�\n",
    ]));
	set("attitude", "peaceful");
	setup();
	carry_object(__DIR__"obj/huaao")->wear();
}
