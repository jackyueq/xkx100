// jiading.c �Ҷ�

inherit NPC;
string ask_kid();

void create()
{
	set_name("�Ҷ�", ({ "jia ding", "jia" }));
	set("gender", "����");
	set("age", 35);

	set("combat_exp", 4000);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);
	set("shen_type", -1);

	set("chat_chance", 30);
	set("chat_msg", ({
		"�Ҷ�����ȥȥ��һ��ȥ������\n",
        "�š��Ҷ�������üͷ��һ���������˵����ӡ�\n",
        "�Ҷ��������ܲ��ܱ������ң�\n"
    }) );
    
	set( "inquiry", ([
		"�" : "�������㲻������ſ���\n",
		"С����ɽ��" : "�������\n",
		"����" : "���ݷ��������£�\n",
		"����ʯ" : (: ask_kid :)
	]) );
	setup();
	add_money("silver",3);
	carry_object("/clone/misc/cloth")->wear();
}

string ask_kid()
{
    if ( this_player()->query_temp( "kid_ask" ) )
    {
    }
    else
        return "�����Ҽ���ү��\n";
}
